#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k, a[10000]={};
bool check(){
    int sum=0;
    for (int i=0; i<n; i++){
        sum+=a[i];
        if(sum>k) return false;
    }
    if(sum!=k) return false;
    return true;
}
void sinh(int i){
    for (int j=0; j<=1; j++){
        a[i]=j;
        if(i==n-1){
            if(check()){
                for (int i=0; i<n; i++) cout<<a[i];
                cout<<endl;
            }
        }
        else sinh(i+1);
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        sinh(0);
    }
}