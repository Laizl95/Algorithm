#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1005,inf=1e6+5;
typedef long long LL;
int a[N],b[N];
int dp[N][2][N];
/*dp[i][0][k]=max(dp[i-1][j][k-1]+a[i]-a[j]);
dp[i][j][k]=dp[i-1][j][k];
dp[i][i][k]=dp[i-1][0][k];*/
int main(){
    int n,m=5;
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    dp[0][1][0]=-inf;
    dp[0][1][1]=-inf;

    rep(i,1,n+1){
        rep(k,0,m+1){
        int j=i&1;
        if(i-1>k) dp[j][1][k]=max(dp[j^1][1][k],dp[j^1][0][k]-a[i]);
        else dp[j][1][k]=-inf;
        if(i-1==0 && k==0) dp[j][1][k]=-a[i];
        dp[j][0][k]=dp[j^1][0][k];
        if(k && i-1>k-1)
            dp[j][0][k]=max(dp[j][0][k],dp[j^1][1][k-1]+a[i]);
        if(i<=k) dp[j][0][k]=dp[j][1][k]=-inf;
      }

    }
    int ans=0;
    rep(i,0,2)rep(j,0,2) rep(k,0,m+1){
       // cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
        ans=max(ans,dp[i][j][k]);}
    cout<<ans<<endl;
return 0;
}
