#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

vector<int>v;
struct node{
    int val;
    node *left, *right;
    node(int x){
        val=x;
        left=right=nullptr;
    }
};
node *build(node *root, int x){
    if(root==nullptr) return new node(x);
    if(root->val<x) root->right=build(root->right,x);
    if(root->val>x) root->left=build(root->left,x);
    return root;
}
int bfs(node *root){
    int res=0;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(q.size()){
        auto [cur,lv]=q.front(); q.pop();
        if(cur->left==nullptr and cur->right==nullptr){
            res=max(res,lv);
        }
        if(cur->left) q.push({cur->left,lv+1});
        if(cur->right) q.push({cur->right,lv+1});
    }
    return res;
}
int main(){
    int t; cin>>t;
    while(t--){
        node*root=nullptr;
        int n; cin>>n;
        v.resize(n);
        for (int i=0; i<n; i++){
            int x; cin>>x;
            root=build(root,x);
        }
        cout<<bfs(root)<<endl;
    }
}