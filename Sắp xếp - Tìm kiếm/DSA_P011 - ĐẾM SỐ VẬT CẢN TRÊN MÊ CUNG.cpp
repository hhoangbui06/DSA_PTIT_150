#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dx[4]={-1,0,0,1}, dy[4]={0,-1,1,0};
char a[100][100]={};
int n,m;
void check(int x, int y){
    for (int i=0; i<4; i++){
        int x1=x+dx[i],y1=y+dy[i];
        if(x1<=n and y1<=m and x1>=1 and y1>=1 and a[x1][y1]=='#'){
            a[x1][y1]='.';
            check(x1,y1);
        }
    }
}
int main(){
    int cnt=0;
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) cin>>a[i][j];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if(a[i][j]=='#'){
                a[i][j]='.';
                cnt++;
                check(i,j);
            }
        }
    }
    cout<<cnt;
}