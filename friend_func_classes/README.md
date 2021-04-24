Only member functions can access private, protected and public members.
If there is a glocal function which is not a member function of the class, then it can only access public members of the
class upon the object of the class.

If it is desired to access private members of A class, into a member function of B class with a 'has a'
relationship, upon an object of B class, then it is required to declare class B as a friend class in class A.

