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
const int N=105,inf=1e6+5,mod=19650827;
typedef long long LL;
int n,m;
int dp[N][N],in[N];
//dp[i][k]=min(dp[son1][x]+dp[son2][y]) x+y=k;
vector<pii> edge[N];
void solve(int u,int fa){
    if(in[u]==1) return;
    pii son[2];
    int t=0;
    for(auto &x:edge[u]){
        int v=x.fi,w=x.se;
        if(v==fa) continue;
        son[t++]=x;
        solve(v,u);
    }
    rep(i,1,m+1){
        rep(j,0,i+1){
            int cnt=0;
            if(j) cnt+=son[0].se;
            if(i-j-1>=0) cnt+=son[1].se;
            if(j && i-j-1>=0)
                dp[u][i]=max(dp[u][i],dp[son[0].fi][j-1]+cnt+dp[son[1].fi][i-j-1]);
            else if(i-j-1>=0)
                dp[u][i]=max(dp[u][i],dp[son[1].fi][i-j-1]+cnt);
            else if(j) dp[u][i]=max(dp[u][i],dp[son[0].fi][j-1]+cnt);

        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    int u,v,w;
    rep(i,0,n-1){
       scanf("%d %d %d",&u,&v,&w);
       edge[u].pb(mp(v,w));
       edge[v].pb(mp(u,w));
       in[u]+=1;
       in[v]+=1;
    }
    rep(i,1,n+1) if(in[i]==2){

        solve(i,-1);
        cout<<dp[i][m]<<endl;
        return 0;
    }
return 0;
}
