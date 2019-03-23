//https://www.spoj.com/problems/CSUMQ/en/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int num[N];

int main()
{
    int n,Q;
    cin>>n;
    cin>>num[0];
    for(int i=1;i<n;i++){
        cin>>num[i];
        num[i] += num[i-1];
    }
    cin>>Q;
    int i,j;
    while(Q--){
        cin>>i>>j;
        if(i != 0){
        cout<<num[j]-num[i-1]<<endl;}
        else{
        cout<<num[j]<<endl;}
    }
    return 0;
}