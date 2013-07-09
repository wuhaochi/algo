#include <string>
#include <functional>

#include <iostream>

using namespace std;


class A{
public:
    virtual void f()
    {
        cout << "A::f()" << endl;
    }
    
};


class B1 : public virtual A{
public:
    void f()
    {
        cout << "B1::f()" << endl;
    }
};


class B2 : public virtual A{
public:
    void f()
    {
        cout << "B2::f()" << endl;
    }
};


class C: public B1, public B2
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


int main()
{
    C c;
    
        // upcast
    A* pa = dynamic_cast<A*>(&c); // compile error if A is not virtual inheritance
    B1* pb1 = dynamic_cast<B1*>(pa);
    pb1->f();
    B2* pb2 = dynamic_cast<B2*>(pa);
    pb2->f();
    C* pc = dynamic_cast<C*>(pa);
    pc->f();
    
    A a;
        // downcast
    pa  = &a;
    
    pb1 = dynamic_cast<B1*>(pa);
    if(pb1) {
    pb1->f();
    }
    else{
        cout << "pb1 is null" << endl;
    }
    
    try{
        B1& rb1 = dynamic_cast<B1&>(a);
    }
    catch(const bad_cast& e)
    {
        cout << e.what() << endl;
    }
    
        // cross cast
    pa = &c;
    pb2 = dynamic_cast<B2*>(pa);
    pb1 = dynamic_cast<B1*>(pb2);
    pb1->f();
    return 0;
}
