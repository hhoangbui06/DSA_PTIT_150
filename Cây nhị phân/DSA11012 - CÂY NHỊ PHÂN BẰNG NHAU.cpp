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
node *build(){
        int n; cin>>n;
        unordered_map<int,node*>k;
        unordered_map<int,bool>m;
        int a,b; char c;
        node *tmp=nullptr;
        for (int i=0; i<n; i++){
            cin>>a>>b>>c;
            if(k[a]==0){
                tmp=new node(a);
                k[a]=tmp;
            }
            if(c=='R'){
                node *rac=new node(b);
                k[a]->right=rac;
                k[b]=rac;
            }
            else if (c=='L'){
                node *rac=new node(b);
                k[a]->left=rac;
                k[b]=rac;
            }
        }
        return tmp;
}
bool check(node *tree1, node *tree2){
    queue<node*>q1, q2;
    q1.push(tree1), q2.push(tree2);
    while(q1.size() or q2.size()){
        if((!q1.size() and q2.size()) or (q1.size() and !q2.size())) return false;
        node* cur1=q1.front(), *cur2=q2.front();
        q1.pop(), q2.pop();
        if(cur1->x !=cur2->x) return false;
        if(cur1->left) q1.push(cur1->left);
        if(cur2->left) q2.push(cur2->left);
        if(cur1->right) q1.push(cur1->right);
        if(cur2->right) q2.push(cur2->right);
    }
    return true;
}
int main(){
    int t; cin>>t;
    while(t--){
        node *tree1=build();
        node*tree2=build();
        cout<<check(tree1,tree2)<<endl;
    }
}