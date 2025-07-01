#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int t; cin>>t;
    while(t--){
        int n,s; cin>>n>>s;
        int w[n], v[n];
        for (int i=0; i<n; i++) cin>>w[i];
        for (int i=0; i<n; i++) cin>>v[i];
        ll res[s+1]={};
        int dp[s+1]={1};
        ll ans=0;
        for (int i=0; i<n; i++){
            for (int j=s; j>=w[i]; j--){
                if(dp[j-w[i]]){
                    dp[j]=1;
                    res[j]=max(res[j], res[j-w[i]]+v[i]);
                    ans =max(ans,res[j]);
                }
            }
        }
        cout<<ans<<endl;
    }
}