//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1865
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

bitset<N> is_prime;
vector<ll> primes;

void sieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = 1;
	int i = 0;
	for (i = 2; i*i <= 2500; i++)
	{
		if (is_prime[i])
			for (ll j = i * i; j < N; j += i)
				is_prime[j] = 0;
	}
	
}


int main()
{
	sieve();
	string n;
	ll sum = 0;
	while (cin >> n)
	{
		if (cin.eof())
			break;
		sum = 0;
		for (int i = 0; i < n.length(); i++) {
			sum += n[i] < 'a' ? n[i] - 'A' + 27 : n[i] - 'a' + 1;
		}
		if (is_prime[sum]) 
			cout << "It is a prime word.\n";
		else
			cout << "It is not a prime word.\n";
	}
	return 0;
}