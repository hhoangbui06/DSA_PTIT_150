#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

int cot[9], hang[9], cheo1[17], cheo2[17], co[9][9];
ll sum,res;
void sinh(int i, ll sum){
    for (int j=1; j<=8; j++){
        if(!cot[j] and !cheo1[i+j-1] and !cheo2[i-j+8]){
            cot[j]=1;
            cheo1[i+j-1]=1,cheo2[i-j+8]=1;
            if(i==8){
                res=max(res,sum+co[i][j]);
            }
            else sinh(i+1, sum+co[i][j]);
            cot[j]=cheo1[i+j-1] =cheo2[i-j+8]=0;
        }
    }
}
int main(){
    faster();
    int t; cin>>t;
    while(t--){
        res=0;
        for (int i=1; i<=8; i++){
            for (int j=1; j<=8; j++) cin>>co[i][j];
        }
        sinh(1, 0);
        cout<<res<<endl;
    }
}