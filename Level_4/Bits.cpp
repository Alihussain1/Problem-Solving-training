//https://codeforces.com/problemset/problem/484/A
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    unsigned long long x,y,z,tmpx;
    int T;
    cin>>T;
    unsigned long long shiftingIndx;
    while(T--){
    cin>>y>>x;
    if(y==x){cout<<x<<endl;  continue;}
    tmpx = y;
    shiftingIndx = 0;
    while(tmpx>=y&&tmpx<=x){
        tmpx |= (1ll<<shiftingIndx);
        shiftingIndx++;
    }
    shiftingIndx--;
    tmpx ^= (1ll<<shiftingIndx);
    cout<<tmpx<<endl;  
    }
    return 0;
}