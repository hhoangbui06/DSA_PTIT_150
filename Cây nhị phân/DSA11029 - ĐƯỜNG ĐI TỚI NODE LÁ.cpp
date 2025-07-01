#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

void bfs(vector<int>ds[],int n, int trace[]){
    bool vs[1001]={};
    queue<int>q;
    q.push(n);
    while(q.size()){
        int x=q.front(); q.pop();
        if(vs[x]==0){
            vs[x]=1;
            for (int it: ds[x]){
                if(vs[it]==0){
                    q.push(it);
                    trace[it]=x;
                }
            }
        }
    }
}
void find(int trace[], int x){
    stack<int>st;
    while(trace[x]){
        st.push(x);
        x=trace[x];
    }
    st.push(1);
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        bool node[1001]={};
        vector<int>ds[n+1];
        for (int i=0; i<n-1; i++){
            int u,v; cin>>u>>v;
            ds[u].push_back(v);
            node[u]=true;
        }
        int trace[1001]={};
        bfs(ds,1,trace);
        for (int i=1; i<=n; i++){
            if(node[i]==false){
                find(trace,i);
            }
        }
    }
}
