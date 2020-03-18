#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=5e2+5,inf=1e9+5;
int dp[N][N],b[N];
int a[N][N];

int main(){

    int n;
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&b[i]);
    rep(i,1,n+1) rep(j,i,n+1){
        dp[i][j]=j-i+1;
        if(j==i) a[i][j]=b[i];
    }
    //a[i][j]=a[i][k],a[k+1][j]
    rep(k,1,n)
        for(int i=1;i+k<=n;++i){
            int r=i+k;
            rep(j,i+1,r+1)
                if(a[i][j-1] && a[i][j-1]==a[j][r]){
                    a[i][r]=a[i][j-1]+1;
                    dp[i][r]=1;
                }else dp[i][r]=min(dp[i][j-1]+dp[j][r],dp[i][r]);
    }
    cout<<dp[1][n]<<endl;
return 0;
}
