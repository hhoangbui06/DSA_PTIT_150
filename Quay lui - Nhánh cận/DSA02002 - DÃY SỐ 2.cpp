#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int>a,tmp;
vector<vector<int>>v;

void sinh(){
    v.push_back(a);
    if(a.size()==1) return;
    tmp.clear();
    for (int i=0; i<a.size()-1; i++){
        tmp.push_back(a[i]+a[i+1]);
    }
    a=tmp;
    sinh();
}
int main(){
    int t; cin>>t;
    while(t--){
        a.clear(),tmp.clear(),v.clear();
        cin>>n;
        for (int i=0; i<n; i++){
            int x; cin>>x; a.push_back(x);
        }
        sinh();
        for (int i=v.size()-1; i>=0; i--){
            cout<<"[";
            for (int j=0; j<v[i].size()-1; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<v[i][v[i].size()-1]<<"]"<<" ";
        }
        cout<<endl;
    }
}