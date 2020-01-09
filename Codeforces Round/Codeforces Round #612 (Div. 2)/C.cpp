#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105,inf=1e9+5;
typedef long long LL;
int dp[N][N][N][2],a[N];
int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,n+1) rep(j,0,n+1) rep(k,1,n+1) dp[i][j][k][0]=inf,dp[i][j][k][1]=inf;
    rep(i,1,n+1) scanf("%d",&a[i]);
    dp[0][0][0][1]=0;dp[0][0][0][0]=0;
    rep(i,1,n+1){
        if(a[i]==0){
            rep(k,0,(n+1)/2+1){
                int l=i-k;
                if(k>0) dp[k][l][i][0]=min(dp[k-1][l][i-1][0],dp[k-1][l][i-1][1]+1);
                if(l>0) dp[k][l][i][1]=min(dp[k][l-1][i-1][0]+1,dp[k][l-1][i-1][1]);
            }
        }else{
            if(a[i]&1){
                rep(k,1,(n+1)/2+1){
                   int l=i-k;
                if(k>0) dp[k][l][i][0]=min(dp[k-1][l][i-1][0],dp[k-1][l][i-1][1]+1);}
                //if(l>0) dp[k][l][i][1]=min(dp[k][l-1][i-1][0]+1,dp[k][l-1][i-1][1]);
            }else{
                rep(k,0,(n+1)/2+1){
                     int l=i-k;
                //if(k>0) dp[k][l][i][0]=min(dp[k-1][l][i-1][0],dp[k-1][l][i-1][1]+1);
                if(l>0) dp[k][l][i][1]=min(dp[k][l-1][i-1][0]+1,dp[k][l-1][i-1][1]);
                }
            }
        }
        /*rep(k,0,(n+1)/2+1) rep(l,0,n/2+1){
            printf("%d %d %d\n",k,l,dp[k][l][i][0]);
            printf("%d %d %d\n",k,l,dp[k][l][i][1]);
        }puts("");*/
    }
    int ans=inf;
    ans=min(dp[(n+1)/2][n/2][n][0],dp[(n+1)/2][n/2][n][1]);
    printf("%d\n",ans);
return 0;
}
