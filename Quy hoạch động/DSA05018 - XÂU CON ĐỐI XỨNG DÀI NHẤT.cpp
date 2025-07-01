#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int t; cin>>t;
    while(t--){
        scanf("\n");
        string s; cin>>s;
        int n=s.size();
        int dp[n+1][n+1]={};
        int ans=1;
        for (int i=1; i<=n; i++) dp[i][i]=1;
        for (int size=2; size<=n; size++){
            for (int i=0; i<n; i++){
                int j=i+size-1;
                if(j<n){
                    if(size==2 and s[i]==s[j]) dp[i][j]=1;
                    else if(size>2 and dp[i+1][j-1] and s[i]==s[j]) dp[i][j]=1;
                    if(dp[i][j]) ans=max(ans, j-i+1);
                }
            }
        } 
        cout<<ans<<endl;
    }
}