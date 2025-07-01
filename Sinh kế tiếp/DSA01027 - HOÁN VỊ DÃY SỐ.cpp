#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,a[10], visited[10001]={};
vector<int>v;
void sinh(){
    for (int i=0; i<n; i++){
        if(visited[a[i]]==0){
            v.push_back(a[i]);
            visited[a[i]]=1;
            if(v.size()==n){
                for (int j=0; j<n; j++) cout<<v[j]<<" ";
                cout<<endl;
            }
            else sinh();
            visited[a[i]]=0;
            v.pop_back();
        }
    }
}

int main(){
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    sinh();
}