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
int n,k;
int a[N],vis[N],d[N],num[N],sum[N];
vector<int> edge[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:edge[u]){
            if(vis[v]) continue;
            vis[v]=1;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
}
int dfs(int u){
    num[u]=1;
    for(auto v:edge[u]){
        if(vis[v]) continue;
        vis[v]=1;
        num[u]+=dfs(v);
    }
    return num[u];
}
bool cmp(const int &a,const int &b){
    return a>b;
}
int main(){
    scanf("%d %d",&n,&k);
    int u,v;
    rep(i,0,n-1){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    bfs(1);
   rep(i,1,n+1) vis[i]=0;
   vis[1]=1;
   dfs(1);
   //rep(i,1,n+1) printf("%d ",num[i]);
   rep(i,1,n+1) d[i]-=num[i]-1;
   //puts("");
    sort(d+1,d+n+1,cmp);
    int max_d=d[1];
    LL ans=0;
    rep(i,1,k+1){
        ans+=d[i];
    }
    cout<<ans<<endl;
return 0;
}
