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
const int N=255,inf=1e6+5;
typedef long long LL;
int n;
int a[N],dp[N][N],dp2[N][N],sum[N];
int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    rep(i,n+1,2*n+1) a[i]=a[i-n],sum[i]=sum[i-1]+a[i];
    ms(dp2,-1);
    rep(len,1,n+1){
        rep(i,1,2*n+1){
            int j=i+len-1;
            if(j>2*n) break;
            if(j==i) {dp2[i][j]=0;continue;}
            rep(k,i,j){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
                if(dp2[i][j]==-1)
                    dp2[i][j]=dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1];
                else dp2[i][j]=min(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    //rep(i,1,n+1) printf("%d ",dp2[1][i]);puts("");
    int ans1=0,ans2=inf;
    rep(i,1,n+1) ans1=max(ans1,dp[i][i+n-1]),ans2=min(ans2,dp2[i][i+n-1]);
    printf("%d\n%d\n",ans2,ans1);
return 0;
}
