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
    friend Complex operator+(Complex c1, Complex c2);
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
Complex operator+(Complex c1, Complex c2)
{
    Complex temp;
    //temp.setReal(c1.getReal() + c2.getReal());
    //temp.setImg(c1.getImg() + c2.getImg());
    temp.real=c1.real+c2.real;
    temp.img=c1.img+c2.img;

    return temp;
}
Complex::~Complex()
{
    cout<<"Complex: In destructor.."<<endl;
}
int main(void)
{
    Complex C1;
    Complex C2(10, 50);
    Complex C3(C2);
    Complex C4;

    cout<<"C1.real = "<<C1.getReal()<<endl;
    cout<<"C1.img = "<<C1.getImg()<<endl;
    cout<<"C2.real = "<<C2.getReal()<<endl;
    cout<<"C2.img = "<<C2.getImg()<<endl;
    cout<<"C3.real = "<<C3.getReal()<<endl;
    cout<<"C3.img = "<<C3.getImg()<<endl;

    C1 = C2.add(C3);
    cout<<"C1=C2+C3: "<<C1.getReal()<<"+"<<C1.getImg()<<"i"<<endl;

    cout<<"Calling overloaded friend function.."<<endl;
    C4 = C2+C3;
    cout<<"C4=C2+C3: "<<C4.getReal()<<"+"<<C4.getImg()<<"i"<<endl;

    cout<<endl;

    return 0;
}
