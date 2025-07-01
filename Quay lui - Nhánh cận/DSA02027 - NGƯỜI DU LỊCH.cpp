#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vs;
vector<vector<ll>>ds;
ll ans=INT_MAX,n;
void sinh(int x, ll res, int cnt){
    if(res>=ans) return;
    if(cnt==n){
        ans=min(ans,res+ds[x][1]);
        return;
    }
    for (int i=1; i<=n; i++){
        if(vs[i]==0 and ds[x][i]){
            vs[i]=1;
            sinh(i,res+ds[x][i], cnt+1);
            vs[i]=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
        cin>>n;
        ds.assign(n+1,{});
        vs.assign(n+1,0);
        vs[1]=1;
        for (int i=1; i<=n; i++){
            ds[i].push_back(0);
            for (int j=1; j<=n; j++){
                int x; cin>>x;
                ds[i].push_back(x);
            }
        }
        ans=INT_MAX;
        sinh(1,0,1);
        cout<<ans<<endl;
    
} 