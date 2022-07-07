# Reinterpret cast

Typical expression:

    reinterpret_cast <new_type> (expression)

`reinterpret_cast` converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

It can also cast pointers to or from integer types. The format in which this integer value represents a pointer is platform-specific. The only guarantee is that a pointer cast to an integer type large enough to fully contain it, is granted to be able to be cast back to a valid pointer.

The conversions that can be performed by `reinterpret_cast` but not by `static_cast` are low-level operations, whose interpretation results in code which is generally system-specific, and thus non-portable. For example:

    class A {};
    class B {};
    A * a = new A;
    B * b = reinterpret_cast<B*>(a);

This is valid C++ code, although it does not make much sense, since now we have a pointer that points to an object of an incompatible class, and thus dereferencing it is unsafe.

***
### Program output:

    terminate called after throwing an instance of 'std::bad_alloc'
      what():  std::bad_alloc
    Aborted (core dumped)


