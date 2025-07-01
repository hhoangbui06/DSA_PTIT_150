#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k, a[1000];
vector<int>v;
vector<vector<int>>res;
void sinh(int sum, int pos){
    if(sum==k){
        res.push_back(v);
        return;
    }
    for (int i=pos; i<n; i++){
        if(sum+a[i]<=k){
            v.push_back(a[i]);
            sinh(sum+a[i], i+1);
            v.pop_back();
        }
    }
}
int main(){
    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    sinh(0,0);
    for (int i=res.size()-1; i>=0; i--){
        for (int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<res.size();
}