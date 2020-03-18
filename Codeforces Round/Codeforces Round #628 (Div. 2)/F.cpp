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
const int N=1e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
vector<int> edge[N],v1;
int dep[N],goal,fa[N],vis[N];
int dfs(int u,int pre){
    vis[u]=1;
    for(auto v:edge[u]){
        if(v==pre) continue;
        if(!dep[v]){
            dep[v]=dep[u]+1;
            fa[v]=u;
            if(dfs(v,u)) return 1;
        }
        else{
            if(dep[u]-dep[v]>=goal-1){
                 int x=u;
                 while(x!=v){
                    v1.pb(x);
                    x=fa[x];
                 }
                 v1.pb(v);
                 return 1;
            }
        }
    }
    if(vis[u])
        for(auto v:edge[u]){
            vis[v]=0;
        }
    return 0;
}
int main(){
    scanf("%d %d",&n,&m);
    int u,v;
    goal=1;
    while(goal*goal<n){
        ++goal;
    }
    rep(i,0,m){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    dep[1]=1;
    if(dfs(1,-1)){
        printf("2 %d\n",v1.size());
        for(auto u:v1) printf("%d ",u);
        puts("");
        return 0;
    }
    puts("1");
    rep(i,1,n+1){
        if(goal>0 && vis[i]) --goal,printf("%d ",i);
        if(goal==0) break;
    }
    puts("");
return 0;
}
