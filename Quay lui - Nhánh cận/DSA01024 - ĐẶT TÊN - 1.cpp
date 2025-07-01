#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
vector<string>v,s;
set<string>se;
void in(){
    for (int i=0; i<k; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void sinh(int x){
    for (int i=x; i<s.size(); i++){
        v.push_back(s[i]);
        if(v.size()==k){
            in();
        }
        else sinh(i+1);
        v.pop_back();
    }
}
int main(){
    cin>>n>>k;
    scanf("\n");
    for (int i=0; i<n; i++) {
        string x; cin>>x;
        se.insert(x);
    }
    s.assign(se.begin(),se.end());
    sinh(0);
}