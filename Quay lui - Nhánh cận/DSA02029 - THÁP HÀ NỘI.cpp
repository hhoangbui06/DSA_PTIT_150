#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vs;
vector<vector<ll>>ds;
ll ans=INT_MAX,n;
void sinh(int n, char a, char b, char c){
    if(n==1){
        cout<<a<<" -> "<<c<<endl;
        return;
    }
    sinh(n-1,a,c,b);
    sinh(1,a,b,c);
    sinh(n-1,b,a,c);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    sinh(n,'A','B','C');
} 