#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
//17:20
int a[N],vis[N],ans[N],n;
int dfs(int u,int pre){
    if(u<1 || u>n) return -1;

    cout<<u<<" "<<pre<<endl;
    vis[u]+=1;
    if((a[u]+a[pre])&1){
        //ans[u]=1;
        ans[pre]=1;
        return 1;
    }
    if(vis[u]) return ans[u];
    if(vis[u]>=2) return -1;
    int l_n=dfs(u+a[u],u);
    int r_n=dfs(u-a[u],u);
    if(ans[u]==-1){
        if(l_n==-1) ans[u]=r_n;
        if(r_n==-1) ans[u]=l_n;
        if(l_n!=-1 && r_n!=-1) ans[u]=min(l_n,r_n);
    }else{
        if(l_n!=-1) ans[u]=min(ans[u],l_n);
        if(r_n!=-1) ans[u]=min(ans[u],r_n);
    }
    if(ans[u]==-1) return -1;
    return ++ans[u];
}
int main(){

    scanf("%d",&n);
    rep(i,0,n) scanf("%d",&a[i+1]);
    rep(i,1,n+1) if(!vis[i]) dfs(i,-1);
    rep(i,1,n+1) printf("%d ",ans[i]);puts("");
return 0;
}
