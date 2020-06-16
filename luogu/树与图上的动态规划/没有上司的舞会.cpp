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
const int N=1e4+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int dp[N][2],a[N],vis[N];
int n;
vector<int> edge[N];
int dfs(int u){
    if(a[u]>0) dp[u][1]=a[u];
    dp[u][0]=0;
    for(auto &v:edge[u]){
        if(vis[v]) continue;
        vis[v]=1;
        dfs(v);
        if(dp[v][0]>0) dp[u][1]+=dp[v][0];
        if(dp[v][1]>0) dp[u][0]+=dp[v][1];
    }
}
int main(){
    int u,v;
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(i,1,n){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    vis[1]=1;
    dfs(1);

    printf("%d\n",max(dp[1][1],dp[1][0]));
return 0;
}
