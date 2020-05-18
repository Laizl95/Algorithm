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
const int N=2e2+5,inf=1e6+5;
typedef long long LL;

int a[N],b[N],dp[N][N][2],sum[N];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    rep(i,1,n+1) {
        scanf("%d %d",&a[i],&b[i]);
        sum[i]=sum[i-1]+b[i];
    }
    rep(i,1,n+1) rep(j,1,n+1) dp[i][j][0]=dp[i][j][1]=inf;
    dp[k][k][0]=dp[k][k][1]=0;
    rep(len,2,n+1){
        rep(i,1,n+1){
            int j=i+len-1;
            if(j>n) break;
            dp[i][j][0]=min(dp[i+1][j][0]+(a[i+1]-a[i])*(sum[n]-sum[j]+sum[i]),
                            dp[i+1][j][1]+(a[j]-a[i])*(sum[n]-sum[j]+sum[i]));

            dp[i][j][1]=min(dp[i][j-1][0]+(a[j]-a[i])*(sum[n]-sum[j-1]+sum[i-1]),
                            dp[i][j-1][1]+(a[j]-a[j-1])*(sum[n]-sum[j-1]+sum[i-1]));
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
return 0;
}
