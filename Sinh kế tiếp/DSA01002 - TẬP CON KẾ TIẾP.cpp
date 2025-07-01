#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k,a[1001];
void sinh(){
    int i=k;
    while(a[i]==n-k+i and i>=1) i--;
    if(i==0){
        for (int j=i+1; j<=k; j++) a[j]=j;
        return;
    }
    a[i]++;
    for (int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        for (int i=1; i<=k; i++) cin>>a[i];
        sinh();
        for (int i=1; i<=k; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    
}