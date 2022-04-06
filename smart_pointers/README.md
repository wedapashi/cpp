# Smart pointers

It is introduced in C++11 version, specifically deals with ways to avoid memory leaks.  

A Smart Pointer is a wrapper class over a pointer with an operator like `*` and `->` overloaded. The objects of the smart pointer class look like normal pointers. But, unlike Normal Pointers it deallocates and frees the destroyed object memory. When the object is destroyed it frees the memory as well. So, we don’t need to delete it as Smart Pointer does will handle it.

The idea is to take a class with a pointer, destructor and overloaded operators like `*` and `->`. Since the destructor is automatically called when an object goes out of scope, the dynamically allocated memory would automatically be deleted.

It has 3 types:

- _unique_ptr:_ As the name suggests, at a time only one pointer can point to the object.   
- _shared_ptr:_ As the name suggests, at a time multiple pointers can point to a common object. It maintains a reference counter which indicates the number of pointers pointing to the common object.
- _weak_ptr:_ At a time multiple pointers can point to a common object, its just that, it doesn't maintain a reference counter as _shared_ptr_ does!

