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
node *build(int l, int r){
    if(l>r) return nullptr;
    int m=(l+r)/2;
    node *root=new node(v[m]);
    root->left=build(l,m-1);
    root->right=build(m+1,r);
    return root;
}
void in(node *root){
    if(root==nullptr) return;
    cout<<root->val<<" ";
    in(root->left);
    in(root->right);
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        v.resize(n);
        for (int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(),v.end());
        node *root=build(0,v.size()-1);
        in(root);
        cout<<endl;
    }
}