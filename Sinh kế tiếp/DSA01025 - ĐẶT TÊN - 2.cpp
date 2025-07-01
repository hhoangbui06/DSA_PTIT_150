#include<bits/stdc++.h>
using namespace std;
#define ll long long

char c1,c2;
int n,k;

void sinh(char x, string s){
    for (char c=x; c<=c2; c++){
        string tmp=s+c;
        if(tmp.size()==k){
            cout<<tmp<<endl;
        }
        else sinh(c+1,tmp);
    } 
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        c2='A'+n-1;
        sinh('A',"");
    }
}