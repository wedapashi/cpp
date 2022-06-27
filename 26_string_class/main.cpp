#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    string str;
    cout << "Feed me with some text here: ";
    //cin >> str;
    getline(cin, str);

    cout << "You entered: "<< str << endl;

    cout << "str.length is " << str.length() << endl;
    cout << "str.size is " << str.size() << endl;
    cout << "str.capacity is " << str.capacity() << endl;
    cout << "str.max_size is " << str.max_size() << endl;
    cout << "Lets set the capacity to 100 using resize() method.." << endl;
    str.resize(100);
    cout << "str.capacity is " << str.capacity() << " and length is " << str.length() << endl;
    cout << "str.max_size is " << str.max_size() << endl;
    cout << "Lets append ""_type"" to the string using append() method.." << endl;
    str.append("_type");
    cout << "Lets see if append() operation has an impact on capacity." << endl;
    cout << "Str is: "<< str << endl;
    cout << "str.capacity is " << str.capacity() << " and length is " << str.length() << endl;
    cout << "Lets replace the first 3 characters to XYZ using replace() method.." << endl;
    str.replace(0, 2, "XYZ");
    cout << "Str is: "<< str << endl;
    cout << "Lets insert 3 characters FOX at 5th index using insert() method.." << endl;
    str.insert(5, "FOX");
    cout << "Str is: "<< str << endl;
    cout << "Lets insert first 2 characters from ROCK at 10th index using a different version of insert() method.." << endl;
    str.insert(7, "ROCK", 2);
    cout << "Str is: "<< str << endl;
    cout << "Lets erase the string using erase() method.." << endl;
    str.erase();
    cout << "Str is: "<< str << endl;
    cout << "str.capacity is " << str.capacity() << " and length is " << str.length() << endl;
    cout << "Lets push one char P at the back of the string using push_back() method.." << endl;
    str.push_back('P');
    cout << "Str is: "<< str << endl;
    cout << "str.capacity is " << str.capacity() << " and length is " << str.length() << endl;
    cout << "Lets truncate one char from the back of the string using pop_back() method.." << endl;
    str.pop_back();
    cout << "Str is: "<< str << endl;
    cout << "str.capacity is " << str.capacity() << " and length is " << str.length() << endl;

    return 0;
}
