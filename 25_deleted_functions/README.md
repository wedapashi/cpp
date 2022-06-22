# Deleted functions

There might be a use-case where we would want to prevent few things, such as using a copy constructor, or calling some functions with incompatible data types such as `uint64_t` instead of `uint32_t`.

This can be achieved using the `delete` keyword - with the feature of deleted functions provided by `C++11`.

    foo(const foo &) = delete;

prevents the copy constructor usage.


    void setBar(uint64_t Bar) = delete;
    void setBar(float Bar) = delete;

prevents calling `setBar()` method with `uint64_t` and `float` data type -- I know, in the this case probably looking at the warnings would helpto rectify the probable bug with data types but this approach is far more constructive and safe.

***
### Program output:

    g++ main.cpp -o a.out -g -Werror -Wall -Wno-unknown-pragmas -lpthread -lrt
    main.cpp: In function ‘int main()’:
    main.cpp:33:14: error: use of deleted function ‘foo::foo(const foo&)’
       33 |     foo f3(f2);
          |              ^
    main.cpp:15:5: note: declared here
       15 |     foo(const foo &) = delete;
          |     ^~~
    main.cpp:34:19: error: call of overloaded ‘setBar(int)’ is ambiguous
       34 |     f2.setBar(1234);
          |                   ^
    main.cpp:19:10: note: candidate: ‘void foo::setBar(uint32_t)’
       19 |     void setBar(uint32_t Bar) {
          |          ^~~~~~
    main.cpp:22:10: note: candidate: ‘void foo::setBar(uint64_t)’ <deleted>
       22 |     void setBar(uint64_t Bar) = delete;
          |          ^~~~~~
    main.cpp:23:10: note: candidate: ‘void foo::setBar(float)’ <deleted>
       23 |     void setBar(float Bar) = delete;
          |          ^~~~~~
    main.cpp:35:21: error: use of deleted function ‘void foo::setBar(float)’
       35 |     f2.setBar(12.34f);
          |                     ^
    main.cpp:23:10: note: declared here
       23 |     void setBar(float Bar) = delete;
          |          ^~~~~~
    main.cpp:36:21: error: use of deleted function ‘void foo::setBar(uint64_t)’
       36 |     f2.setBar(u64val);
          |                     ^
    main.cpp:22:10: note: declared here
       22 |     void setBar(uint64_t Bar) = delete;
          |          ^~~~~~
    main.cpp:33:9: error: unused variable ‘f3’ [-Werror=unused-variable]
       33 |     foo f3(f2);
          |         ^~
    cc1plus: all warnings being treated as errors
    make: *** [Makefile:17: all] Error 1

