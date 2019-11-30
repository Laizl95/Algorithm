#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
//19:36
set<int> s;
map<int,int> mp[N];
vector<int> edge[N];
int vis[N];
void dfs(int u){
    if(vis[u]) return;
    s.erase(u);
    vis[u]=1;
    set<int>::iterator it;
    vector<int> v;
    for(it=s.begin();it!=s.end();++it){
        if(!mp[u].count(*it)) v.pb(*it);
    }
    rep(i,0,v.size()) s.erase(v[i]);
    rep(i,0,v.size()) dfs(v[i]);
}
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    rep(i,0,m){
        scanf("%d %d",&u,&v);
        mp[u][v]=1;
        mp[v][u]=1;
    }
    rep(i,0,n) s.insert(i+1);
    int ans=0;
    rep(i,1,n+1)
      if(!vis[i]){
        ans+=1;
        dfs(i);
      }
      printf("%d\n",ans-1);
return 0;
}
