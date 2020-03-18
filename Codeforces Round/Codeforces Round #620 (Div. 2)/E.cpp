#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=1e5+5,inf=1e9+5;
typedef long long LL;
int fa[N][31],dep[N];
vector<int> edge[N];
void dfs(int u,int pre){
    fa[u][0]=pre;
    dep[u]=dep[fa[u][0]]+1;
    rep(i,1,31){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(auto v:edge[u]){
        if(v==pre) continue;
        dfs(v,u);
    }
}
int lca(int x,int y){
    if(dep[x]>dep[y]) swap(x,y);
    int tmp=dep[y]-dep[x];
    for(int j=0;tmp>0;++j,tmp>>=1)
        if(tmp&1) y=fa[y][j];//用深的点
    if(y==x) return x;
    for(int j=30;j>=0;j--){
        if(fa[x][j]!=fa[y][j]){
            x=fa[x][j];
            y=fa[y][j];
        }
    }
    return fa[y][0];//用深的点
}
int cal(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int judge(int d,int k){
  return (d<=k && (k-d)%2==0);
}
int main(){
    int n;
    scanf("%d",&n);
    int q,u,v;
    rep(i,0,n-1){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    dfs(1,0);
    scanf("%d",&q);
    int x,y,a,b,k;
    while(q--){
        scanf("%d %d %d %d %d",&x,&y,&a,&b,&k);
        //cout<<lca(a,b)<<endl;
        if(judge(cal(a,b),k) || judge(cal(a,x)+1+cal(y,b),k)
           || judge(cal(a,y)+1+cal(x,b),k)){
            puts("YES");
        }else puts("NO");
    }
return 0;
}
