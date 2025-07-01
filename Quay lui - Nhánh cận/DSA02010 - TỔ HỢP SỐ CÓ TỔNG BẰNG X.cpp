#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int>v,a;
vector<vector<int>>res;
int n,k;
void sinh(int sum, int pos){
    if(sum==k){
        res.push_back(v);
        return;
    }
    for (int i=pos; i<a.size(); i++){
        if(sum+a[i]<=k){
            v.push_back(a[i]);
            sinh(sum+a[i],i);
            v.pop_back();
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        set<int>se;
        v.clear(),a.clear(),res.clear();
        for (int i=0; i<n; i++){
            int x; cin>>x;
            se.insert(x);
        }
        a.assign(se.begin(),se.end());
        sinh(0,0);
        if(res.size()==0) cout<<-1;

        else for (int i=0; i<res.size(); i++){
            cout<<"[";
            for (int j=0; j<res[i].size()-1; j++){
                cout<<res[i][j]<<" ";
            }
            cout<<res[i][res[i].size()-1]<<"]";
        }
        cout<<endl;
    }
}