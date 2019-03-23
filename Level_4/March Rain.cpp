#include <bits/stdc++.h>
using namespace std;

const int N=1e5+1;
long long n,k,S[N];

bool CanWeCoverIt(long long length){
    int last_index_covered = -1;
    int used= 0;
    for(int i=0;i<n;i++){
        if(S[i] > last_index_covered){
            used++;
            if(used > k) return 0;
            last_index_covered = S[i]+length-1;
        }
    }
    return 1;  
}

long long binarySearch(){
    long long lo=0,mid,hi=1e9+1;
    while(lo<hi){
        mid = (lo+hi)/2;
        if(CanWeCoverIt(mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        cout<<binarySearch()<<endl;
    }
    return 0;
}