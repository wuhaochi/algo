#include <string>
#include <functional>

#include <iostream>


using namespace std;

class A{
public:
    A()
    {
    	cout << "A::A()" << endl;
    }
    
    virtual void f()
    {
        cout << "A::f()" <<endl;
    }
    
    virtual ~A()
    {
        cout << "A::~A()" << endl;
    }
};

class B1 : public  A
{
public:
    B1()
    {
    	cout << "B1::B1()" << endl;
    }
  
	virtual ~B1(){
    	cout << "B1::~B1()" << endl;
    }
    
    void f()
    {
        cout << "B1::f()" << endl;
    }
    
};

class B2 : public  virtual A
{
public:
    
    B2()
    {
    	cout << "B2::B2()" << endl;
    }
    virtual ~B2()
    {
        cout << "B2::~B2()" << endl;
    }
    
    void f()
    {
    	cout << "B2::f()" << endl;
    }
    
};


class C : public B2, public B1
{
public:
    C()
    {
        cout << "C::C()" << endl;
    }
    
    ~C()
    {
        cout << "C::~C()" << endl;
    }
    
    void f()
    {
        cout << "C::f()" << endl;
    }
};

int syntax()
{
    	// test multi inheritance function ambiguous.
    C c;
    
    return 0;
}
