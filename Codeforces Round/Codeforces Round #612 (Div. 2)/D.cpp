#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e3+5,inf=1e9+5;
typedef long long LL;
vector<int> edge[N];
int a[N],ans[N],son[N],in[N],out[N];
int n,tot,ok=1;
int dfs(int u){
    int num=0;
    in[u]=++tot;
    rep(i,0,edge[u].size()){
        int v=edge[u][i];
        int t=dfs(v);
        rep(i,in[v],out[v]+1)
            ans[i]+=num;
        num+=t;
    }
    num+=1;
    out[u]=tot;
    int cnt=out[u]-in[u]+1;
    if(son[u]>=cnt){
        ok=0;
        return 0;
    }
    ans[in[u]]=son[u];
    rep(i,in[u]+1,out[u]+1)
        if(ans[i]>=son[u]) ++ans[i];
    return num;
}
int main(){
    scanf("%d",&n);
    int x,root;
    rep(i,0,n){
       scanf("%d %d",&x,&son[i+1]);
       if(x) edge[x].pb(i+1);
       else root=i+1;
       ans[i+1]=-1;
    }

    dfs(root);
    if(!ok) {puts("NO");return 0;}
    puts("YES");
    rep(i,1,n+1) printf("%d ",ans[in[i]]+1);puts("");
return 0;
}
