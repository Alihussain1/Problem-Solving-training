//https://www.spoj.com/problems/VECTAR8/
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
 
bitset<N> is_prime;
vector<ll> primes;
 
inline bool IsScaryPrime(ll n)
{
	string num = to_string(n);
	int x = 0;
	
	for (int i = x; i < num.length(); i++)
	{
		if (num[i] == '0')
			return false;
	}
	while (x < num.length()-1)
	{
		num[x] = '0';
		if (!is_prime[stoll(num)]) return false;
		x++;
	}
	return true;
}
 
void sieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	ll i = 0;
	
	for (i = 2; i*i <= N; i++)
	{
		if (is_prime[i] && IsScaryPrime(i))
			primes.push_back(i);
		for (ll j = i * i; j < N; j += i)
			is_prime[j] = 0;
	}
	for (i; i < N; i++)
		if (is_prime[i] && IsScaryPrime(i))
			primes.push_back(i);
}
 
 
int main()
{
	sieve();
	int T;
	cin >> T;
	int n;
	int indx = 0;
	while (T--)
	{
		cin >> n;
		indx = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
		cout << indx << endl;
	}
	return 0;
}