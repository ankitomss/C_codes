#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculateFibo(int n,  unsigned int *T) {
    if (n < 2)
        return 0;
    
    T[n] = T[n-1]*T[n-1] + T[n-2];
    return T[n];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int A, B, N;
    cin>> A;
    cin >> B;
    cin >> N;
    
    unsigned int *T = new unsigned int(N);
    cout << sizeof(long long);
    cout << "size of long" << sizeof(long); 
    T[0]=A;
    T[1]=B;
    
    for(int i=2; i < N; i++)
    {
	    cout << calculateFibo(i, T)<<"\n";
	    
    }
    
    cout << T[N-1];
    return 0;
}
