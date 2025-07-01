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
node *build(vector<int>v, int l, int r){
    if(l>r) return nullptr;
    int m=(l+r)/2;
    node *root=new node(v[m]);
    root->left=build(v,l,m-1);
    root->right=build(v,m+1,r);
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
void in(node *root){
    if(root==nullptr) return;
    in(root->left);
    in(root->right);
    cout<<root->x<<" ";
}
ll cnt(node *root){
    queue<node*>q;
    q.push(root);
    ll res=0;
    while(q.size()){
        node*cur=q.front();q.pop();
        if(cur->left==nullptr and cur->right==nullptr) res++;
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return res;
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
        sort(v.begin(),v.end());
        node *root=build(v,0,n-1);
        cout<<cnt(root);
        cout<<endl;
    }
}