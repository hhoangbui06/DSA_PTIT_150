#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int>v;
vector<vector<int>>res;
void sinh(int num, int sum){
    if(sum==n){
        res.push_back(v);
        return;
    }
    for (int i=num; i>=1; i--){
        if(sum+i<=n){
            v.push_back(i);
            sinh(i,sum+i);
            v.pop_back();
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        res.clear();
        sinh(n,0);
        for (int i=0; i<res.size(); i++){
            cout<<"(";
            for (int j=0; j<res[i].size(); j++){
                if(j!=res[i].size()-1) cout<<res[i][j]<<" ";
                else cout<<res[i][j];
            }
            cout<<")"<<" ";
        }
        cout<<endl;
    }
}