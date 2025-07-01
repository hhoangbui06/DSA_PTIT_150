#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k,a[1001];
void sinh(){
    int i=n-1;
    while(i>=1 and a[i]>a[i+1]) i--;
    if(i==0) for (int j=i+1; j<=n; j++) a[j]=j;
    else{
        for (int j=n; j>i; j--){
            if(a[j]>a[i]){
                swap(a[j],a[i]);
                reverse(a+i+1,a+n);
                break;
            }
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        sinh();
        for (int i=1; i<=n; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    
}