#include <string>
#include <functional>

#include <iostream>

using namespace std;

    // member function pointer

class C
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

int n = 0;
int main()
{
    typedef void (C::*C_mem)();
    
    C c;
    C_mem pmem = &C::f;
    
    ((&c)->*pmem)();
    
    (c.*pmem)();
    
	n ++;
    if( n < 3)
    {
    	typedef int (*pfunc)();
        pfunc ptr = main;
        cout << "run main: " << n << endl;
        ptr();
    }
    return 0;
}
