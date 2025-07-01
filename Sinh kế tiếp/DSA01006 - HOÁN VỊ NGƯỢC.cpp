#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int>a;
vector<vector<int>>res;
int visited[100]={0};
void sinh(int i){
    for (int j=1; j<=n; j++){
        if(visited[j]==0){
            a[i]=j;
            visited[j]=1;
            if(i==n) res.push_back(a);
            else sinh(i+1);
            visited[j]=0;
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        a.clear();
        res.clear();
        a=vector<int>(n+1);
        sinh(1);
        reverse(res.begin(),res.end());
        for(auto x:res){
            for (auto k:x){
                if(k>=1 and k<=n)cout<<k;
            }
            cout<<" ";
        }
        cout<<endl;
    }
}