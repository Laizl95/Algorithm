#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
vector<pair<int,int> > edge[N];
int n;
LL ans1,ans2;
int dfs(int v,int u){
    int cnt=1;
    rep(i,0,edge[v].size()){
        if(edge[v][i].first==u) continue;
        int sub=dfs(edge[v][i].first,v);
        cnt+=sub;
        if(sub&1) ans2+=1LL*edge[v][i].second;
        ans1+=1LL*min(sub,2*n-sub)*edge[v][i].second;
    }
   return cnt;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,2*n) edge[i].clear();
        ans1=0;ans2=0;
        int u,v,w;
        rep(i,0,2*n-1){
            scanf("%d %d %d",&u,&v,&w);
            u-=1;v-=1;
            edge[u].pb(make_pair(v,w));
            edge[v].pb(make_pair(u,w));
        }
        dfs(0,-1);
        printf("%lld %lld\n",ans2,ans1);
    }
return 0;
}
