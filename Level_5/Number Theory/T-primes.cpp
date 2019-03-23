//https://codeforces.com/contest/230/problem/B
#include <bits\stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+6;

int Arr[N];



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
    //vector<ll> div;
    ll count = 0;
    ll i = 0;
    for(i = 1;i*i<n;i++){
        if(n%i == 0)
        {
            count+=2;
        }
    }
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


bitset<N> is_prime;

map<ll, bool> tPrimes;
void sieve(){   //O(N*log(log(N))) ~= O(N)
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for(ll i = 2 ; i <= N ; ++i)
    if(is_prime[i]){
      tPrimes[i*i] = 1;
      for(ll j = i*i ; j < N ; j += i)
        is_prime[j] = 0;
    }
}

int main()
{
    sieve();
    int T;
    cin>>T;
    ll x;
    while(T--)
    {
        cin>>x;
        if(tPrimes[x])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
