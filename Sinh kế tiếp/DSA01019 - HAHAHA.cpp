#include<bits/stdc++.h>
using namespace std;
#define ll long long

char a[2]={'A','H'};
string s; int n;
bool check(string s){
    if(s[0]!='H' or s[s.size()-1]!='A') return false; 
    for (int i=0; i<s.size()-1; i++){
        if(s[i]=='H' and s[i+1]=='H') return false;
    }
    return true;
}
void sinh(){
    for (int i=0; i<2; i++){
        s+=a[i];
        if(s.size()==n){
            if(check(s)) cout<<s<<endl;
        }
        else sinh();
        s.pop_back();
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        s.clear();
        cin>>n;
        sinh();
    }
}