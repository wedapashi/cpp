C++ has in its definition a way to represent sequence of characters as an object of class. This class is called std:: string. String class stores the characters as a sequence of bytes with a functionality of allowing access to single byte character.

Constructors:
	1. string ()
- creates an empty string ("")
	2. string ( other_string )
- creates a string identical to other_string
	3. string ( other_string, position, count )
- creates a string that contains count characters from other_string, starting at position. If count is missing (only the first two arguments are given), all the characters from other_string, starting at position and going to the end of other_string, are included in the new string.
	4. string ( count, character )
- create a string containing character repeated count times
