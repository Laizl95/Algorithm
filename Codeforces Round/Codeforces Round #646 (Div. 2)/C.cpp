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
const int N=1e3+5,inf=1e6+5,mod=998244353;
typedef long long LL;
vector<int> edge[N];
int vis[N],in[N];
int dfs(int root){
    int cnt=1;
    for(auto &v:edge[root]){
        if(vis[v]) continue;
        vis[v]=1;
        cnt+=dfs(v);
    }
    return cnt;
}
int main(){
    int t,n,root;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&root);
        rep(i,1,n+1) in[i]=0,vis[i]=0,edge[i].clear();
        int u,v;
        rep(i,1,n){
            scanf("%d %d",&u,&v);
            edge[u].pb(v);
            edge[v].pb(u);
            in[u]+=1;
            in[v]+=1;
        }

        if(in[root]==1 || n==1) {puts("Ayush");continue;}
        vis[root]=1;
        int cnt=dfs(root)-1;
       // cout<<cnt<<endl;
        if(cnt&1) puts("Ayush");
        else puts("Ashish");

    }
return 0;
}
