# Friend functions and classes
Only member functions can access private, protected and public members.
If there is a glocal function which is not a member function of the class, then it can only access public members of the
class upon the object of the class.

If it is desired to access private members of A class, into a member function of B class with a 'has a'
relationship, upon an object of B class, then it is required to declare class B as a friend class in class A.

===
### Program's explanation

Class My and class Your shares a 'has a' relationship. We can access a and b which are private and protected members of the class My respectively by making class Your a friend class in Class My declaration (See code for details)..

Setting value of a and b which are private and protected members of the class Test respectively.
This is done by making function() a friend function in class Test.

===
### Program's Output:
a = 10, b = 20, c = 30
