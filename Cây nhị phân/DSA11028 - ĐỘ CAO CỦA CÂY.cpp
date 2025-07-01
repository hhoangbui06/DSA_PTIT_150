#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

ll bfs(vector<int>ds[], int n){
    queue<pair<int,int>>q;
    q.push({1, 0});
    int res=INT_MIN;
    while(q.size()){
        auto [canh, lv]=q.front(); q.pop();
        for (int x: ds[canh]){
            q.push({x,lv+1});
            res=max(res,lv+1);
        }
    }
    return res;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>ds[n+1];
        for (int i=0; i<n-1; i++){
            int u,v; cin>>u>>v;
            ds[u].push_back(v);
        }
        cout<<bfs(ds,n+1)<<endl;
    }
}