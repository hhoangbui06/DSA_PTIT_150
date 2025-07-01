#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

struct node{
    int val;
    node *left, *right;
    node (int x){
        val=x;
        left=right=nullptr;
    }
};
node *insert(node *root, int x){
    if(root==nullptr) root=new node(x);
    if(root->val>x) root->left=insert(root->left,x);
    if(root->val<x) root->right=insert(root->right,x);
    return root;
}
node *find(node *root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;
}
node *xoa(node *root, int x){
    if(root==nullptr) return nullptr;
    if(x>root->val) root->right=xoa(root->right,x);
    else if(x<root->val) root->left=xoa(root->left,x);
    else{
        if(root->left==NULL){
            node *tmp=root->right;
            delete root;
            return tmp;
        }
        if(root->right==NULL){
            node *tmp=root->left;
            delete root;
            return tmp;
        }
        node *tmp=find(root->right);
        root->val=tmp->val;
        root->right=xoa(root->right,tmp->val);
    }
    return root;
}
void in(node *root){
    if(root==nullptr) return;
    cout<<root->val<<" ";
    in(root->left);
    in(root->right);
}
int main(){
    faster();
    int n; cin>>n;
    node *root=nullptr;
    for (int i=1; i<=n; i++){
        cout<<"Query #"<<i<<": ";
        string s; cin>>s;
        if(s=="ins"){
            int x; cin>>x;
            root=insert(root,x);
            in(root);
            cout<<endl;
        }
        else{
            int x; cin>>x;
            root=xoa(root,x);
            in(root);
            cout<<endl;
        }
    }
}