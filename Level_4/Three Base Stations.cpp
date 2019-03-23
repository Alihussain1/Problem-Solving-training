#include <bits/stdc++.h>

using namespace std;
const int N = 2e05+1;
double Loc[N],Xxxx[3],X[3];
long n ;
double EPS = 1e-7;
double EPS2 = 1e-5;

bool ok(double p){
  int startingHouse = 0;
  Xxxx[0]= Loc[0]+p;
  Xxxx[1] = 0;
  Xxxx[2] = 0;
  for(int i = 1 ; i < 3 ; i++){
    startingHouse = upper_bound(Loc, Loc+n, Loc[startingHouse]+(2*p))-Loc;
    if(i<3) Xxxx[i] = Loc[startingHouse]+p;
    if(startingHouse == n || (Xxxx[i] + p >= Loc[n-1]))  return 1;
  }
  return 0;
}


double binarySearch()
{
    double lo = 0.0,mid, hi=Loc[n-1];
    while(hi-lo>EPS){
        mid = (lo + hi)/2;
        if(ok(mid))
        {
            X[0]=Xxxx[0];
            X[2]=Xxxx[2];
            X[1]=Xxxx[1];
            hi = mid;
        }else
        {
            lo = mid;
        }
    }
    return hi;
}
int main()
{
    
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>Loc[i];
    }
    sort(Loc,Loc+n);
    
    cout << fixed;
    cout << setprecision(6);
    
    cout<<binarySearch()<<endl;
    cout<<X[0]<<" ";
    if(X[1] > 0)
        cout<<X[1]<<" "; 
    else 
        cout<<X[0]<<" ";
    if(X[2] > 0 )
        cout<<X[2]<<endl;
    else
        cout<<X[0]<<endl;
    return 0;
}