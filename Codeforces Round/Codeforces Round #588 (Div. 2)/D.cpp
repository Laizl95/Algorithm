#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=7000+5,inf=1e9+5;
typedef long long LL;

int n;
LL a[N];
int b[N],vis[N];
vector<int> num[N];
vector<int> edge[N];
int id;
void dfs(int u){
    vis[u]=id;
    num[id].pb(u);
    for(auto v:edge[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

int main(){

    scanf("%d",&n);
    rep(i,1,n+1) scanf("%lld",&a[i]);
    rep(i,1,n+1) scanf("%d",&b[i]);
    rep(i,1,n+1){
        rep(j,i+1,n+1){
            if((a[i]&a[j])>=a[i] && (a[j]&a[i])>=a[j]){
                   edge[i].pb(j);
                   edge[j].pb(i);
            }
        }
    }
    rep(i,1,n+1){
        if(!vis[i]) ++id,dfs(i);
    }
    //rep(i,1,n+1) printf("%d ",vis[i]);

    vector<LL> v;
    LL ans=0;
    rep(i,1,id+1){
        if(num[i].size()<2) continue;
        v.pb(a[num[i][0]]);
        for(auto it:num[i]) ans+=b[it];
    }

    rep(i,1,id+1){
        if(num[i].size()>1) continue;
        LL t=a[num[i][0]];

        for(auto j:v){
           if((t&j)>=t) {ans+=b[num[i][0]];break;}
        }
    }
    cout<<ans<<endl;
return 0;
}
