#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>


using namespace std;
typedef long long ll;
const int N = 1e6+6 ;
int CD[N];
int main()
{
	
	int n, p;
	int max = -1e5;
	int songsChoosed = 0;
	while (scanf("%d %d", &n, &p) != EOF)
	{
	    max = -1e5;
		for (int i = 0; i < p; i++)
			scanf("%d", CD + i);
		int sum = 0;
		for (int msk = 0; msk < (1<<p); msk++)
		{
			sum = 0;
			for (int i = 0; i < p; i++)
				if (msk&(1 << i))
					sum += CD[i];
			if (sum > max && sum <= n)
			{
				max = sum;
				songsChoosed = msk;
			}

		}
		for (int i = 0; i < p; i++)
			if (songsChoosed&(1 << i))
				printf("%d ", CD[i] );
		printf("sum:%d\n", max);
	}
	return 0;
}