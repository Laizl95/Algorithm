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
const int N=5e3+5,inf=1e7+5;
typedef long long LL;
int a[N],dp[N][N];
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(i,0,n+1) rep(j,0,n+1) dp[i][j]=inf;
    dp[0][0]=0;
    rep(i,1,n+1){
        rep(j,0,n+1){
           dp[i][min(a[i],j)]=min(dp[i][min(a[i],j)],dp[i-1][j]+1);//Êú×ÅË¢
           if(dp[i-1][j]==inf || a[i]>n) continue;
           if(j<=a[i]) dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]+a[i]-j);//ºá×ÅË¢
           else dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]);
        }
    }
    int ans=n;
    //rep(i,1,n+1){rep(j,0,n+1) printf("%d ",dp[i][j]);puts("");}
    rep(i,0,n+1)
        ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
return 0;
}
