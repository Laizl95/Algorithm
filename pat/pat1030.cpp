#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=505;
int head[N],pre[N],vis[N],cost[N],dis[N],tot;
struct E{
  int v,w,cost,next;
  E(){}
  E(int _v,int _w,int _cost,int _next){
     v=_v;w=_w;cost=_cost;next=_next;
  }
}edge[N*N];
void add_edge(int u,int v,int w,int c){
   edge[tot]=E(v,w,c,head[u]);
   head[u]=tot++;
}
struct node{
   int u,w,c;
   node(){}
   node(int _u,int _w,int _c){u=_u;w=_w;c=_c;}
   bool operator < (const node &a) const{
      if(w!=a.w) return w>a.w;
      return c>a.c;
   }
};
void dfs(int u){
   if(u==-1) return;
   dfs(pre[u]);
   printf("%d ",u);
}
void dijkstra(int n,int sd,int zd){
    rep(i,0,n) vis[i]=0,dis[i]=INT_MAX-1,pre[i]=-1,cost[i]=INT_MAX-1;
    dis[sd]=0;cost[sd]=0;
    priority_queue<node> q;
    q.push(node(sd,0,0));
    while(!q.empty()){
        node a=q.top();
        q.pop();
        int u=a.u;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v;
            if(vis[v]) continue;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                cost[v]=cost[u]+edge[i].cost;
                pre[v]=u;
                q.push(node(v,dis[v],cost[v]));
            }else if(dis[v]==dis[u]+edge[i].w && cost[v]>cost[u]+edge[i].cost){
                cost[v]=cost[u]+edge[i].cost;
                pre[v]=u;
                q.push(node(v,dis[v],cost[v]));
            }
        }
    }
    dfs(zd);
    printf("%d %d\n",dis[zd],cost[zd]);
}
int main(){
    int n,m,sd,zd;
    while(scanf("%d %d %d %d",&n,&m,&sd,&zd)!=EOF){
        rep(i,0,n) head[i]=-1;
        int u,v,w,c;
        rep(i,0,m){
          scanf("%d %d %d %d",&u,&v,&w,&c);
          add_edge(u,v,w,c);
          add_edge(v,u,w,c);
        }
        dijkstra(n,sd,zd);
    }
return 0;
}
