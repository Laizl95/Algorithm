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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m,k;
int a[N],dp[N],vis[N];
vector<int> edge[N];
//dp[i]=dp[j]+dp[j1]+...
int dfs(int u,int pre){
        dp[u]=a[u];
    for(auto v:edge[u]){
        if(v==pre) continue;
        int num=dfs(v,u);
        if(num>0) dp[u]+=num;
    }
    return dp[u];
}
void bfs(int u){
    queue<int> q;
    q.push(u); vis[u]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:edge[u]){
            if(vis[v]) continue;
            vis[v]=1;
            if(dp[v]>=0) dp[v]=max(dp[v],dp[u]);
            else dp[v]=max(dp[v],dp[u]+a[v]);
            q.push(v);
        }
    }
}
int main(){
    scanf("%d",&n);
    rep(i,1,n+1){
        scanf("%d",&a[i]);
        if(a[i]==0) a[i]=-1;
    }
    int u,v;
    rep(i,1,n){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    dfs(1,0);
    //rep(i,1,n+1) printf("%d ",dp[i]); puts("");
    bfs(1);
    rep(i,1,n+1) printf("%d ",dp[i]); puts("");
return 0;
}
