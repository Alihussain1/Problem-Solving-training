//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1480
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int N = 1e6+6 ;
int SPF[N];
bitset<N> is_prime;
vector<ll> primes;
vector<ll> almostprimes;
void sieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	
	ll i = 0;
	for (i = 2; i*i <= N; i++)
	{
		if (is_prime[i])
			primes.push_back(i);
		for (ll j = i * i; j < N; j += i)
			is_prime[j] = 0;			
	}
	for (i; i < N; i++)
		if (is_prime[i])
			primes.push_back(i);
}
int main()
{
	sieve();
	int T;
	cin >> T;
	ll low,high;
	ll count = 0;
	for (ll i = 0; i < primes.size(); i++)
	{
		for (ll j = primes[i] * primes[i]; j <= 1000000000001; j *= primes[i])
			almostprimes.push_back(j);
	}
	sort(almostprimes.begin(), almostprimes.end());
	ll start, end;
	while (T--)
	{
		cin >> low>>high;
		start = lower_bound(almostprimes.begin(), almostprimes.end(), low) - almostprimes.begin();
		end = upper_bound(almostprimes.begin(), almostprimes.end(), high) - almostprimes.begin();
		printf("%lld\n", end - start);
	}
	return 0;
}