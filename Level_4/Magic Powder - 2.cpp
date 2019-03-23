#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
long long n,k,A[N],B[N];

bool CanWeMakeIt(long long CakeCount){
    long long Magic = k;
    long long needed = 0;
    for(int i=0;i<n;i++)
    {
        needed = CakeCount*A[i];
        if(needed > B[i])
        {
            if(needed - B[i] <= Magic)
            {
                Magic-=(needed - B[i]);
            }
            else
            {
                return 0;
            }
        }
    }
  return 1;  
}