# Shared Pointers

`std::shared_ptr` is a smart pointer that retains shared ownership of an object through a pointer. Several `shared_ptr` objects may own the same object. The object is destroyed and its memory deallocated when either of the following happens:

* The last remaining `shared_ptr` owning the object is destroyed;
* The last remaining `shared_ptr` owning the object is assigned another pointer via `operator=` or `reset()`.
* The object is destroyed using delete-expression or a custom deleter that is supplied to `shared_ptr` during construction.

A `shared_ptr` can share ownership of an object while storing a pointer to another object. This feature can be used to
point to member objects while owning the object they belong to. The stored pointer is the one accessed by `get()`, the dereference and the comparison operators. The managed pointer is the one passed to the deleter when use count reaches zero.

A `shared_ptr` may also own no objects, in which case it is called empty (an empty `shared_ptr` may have a non-null stored pointer if the aliasing constructor was used to create it).

## Program explanation:

`class keyValuePair` is self-explanatory, contains two strings: `key` and `value`. It has member function to set it, print it and read its size, etc, and yeah - a method to export it as an array! Bad code, indeed.

`class Buffer` is basically a wrapper around the a `unsigned char` array. You can consider this as a data container for sending some data such as device information and descriptors. It has a `append()` method which allows appending byte array to the data in existing buffer.

`class Module` is a class that instantiates a module capable of populating the data in key-value pair in ASCII format,
and is expected to put this data into a the buffer shared with different modules. It contains a `shared_ptr` to `Buffer`
type. It has a `unique_ptr` of `keyValuePair` type to hold an instance of key-value pair. It has `setKeyValuePair()`
that updates the key-value pair,  and a `getKeyValuePair()` method that retrieves it as required.
Importantly, `setBuffer()` and `getBuffer()` are facilitators that initialize the `m_Buffer` to the instance of `Buffer`, and returns the reference to `m_Buffer` respectively.
These are the key-value pairs we are playing with:

    const keyValuePair serialNum("SN", "123456");
    const keyValuePair modelNum("Model", "M4623-N");
    const keyValuePair vId("VID", "0x22C4");
    const keyValuePair pId("PID", "0x1000");

We need an instance of `Buffer` of course and we'll create it dynamically and set it up with a `shared_ptr`.

    std::shared_ptr<Buffer> buffer { new Buffer{} };

We need instances of `Module` and we'll create it dynamically and set it up with a `shared_ptr`.

    std::shared_ptr<Module> devInfo { new Module{} };
    std::shared_ptr<Module> descrInfo { new Module{} };

Now, we need to set the `shared_ptr` to `buffer` instace to work with it:

    devInfo.get()->setBuffer(buffer);
    descrInfo.get()->setBuffer(buffer);

We can put key-value pairs in the buffer:

    devInfo.get()->setKeyValuePair(serialNum);
    devInfo.get()->writeToBuffer();
    devInfo.get()->setKeyValuePair(modelNum);
    devInfo.get()->writeToBuffer();

    descrInfo.get()->setKeyValuePair(vId);
    descrInfo.get()->writeToBuffer();
    descrInfo.get()->setKeyValuePair(pId);
    descrInfo.get()->writeToBuffer();

And finally, print it all:

    buffer.get()->print();

***

### Program output:

    "SN" = "123456"
    "Model" = "M4623-N"
    "VID" = "0x22C4"
    "PID" = "0x1000"

