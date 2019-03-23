#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
long long n=3,np,ns,nc,pp,ps,pc,k,A[3],B[3],C[3];

bool CanWeMakeIt(long long CakeCount){
    long long Magic = k;
    long long needed = 0;
    for(int i=0;i<n;i++)
    {
        needed = CakeCount*A[i];
        if(needed > B[i])
        {
            needed -= B[i];
            if(needed*C[i] <= Magic)
            {
                Magic-=(needed*C[i]);
            }
            else
            {
                return 0;
            }
        }
    }
  return 1;  
}

long long binarySearch(){
    long long lo=0,mid,hi=2e12+1;
    while(lo<hi){
        mid = (lo+hi+1)/2;
        if(CanWeMakeIt(mid)){
            lo = mid;
        }else{
            hi = mid -1;
        }
    }
    return lo;
}

int main()
{
    string recipe;
    getline(cin,recipe);
    cin>>np>>ns>>nc>>pp>>ps>>pc>>k;
    for(int i=0;i<recipe.length();i++)
    {
        if(recipe[i] == 'B') A[0]++;
        if(recipe[i] == 'S') A[1]++;
        if(recipe[i] == 'C') A[2]++;
    }
    B[0] = np;
    B[1] = ns;
    B[2] = nc;
    C[0] = pp;
    C[1] = ps;
    C[2] = pc;
    //cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<endl<<B[0]<<" "<<B[1]<<" "<<B[2]<<endl;
    //cout<<CanWeMakeIt(2)<<endl;
    cout<<binarySearch()<<endl;
    return 0;
}