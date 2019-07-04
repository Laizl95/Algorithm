#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
int head[N],vis[N];
int tot=0;
struct E{
 int v,next;
 E(){}
 E(int _v,int _next):v(_v),next(_next){}
}edge[N*N];
void add_edge(int u,int v){
  edge[tot]=E(v,head[u]);
  head[u]=tot++;
}
int dfs(int u){
if(vis[u]) return 0;
     vis[u]=1;
    int ans=0;
   for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(vis[v]) continue;
        ans+=1;
        ans+=dfs(v);
   }
   return ans;
}
int main(){
    int n,m,k;
    while(scanf("%d %d %d",&n,&m,&k)!=EOF){
            int u,v;
        ms(head,-1);
        rep(i,0,m){
          scanf("%d %d",&u,&v);
          add_edge(u,v);
        }
        rep(i,0,k){
           scanf("%d",&u);
           ms(vis,0);
           vis[u]=1;
           int ans=0;
           rep(j,1,n+1){
             ans+=dfs(j);
           }
           printf("%d\n",n-2-ans);
        }
    }
return 0;
}
