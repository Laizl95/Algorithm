#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5,mod=1e9+7;
typedef long long LL;
//找出无向图中不在环中的点
vector<int> edge[N];
int dfn[N],low[N],vis[N];
int cnt=0;
stack<int> s;
vector<int> ans;
void tarjan(int w,int u){
    dfn[u]=low[u]=++cnt;
    s.push(u);
    vis[u]=1;
    rep(i,0,edge[u].size()){
        int v=edge[u][i];
        if(v==w) continue;
        if(!dfn[v]) tarjan(u,v);
        if(vis[v]) low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u]){
        int tot=0;
        while(s.top()!=u){
           tot+=1;
            //printf("%d ",s.top());
            s.pop();
        }
    if(tot==0) ans.pb(s.top());
    s.pop();
    }
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
            int u,v;
        rep(i,0,m){
            scanf("%d %d",&u,&v);
            edge[u].pb(v);
            edge[v].pb(u);
        }

        rep(i,1,n+1){
            if(!dfn[i]){
               tarjan(i,i);
            }
        }
        sort(ans.begin(),ans.end());
        rep(i,0,ans.size()) printf("%d\n",ans[i]);
    }
return 0;
}
