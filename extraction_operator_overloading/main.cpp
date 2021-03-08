#include <iostream>
using namespace std;

class Complex
{
private:
    uint32_t real;
    uint32_t img;
public:
    Complex();
    Complex(uint32_t real, uint32_t img);
    Complex(Complex &num);
    void setReal(uint32_t real);
    uint32_t getReal();
    void setImg(uint32_t img);
    uint32_t getImg();
    Complex add(Complex C);
    Complex operator+(Complex C);
    friend ostream& operator<<(ostream &o, Complex &C);
    friend istream& operator>>(istream &i, Complex &C);
    ~Complex();
};

Complex::Complex()
{
    cout<<"Complex: In default constructor"<<endl;
    setReal(1);
    setImg(1);
}
Complex::Complex(uint32_t real, uint32_t img)
{
    cout<<"Complex: In parameterized constructor"<<endl;
    setReal(real);
    setImg(img);
}
Complex::Complex(Complex &num)
{
    cout<<"Complex: In copy constructor"<<endl;
    setReal(num.real);
    setImg(num.img);
}
void Complex::setReal(uint32_t real)
{
    this->real = real;
}
uint32_t Complex::getReal()
{
    return this->real;
}
void Complex::setImg(uint32_t img)
{
    this->img = img;
}
uint32_t Complex::getImg()
{
    return this->img;
}
Complex Complex::add(Complex C)
{
    Complex temp;
    temp.real = this->real + C.real;
    temp.img = this->img + C.img;
    return temp;
}
Complex Complex::operator+(Complex C)
{
    Complex temp;
    temp.real = this->real + C.real;
    temp.img = this->img + C.img;
    return temp;
}
ostream& operator<<(ostream &o, Complex &C)
{
    o<<C.real<<"+"<<C.img<<"i"<<endl;
    return o;
}
istream& operator>>(istream &i, Complex &C)
{
    i>>C.real>>C.img;
    return i;
}
Complex::~Complex()
{
    cout<<"Complex: In destructor.."<<endl;
}
int main(void)
{
    Complex C1;
    cout<<"Enter real and imaginary parts of the complex number :"<<endl;
    cin >> C1;
    cout<<"Calling overloaded function to display the value.."<<endl;
    cout<<C1;

    return 0;
}
