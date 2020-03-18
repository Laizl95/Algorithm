#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
int a[N],vis[N],d[N];
vector<int> edge[N],rev_edge[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    d[s]=0;vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:rev_edge[u]){
            if(vis[v]) continue;
            vis[v]=1;
            d[v]=d[u]+1;
            q.push(v);
        }
    }
}
int main(){

    scanf("%d %d",&n,&m);
    int u,v,k;
    rep(i,0,m){
        scanf("%d %d",&u,&v);
        edge[u].pb(v);
        rev_edge[v].pb(u);
    }
    scanf("%d",&k);
    rep(i,0,k) scanf("%d",&a[i]);
    bfs(a[k-1]);
    //rep(i,1,n+1) cout<<d[i]<<" ";cout<<endl;
    int mn=0,mx=0;
    rep(i,0,k-1){
        int u=a[i],v=a[i+1];
        //cout<<u<<" "<<v<<endl;
        if(d[u]!=d[v]+1) ++mn,++mx;
        else{
                for(auto m:edge[u])
                if(m!=v && d[v]==d[m]){
                    ++mx;break;
                }
        }
    }
    cout<<mn<<" "<<mx<<endl;
return 0;
}
