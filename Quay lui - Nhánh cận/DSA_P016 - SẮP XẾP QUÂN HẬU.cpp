#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

int cot[21], hang[21], cheo1[41], cheo2[41], cnt,n, co[21][21];
ll res=0;
void sinh(int i, ll sum){
    for (int j=1; j<=8; j++){
        if(cot[j]==0 and cheo1[i+j-1]==0 and cheo2[i-j+8]==0){
            hang[i]=j;
            cheo1[i+j-1]=1;
            cot[j]=1;
            cheo2[i-j+8]=1;
            if(i==8){
                res=max(res, sum+co[i][j]);
                cnt++;
            }
            else sinh(i+1, sum+co[i][j]);
            cot[j]=0;
            cheo1[i+j-1]=0;
            cheo2[i-j+8]=0;
        }
    }
}
int main(){
    faster();
    int t; cin>>t;
    for (int test=1; test<=t; test++){
        cout<<"Test "<<test<<": ";
        res=0;
        for (int i=1; i<=8; i++){
            for (int j=1; j<=8; j++) cin>>co[i][j];
        }
        sinh(1,0);
        cout<<res<<endl;
    }
}
