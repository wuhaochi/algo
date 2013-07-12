#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

void insertion_sort(int* A, int L)
{
    for(int i = 1; i < L; ++i)
    {
        while (i > 0 && A[i] < A[i-1]) {
            swap(A[i], A[i-1]);
            --i;
        }
    }
}

void run_insertion_sort()
{
	int A[] = {1, 3, 5, 3, 5, 9, 2, 1};
    int L = sizeof(A)/sizeof(int);
	insertion_sort(A, L);
    copy(A, A+L, ostream_iterator<int>(cout, " "));
}

int main()
{
    run_insertion_sort();
    return 0;
    
}
