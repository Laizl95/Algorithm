#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcpy(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e3+5,MAXN=3,l=2,mod=10;
typedef long long LL;
int n,m;
vector<int> edge[N];
int vi[N][N];
int vis[N];
int dfs(int u,int fa){
    vis[u]=1;
    rep(i,0,edge[u].size()){
        int v=edge[u][i];
        if(v==fa) continue;
        if(vis[v])return 1;
        vis[v]=1;
        if(dfs(v,u)) return 1;
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        rep(i,0,n) edge[i].clear(),vis[i]=0;
        rep(i,0,n) rep(j,0,n) vi[i][j]=0;

        int u,v;
        int ok=0;
        rep(i,0,m){
            scanf("%d %d",&u,&v);
            edge[u].pb(v);
            edge[v].pb(u);
            if(vi[u][v]) ok=1;
            vi[u][v]=1;
            vi[v][u]=1;
            if(u==v) ok=1;
        }
        rep(i,0,n)
            if(!vis[i]){
                if(dfs(i,i)) ok=1;
            }
        cout<<ok<<endl;
    }
return 0;
}
