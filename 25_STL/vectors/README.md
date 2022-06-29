# Vectors

Vectors are sequencial containers that are similar to arrays that can be resized as and when required. We may not specify the length in declaration and can modify it later. Vectors are in a way, the dynamic arrays with an ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container itself. In a Vector, elements are placed in logically contiguous memory so that those can be accessed and traversed using `iterators`. In a vector, data is inserted at the end.  

Reading [CPP Reference for standard header](https://en.cppreference.com/w/cpp/header/vector) would help.

With `using namespace std;`

A typical syntax is

    vector<dataType> <variableName> = { initalizingValues };
So,

    vector<int> v = { 2, 4 };

creates a `v` which is a `vector` of `int`s.
    
The iterator can be declared as:

    vector<dataType>::iterator variableName;  

So,

    vector<int>::iterator itr; 
    
creates a `itr` which is an `iterator`.

There are built-in methods provided by standard vector library --

#### Traversing/Iterating Methods:

 - `begin()`: `C++11` This returns an `iterator` pointing to the first element in the vector
 - `cbegin()`: `C++14` It returns a `const iterator` pointing to the first element in the vector
 - `rbegin()`: `C++14` It returns a reverse `iterator` pointing to the last element in the vector (reverse beginning), it moves from last to first element
 - `crbegin()`: `C++14` It returns a `const` reverse `iterator` pointing to the last element in the vector (reverse beginning), moves from last to first element
 - `end()`: `C++11` This returns an `iterator` pointing to the theoretical element that follows the last element in the vector
 - `rend()`: `C++14` It returns a reverse `iterator` pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
 - `cend()` : `C++14` It returns a `const iterator` pointing to the theoretical element that follows the last element in the vector
 - `crend()`: `C++14` It returns a `const` reverse `iterator` pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
 
#### Traversing the vector:
 
    for(itr=v.begin(); itr!=v.end(); itr++) {
        // Print value - one by one!
        cout << *itr << ' ';
    }
    
#### Traverse using for-each loop:
    
    for(int x:v) {
        // Print value - one by one!
        cout << x << ' ';
    }
    
#### Methods that deal with size of vectors:

 - `size()`: `C++17` It returns the number of elements in the vector
 - `max_size()`: It returns the maximum number of elements that the vector can hold
 - `capacity()`: It returns the size of the storage space currently allocated to the vector expressed as number of elements
 - `resize(n)`: It sesizes the container so that it contains `n` elements
 - `empty()`: `C++17` It returns whether the container is empty
 - `shrink_to_fit()`: `C++11` It reduces the capacity of the container to fit its size and destroys all elements beyond the capacity
 - `reserve()`: It requests that the vector capacity be at least enough to contain n elements    

Usage examples:

Reading size/depth of container and resizing it to increase it by 10 -

    size_t sz = v.size();
    sz += 10;
    v.resize(sz);

We can use `shrink_to_fit()` to free unused memory - 
    
    v.shrink_to_fit();
    
#### Methods for element access:

 - `at(n)`: It returns a reference to the element at position `n` in the vector
 - `front()`: It returns a reference to the first element in the vector
 - `back()`: It returns a reference to the last element in the vector
 - `data()`: `C++17` It returns a direct pointer to the memory array used internally by the vector to store its owned elements
 
Usage example:

We can use `at()` method to access a data member at index = 3

    int x = v.at(3)

Okay, no non-sense but We can use `[]` operator method to access a data member at a valid index

    int x = v[3];

We can use `front()` and `back()` methods to access a data member at first and last position respectively.

    int first = v.front();
    int last = v.back();

We can use `data()` method to get a pointer to the first element in the vector

    int *p = v.data();
    cout << "First index accessed using a compatible pointer is " << *p << endl;

#### Methods for modifications:

 - `assign()`: It assigns new value to the vector elements by replacing old ones
 - `push_back()`: Pushes the elements into a vector from the back
 - `pop_back()`: Used to pop or remove elements from a vector from the back
 - `insert()`: Inserts new elements before the element at the specified position
 - `erase()`: `C++20` It is used to remove elements from a container from the specified position or range.
 - `swap()`: It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
 - `clear()`: It is used to remove all the elements of the vector container
 - `emplace()`: `C++11` It extends the container by inserting new element at position
 - `emplace_back()`: `C++11` It is used to insert a new element into the vector container, the new element is added to the end of the vector
 - `swap()`: `C++11` swaps the contens of the two containers
 
Usage examples:

We can push values in vector using `push_back()` method -

    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);

We can use insert() to insert the value = 100 in the container -

    v.insert(v_it, 100);
    
We can use `emplace()` to construct a value = 88, in the container as a desired position, say 4 -

    v_it = v.begin();
    ++v_it;
    ++v_it;
    ++v_it;
    v.emplace(v_it, 88);
    
