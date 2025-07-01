#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[10000], n;
bool check(){
    int left=0, right=n-1;
    while(left<=right){
        if(a[left]!=a[right]) return false;
        right--, left++;
    }
    return true;
}
void sinh(int i){
    for (int j=0; j<=1; j++){
        a[i]=j;
        if(i==n-1){
            if (check()){
                for (int k=0; k<n; k++) cout<<a[k]<<" ";
                cout<<endl;
            }
        }
        else sinh(i+1);
    }
}

int main(){
    cin>>n;
    sinh(0);
}