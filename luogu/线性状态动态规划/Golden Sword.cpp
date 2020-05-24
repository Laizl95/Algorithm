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
const int N=5505;
typedef long long LL;
const LL inf=1LL<<62;
LL dp[N][N],q[N];
int a[N],pos[N];
int main(){
    int n,w,s;
    scanf("%d %d %d",&n,&w,&s);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(i,0,n+1) rep(j,0,n+1) dp[i][j]=-inf;
    dp[0][0]=0;
    rep(i,1,n+1){
        int head=1,tail=1;
        pos[head]=w;
        q[head]=dp[i-1][w];
        per(j,1,w+1){
            while(pos[head]>j+s-1 && head<=tail) ++head;
            while(dp[i-1][j-1]>q[tail] && head<=tail) --tail;
            pos[++tail]=j-1;
            q[tail]=dp[i-1][j-1];
            dp[i][j]=q[head]+j*1LL*a[i];
        }
    }
    LL ans=-inf;
    rep(i,1,w+1) ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
return 0;
}
