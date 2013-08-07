    //
    //  main.cpp
    //  test
    //
    //  Created by Ｈaochi Ｗu on 7/27/13.
    //  Copyright (c) 2013 Algorithm. All rights reserved.
    //

#include <iostream>

namespace whc {
    
    void _memcpy_no_overlap(void* dst, void* src, size_t len)
    {
        long* pdst = static_cast<long*>(dst);
        long* psrc = static_cast<long*>(src);
        for(int i = 0; i < len / sizeof(long); ++i)
        {
            *pdst ++= *psrc ++;
        }
        char* pcdst = reinterpret_cast<char*>(pdst);
        char* pcsrc = reinterpret_cast<char*>(psrc);
        for(int i = 0; i < len % sizeof(long); ++i)
        {
            *pcdst ++ = *pcsrc ++;
        }
    }
    
    void _memcpy_backward(void* dst, void* src, size_t len)
    {
        char* pdst = static_cast<char*>(dst) + len;
        char* psrc = static_cast<char*>(src) + len;
        
        long* longdst = reinterpret_cast<long*>(pdst);
        long* longsrc = reinterpret_cast<long*>(psrc);
        for(int i = len / sizeof(long); i > 0; --i)
        {
            *(--longdst) = *(--longsrc);
        }
        
        if( len % sizeof(long))
        {
            pdst = reinterpret_cast<char*>(longdst);
            psrc = reinterpret_cast<char*>(longsrc);
            for(int i = len % sizeof(long); i > 0; --i)
            {
                *(--pdst) = *(--psrc);
            }
        }
    }
    
    void _memcpy_forward(void* dst, void* src, size_t len)
    {
        long* pdst = static_cast<long*>(dst);
        long* psrc = static_cast<long*>(src);
        for(int i = 0; i < len / sizeof(long); ++i)
            *pdst ++ = *psrc ++;
        for (int i = 0; i < len % sizeof(long); ++i) {
            *(char*)pdst ++ = *(char*)psrc ++;
        }
    }
    
    void memcpy(void * dst, void* src, size_t len)
    {
        ptrdiff_t dist = reinterpret_cast<intptr_t>(dst) - reinterpret_cast<intptr_t>(src);
        if(labs(dist) >= len) // no overlap
        {
            _memcpy_no_overlap(dst, src, len);
            return;
        }
        if(dist > 0)// back from backward
        {
            _memcpy_backward(dst, src, len);
            return;
        }
        _memcpy_forward(dst, src, len);
        return ;
    }
    
    
}

using namespace std;

void test(char* src)
{
    
    int len = strlen(src) + 1;
    char* dst = new char[len];
    memset(dst, 0, len);
	cout << "len = " << len << endl;
    whc::memcpy(dst, src, len);
    cout << "src: " << src << endl;
    cout << "dst: " << dst << endl;
    cout << strcmp(src, dst)<< endl;
    delete [] dst;
}

template<typename T, int N>
void test(T (&src)[N])
{
    int L = sizeof(src)/sizeof(T);
    T* dst = new T[L];
    whc::memcpy(dst, src, L * sizeof(T));
    cout << "src: ";
    for(int i : src)
    {
        cout << i << ' ';
    }
    cout << "\ndst: ";
    for(int i = 0; i < L; ++i){
        cout << dst[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < L; ++i)
    {
        if(src[i] != dst[i])
        {
            cout << 1 << endl;
            return ;
        }
    }
    cout << 0 << endl;
    return ;
}

int main(int argc, const char * argv[])
{
    char* src = "hello1234567890ASDFGHJKLQWERTYUIOP";
    test(src);
    
    src = "1234567"; // size eq to sizeof(long)
    test(src);
    
    int pint[] = {1, 2, 3, 100, 5, 6, 7, 8};
    test(pint);
    
    int pint_2[] = {1, 2, 3, 100, 5, 6, 7, 8, 9};
    test(pint_2);
    
    char* overlap = new char [10];
    memcpy(overlap, "123456789A", 10);
    src = overlap;
    char* dst;
    dst = src + 1;
    whc::memcpy(dst, src, 9);
    cout << src << endl << dst << endl;
    
    return 0;
}

