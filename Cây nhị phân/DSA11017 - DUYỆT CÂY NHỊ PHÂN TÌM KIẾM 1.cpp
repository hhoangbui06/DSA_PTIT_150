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
void in(node *root){
    if(root==nullptr) return;
    in(root->left);
    in(root->right);
    cout<<root->x<<" ";
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>tmp(n);
        for (int i=0; i<n; i++) cin>>tmp[i];
        node *root=nullptr;
        for (int x:tmp) root=insert(root,x);
        in(root);
        cout<<endl;
    }
}