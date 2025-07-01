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
    if(root==nullptr) return new node(val);
    if(val<root->x) root->left=insert(root->left, val);
    if(val>root->x) root->right=insert(root->right,val);
    return root;
}
void in(node *root){
    if(root==nullptr) return;
    in(root->left);
    cout<<root->x<<" ";
    in(root->right);
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        node *root=nullptr;
        int cnt=0;
        vector<int>tmp;
        for (int i=0; i<n; i++){
            int a,b; char c;
            cin>>a>>b>>c;
            if(cnt==0){
                tmp.push_back(a);
                cnt++;
            }
            tmp.push_back(b);
        }
        for (int x:tmp) root=insert(root,x);
        in(root);
        cout<<endl;
    }
}