#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

struct node{
    int x;
    node *left, *right;
    node (int val){
        x=val;
        left=right=NULL;
    }
};
node *insert(node *root, int val){
    if(root==nullptr) root=new node(val);
    if(val<root->x) root->left=insert(root->left,val);
    if(val>root->x) root->right=insert(root->right,val);
    return root;
}
void solve(node *root, int &cnt){
    if(root==nullptr) return;
    if(root->left or root->right) cnt++;
    solve(root->left,cnt);
    solve(root->right,cnt);
}
bool check(vector<int>v, set<int>se){
    if(v.size()!= se.size()) return false;
    int cnt=0;
    auto it=se.begin();
    while(cnt<v.size() and it!=se.end()){
        if(v[cnt]!=*it) return false;
        cnt++;
        it++;
    }
    return true;
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>v;
        for (int i=0; i<n; i++){
            int x; cin>>x;
            v.push_back(x);
        }
        node *root=nullptr;
        for (int x:v) root=insert(root,x);
        int res=0;
        solve(root,res);
        cout<<res<<endl;
    }
}