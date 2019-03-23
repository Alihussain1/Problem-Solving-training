//https://codeforces.com/contest/236/problem/B
#include <bits\stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+5;
int Arr[N];

inline GetAllDivisorsCount()
{
    for(int i=1;i<N;i++)
    {
            for(int j=i;j<N;j+=i)
            {
                Arr[j]++;
            }
    }
}

inline ll FixMod(ll a,ll b)
{
    return ((a%b)+b)%b;
}
inline ll Floor(ll a,ll b)
{
    return ((a-FixMod(a,b))/b);
}
inline ll GetDivisors(ll n)
{
    ll count = 0;
    ll i = 0;
    for(i = 1;i*i<n;i++)
        if(n%i == 0)
            count+=2;
    if(i*i == n)
        count++;
    return count;
}
inline Is_Prime(ll n)
{
    if(n<=1)return false;
    if(n<=3)return true;
    if(FixMod(n,2) == 0 || FixMod(n,3) == 0)return false;
    for(ll i =0;i*i<=n;i+=6)
    {
        if(FixMod(n,i) == 0) return false;
    }
    return true;
}

int main()
{
    int a,b,c;
    GetAllDivisorsCount();
    ll numberOfDiv = 0;
    cin>>a>>b>>c;
    for(ll i =1;i<=a;i++)
        for(ll j =1;j<=b;j++)
            for(ll k =1;k<=c;k++)
                numberOfDiv += FixMod(Arr[i*j*k],1073741824);
    cout<<numberOfDiv<<endl;
    return 0;
}