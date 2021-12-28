# Smart pointers

It is introduced in C++11 version, specifically deals with ways to avoid memory leaks.  

A Smart Pointer is a wrapper class over a pointer with an operator like `*` and `->` overloaded. The objects of the smart pointer class look like normal pointers. But, unlike Normal Pointers it deallocates and frees the destroyed object memory. When the object is destroyed it frees the memory as well. So, we don’t need to delete it as Smart Pointer does will handle it.

The idea is to take a class with a pointer, destructor and overloaded operators like `*` and `->`. Since the destructor is automatically called when an object goes out of scope, the dynamically allocated memory would automatically be deleted.

It has 3 types:

- unique_ptr  
- weak_ptr  
- shared_ptr  
