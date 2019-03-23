#include <bits/stdc++.h>
using namespace std;

const int N=1e5+1;
long long n,k,S[N];
string X,Y;
bool CanWeCoverIt(long long NumOfRepetation){
    int tmp=0;
    int count = 0;
    //cout<<"X = "<<X<<"  Y= "<<Y<<endl;
    for(int i=0;i<X.length();i++){
        count=0;
        //cout<<"X["<<i<<"] = "<<X[i]<<endl;
        while(tmp!=Y.length()){
            //cout<<"Y["<<tmp<<"] = "<<Y[tmp]<<endl;
            if(Y[tmp] == X[i]){
                count++;
                if(count == NumOfRepetation){ break;}
            }
            tmp++;
            //cout<<"count = "<<count<<endl;
        }
        if(count != NumOfRepetation){return 0;}
    }
    return 1;  
}

long long binarySearch(){
    long long lo=0,mid,hi=Y.length();
    while(lo<hi){
        mid = (lo+hi+1)/2;
        if(CanWeCoverIt(mid)){
            lo = mid;
        }else{
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    int T;
    
    cin>>T;
    while(T--){
        cin>>X;
        cin>>Y;
        //getline(cin,X);
        //getline(cin,Y);
        cout<<binarySearch()<<endl;
    }
    return 0;
}