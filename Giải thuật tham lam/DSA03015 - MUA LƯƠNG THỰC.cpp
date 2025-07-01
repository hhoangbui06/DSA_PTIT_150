#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

ll solve(int max, int day, int nd){
    if(nd>max) return -1;
    ll sum=nd*day;
    int real=day -day/7, check=day;
    ll tmp= max*real;
    if(tmp<sum) return -1;
    int cnt=0;
    while(sum>max){
        cnt++;
        sum-=max;
    }
    if(sum) cnt++; 
    return cnt;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int max,day,nd;
        cin>>max>>day>>nd;
        cout<<solve(max,day,nd)<<endl;
    }
}