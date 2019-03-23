//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1003
#include <bits/stdc++.h>
using namespace std;
typedef struct output{
    int count = 0,chr = 0;
};
output Freq_Arr[100];
bool cmp(output a, output b) {
   return (a.count<b.count || (a.count==b.count && a.chr>b.chr));
}
int main()
{
    string txt;
    bool flag = true;
    while(getline(cin,txt)){
        memset(Freq_Arr,0,sizeof(Freq_Arr));
    for(int i=0;i<txt.length();i++){
        Freq_Arr[txt[i]-31].count++;
        Freq_Arr[txt[i]-31].chr = (int)txt[i];
    }
    sort(Freq_Arr,Freq_Arr+100,cmp);
    if(!flag) cout<<"\n"; flag = false;
    for(int i=0;i<100;i++){
        if(Freq_Arr[i].chr != 0)
        printf("%d %d\n", Freq_Arr[i].chr, Freq_Arr[i].count);
    }
    
    }
    return 0;
}