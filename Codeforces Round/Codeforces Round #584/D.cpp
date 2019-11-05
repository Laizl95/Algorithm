#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5;
typedef long long LL;
//20
vector<int> edge[N];
int vis[N],tot=0;
void dfs(int u){

    vis[u]=1;
    rep(i,0,edge[u].size()){
        int v=edge[u][i];
        if(vis[v]) continue;
        tot+=1;
        dfs(v);
    }
}
int main(){

    int n,k;
    scanf("%d %d",&n,&k);
    int u,v;
    rep(i,0,k){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    rep(i,1,n+1){
        if(!vis[i]) dfs(i);
    }
    printf("%d\n",max(k-tot,0));
return 0;
}
