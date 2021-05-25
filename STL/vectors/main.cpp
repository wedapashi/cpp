#include<iostream>
#include<stdint.h>
#include<vector>
using namespace std;

int main(void)
{
    vector<int> v = { 2, 4 };
    vector<int>::iterator itr;

    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);

    cout << "Printing values by iterator: ";
    for(itr=v.begin(); itr!=v.end(); itr++)
    {
        cout << *itr << ' ';
    }

    cout << endl;
    cout << "Printing values by for each loop: ";
    for(int x:v)
    {
        cout << x << ' ';
    }
 
    cout << endl;
    cout << "Lets see some other functions that are available with vectors: " << endl;

    cout << endl;

    // at();
    cout << "We can use at() method to access a data member at an index..";
    cout << "Value at 3rd index is " << v.at(3) << endl << endl;

    // [] operator
    cout << "Okay, no non-sense but We can use [] operator method to access a data member at an index..";
    cout << "Value at 3rd index accessed as v[3] is " << v[3] << endl << endl;
    
    // front() and back()
    cout << "We can use front() and back() methods to access a data member at first and last position..";
    cout << "Front is " << v.front() << " and back is " << v.back() << endl << endl;
    
    // data()
    cout << "We can use data() to pass the vector as a pointer..";
    int *p = v.data();
    cout << "First index accessed using a compatible pointer is " << *p << endl << endl; 

    // begin() and cbegin()
    cout << "We can use begin() to set the iterator to the front of the vector..";
    vector<int>::iterator v_it = v.begin();
    cout << "First value accessed using an iterator set using begin() is ";
    cout << *v_it << endl << endl;
    
    // end() and cend()
    cout << "We can use end() to set the iterator to the back of the vector..";
    v_it = v.end();
    cout << "Last value accessed using an iterator set using end() and then doing a iterator decrement is "; 
    v_it--;
    cout << *v_it << endl << endl;

    // insert()
    cout << "We can use insert() to insert the value in the container.. ";
    cout << "Lets set the iterator to the front, increment it twice to insert data (test value 55) into container at 3rd position..";
    v_it = v.begin();
    ++++v_it;
    v.insert(v_it, 55);
    cout << "Lets print values by for each loop: ";
    for(int x:v)
    {
        cout << x << ' ';
    }
    cout << endl << endl;
    
    // emplace()
    cout << "We can use emplace() to construct a value in the container as a desired position.. ";
    cout << "Lets set the iterator to the front, increment it thrice to insert data (test value 88) into container at 4th position..";
    v_it = v.begin();
    ++++++v_it;
    v.emplace(v_it, 88);
    cout << "Lets print values by for each loop: ";
    for(int x:v)
    {
        cout << x << ' ';
    }
    cout << endl << endl;

    // size() and resize();
    cout << "We can use size() method to check the size of the vector.. ";
    cout << "Size = " << v.size() << endl;
    cout << "We can use v.resize(v.size() + 4) to increase the size of vector by 4.." << endl;
    v.resize(v.size() + 4);
    cout << "New size is " << v.size() << endl << endl;    

    // shrink_to_fit();
    cout << "Using v.shrink_to_fit() to free unused memory.." << endl;
    v.shrink_to_fit();
    cout << "Size = " << v.size() << endl;
        
    cout << endl;
    return 0;
}
