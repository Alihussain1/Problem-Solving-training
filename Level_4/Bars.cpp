#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>


using namespace std;
typedef long long ll;
const int N = 1e6+6 ;
int bars[N];
int main()
{
	int T;
	scanf("%d", &T);
	int n, p;
	while (T--)
	{
		scanf("%d %d",&n,&p);
		for (int i = 0; i < p; i++)
			scanf("%d", bars + i);
		int sum = 0;
		for (int msk = 0; msk < (1<<p); msk++)
		{
			sum = 0;
			for (int i = 0; i < p; i++)
				if (msk&(1 << i))
					sum += bars[i];
			if (sum == n)
				break;
		}
		if (sum == n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}