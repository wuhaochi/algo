//
//  main.cpp
//  subarrysum
//
//  Created by Ｈaochi Ｗu on 7/20/13.
//  Copyright (c) 2013 MyOrganizationName. All rights reserved.
//
//题目:输入一个整形数组,数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组,每个 子数组都有一个和。求所有子数组的和的最大值。要求时间复杂度为 O(n)。

#include <iostream>

using namespace std;

int sub(int* pA, int* pB)
{
    if( pB < pA)
        return 0x80000000;
    if(pB == pA)
    {
        return pA[0];
    }
    int* pM = pA + (pB-pA)/2;
    int L = sub(pA, pM);
    int R = sub(pM + 1, pB);
    int ML = 0x80000000;
    int m = 0;
	int* p = pM;
    while(p >= pA)
    {
        m += *p;
        ML = max(m ,ML);
        --p;
    }
	p = pM + 1;
    m = 0;
    int MR = 0x80000000;
    while (p<=pB) {
        m += *p;
        MR = max(m, MR);
        ++p;
    }
    int M = max(max(ML, MR), ML + MR);
    return max(max(L, R), M);
}


int runsub(int* A, int L)
{
    return sub(A, A+L-1);
}


int main(int argc, const char * argv[])
{
    cout << "subarray sum" << endl;
    for (int caseno = 0;; ++caseno)
    {
        int v;
        switch (caseno) {
            case 0:
            {
                int A[] = { 1, 3, 5, 7, 9};                
                int L = sizeof(A)/sizeof(int);
                 v = runsub(A, L);
            }
                break;
            case 1:
            {
                int A[] = { -2, 4, 6, 8, 10, 11};
                int L = sizeof(A)/sizeof(int);
                v = runsub(A, L);
            }
                break;
            case 2:
            {
                int A[] = { 2 , -0, 4, 6, -8, 10, -11};
                int L = sizeof(A)/sizeof(int);
             	v = runsub(A,L);
            }
                break;
                
            case 3:
            {
                int A[] = {2};
                int L = sizeof(A)/sizeof(int);
             	v = runsub(A,L);
                 break;
            }   
            case 4:
            {
                int A[] = {};
                int L = sizeof(A)/sizeof(int);
             	v = runsub(A,L);
                break;
            }
            case 5:
            {
                int A[] = {1, -2, 3, 10, -4, 7, 2, -5};
                int L = sizeof(A)/sizeof(int);
             	v = runsub(A,L);
                break;
            }
            case 6:
            {
                int A[] = {-91, -12, -13, -10, -4, -7, -12, -5};
                int L = sizeof(A)/sizeof(int);
             	v = runsub(A,L);
                break;
            }
            default:
                return 0;
        }
        cout << "case " << caseno << ": " << v << endl;
    }
    return 0;
}

