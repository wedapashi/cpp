# Move semantics

Assume there is an object of a class that has a pointer:

    class data {
        private:
            uint32_t *ptr;
        public:
            data(const uint32_t* p) {
                ptr = new uint32_t;
                *ptr = *p;
            }

            ~data() {
                delete(ptr);
                ptr = nullptr;
            }   
    };

We need to follow the rule of three, since we aren't using smart pointers, we'll manage the memory ourselves. I am going to defer writing the assignment operator and only implement the destructor and the copy constructor for now -- as seen above. And, an object `obj1` is created.

The copy constructor defines how to copy the contents of objects. The parameter `const uint32_t&` binds to all expressions of type `uint32_t` which allows you to make copies in the following examples:

    data obj1(px);
    data obj1(function()); // function() returns a uint32_t*

Note that only in the first line where we copy `px` is this deep copy really necessary, because we might want to inspect `px` later and would be very surprised if `px` had changed somehow. Did you notice how I just referred to `px` three times (four times if you include this sentence) and meant the exact same object every time? We call expressions such as `px` the l-values.
Whereas, the argument in next line is not a lvalue, it is a rvalue. Because, the underlying objects have no names, so there is no way to inspect it again at a later point in time. r-values denote temporary objects which are destroyed at the next semicolon (to be more precise: at the end of the full-expression that lexically contains the rvalue).

R-values allowa us to detect rvalue arguments via function overloading. All we have to do is write a constructor with an rvalue reference parameter. Inside that constructor we can do anything we want with the source, as long as we leave it in some valid state:

    data(data&& d) {
        ptr = d.ptr;
        d.ptr = nullptr;
    }

What have we done here is, Instead of deeply copying the heap data, we have just copied the pointer and then set the original pointer to null (to prevent `delete()` from source object's destructor from releasing our 'just stolen data'). In effect, we have "stolen" the data that originally belonged to the source object. Again, the key insight is that under no circumstance could be detected that the source had been modified. Since we don't really do a copy here, we call this constructor a "move constructor". Its job is to move resources from one object to another instead of copying them.

Let's continue by implementing the assignment operator:

    data& operator=(data p) {
        std::swap(data, p.data);
        return *p;
    }

So with `a = b`, the copy constructor will initialize `p` (because the expression `b` is an lvalue), and the assignment operator swaps the contents with a freshly created, deep copy. That is the very definition of the copy and swap idiom -- make a copy, swap the contents with the copy, and then get rid of the copy by leaving the scope. Nothing new here.

But with `a = x + y`, the move constructor will initialize `p` (because the expression `x + y` is an rvalue), so there is no deep copy involved, only an efficient move. That is still an independent object from the argument, but its construction was trivial, since the heap data didn't have to be copied, just moved. It wasn't necessary to copy it because `x + y` is an rvalue, and again, it is okay to move from string objects denoted by rvalues.

To summarize, the copy constructor makes a deep copy, because the source must remain untouched. The move constructor, on the other hand, can just copy the pointer and then set the pointer in the source to null. It is okay to "nullify" the source object in this manner, because the client has no way of inspecting the object again.

In copy semantics:

              obj1
             _____                                      ________
            |     |                             0x1000 |________|
            | ptr |---------------------------> 0x1004 |___55___|
            |_____|                             0x1008 |________|
    

              obj2
             _____                                      ________
            |     |                             0x1100 |________|
            | ptr |---------------------------> 0x1104 |___55___|
            |_____|                             0x1108 |________|
    
For this, we'll have to allocate new memory -- say starting at `0x1104`.

In move semantics: `obj1` is a temporary object, such that it is returned from the function as a value --

    Step I -- Instead of creating a separate object and copying the values, make the pointer to point to the same location.

              obj1
             _____                                      ________
            |     |                             0x1000 |________|
            | ptr |---------------------------> 0x1004 |___55___| <---.
            |_____|                             0x1008 |________|     |
                                                                      |
                                                                      |
              obj2                                                    |
             _____                                                    |
            |     |                                                   |
            | ptr |---------------------------------------------------'
            |_____|                   
    
Now this is like a shallow copy, if `obj1` object's destructor is called, the data is lost!

    Step II -- Detach ptr in obj1 ans set it to nullptr.


                                                        ________
                                         .----> 0x0000 |        |
                                         |             |        |
                                         |                 .
                                         |                 .
                                         |                 .
              obj1                       |                 .        
             _____                       |             |________|
            |     |                      |      0x1000 |________|
            | ptr |----------------------'      0x1004 |___55___| <---.
            |_____|                             0x1008 |________|     |
                                                                      |
                                                                      |
              obj2                                                    |
             _____                                                    |
            |     |                                                   |
            | ptr |---------------------------------------------------'
            |_____|                   
    
This will result calling `delete()` on a `nullptr` from the destructor of `obj1`. 
