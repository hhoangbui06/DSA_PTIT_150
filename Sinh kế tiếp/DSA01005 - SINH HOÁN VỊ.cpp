#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[10000]={},n,k;
void in(){
    for (int i=1; i<=n; i++) cout<<a[i];
    cout<<" ";
}
int visited[100]={0};
void sinh(int i){
    for (int j=1; j<=n; j++){
        if(visited[j]==0){
            a[i]=j;
            visited[j]=1;
            if(i==n) in();
            else sinh(i+1);
            visited[j]=0;
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        sinh(1);
        cout<<endl;
    }
}