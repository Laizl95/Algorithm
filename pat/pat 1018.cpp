#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=505,M=500005;
struct node{
 int u,dis,bike,return_bike;
 node(int _u,int _dis,int _bike,int _return_bike){
   u=_u;dis=_dis;bike=_bike;return_bike=_return_bike;
 }
 bool operator <(const node &a)const{//路程最短 车数量最少
      if(dis!=a.dis) return dis>a.dis;
      if(bike!=a.bike) return bike>a.bike;
      return return_bike>a.return_bike;
 }
};
struct E{
 int v,next,dis;
 E(){}
 E(int _v,int _dis,int _next):v(_v),dis(_dis),next(_next){}
}edge[M];
int num[N],head[N],tot,pre[N],dis[N],bikes[N],vis[N],return_bikes[N];
void add_edge(int u,int v,int w){
   edge[tot]=E(v,w,head[u]);
   head[u]=tot++;
}
void dfs(int u,int zd){
  if(u==-1) return;
  if(u!=zd) printf("%d->",u);
  else printf("%d ",u);
  dfs(pre[u],zd);
}
void dijkstra(int sd,int zd,int c_max,int n){
   rep(i,0,n+1) pre[i]=-1,dis[i]=INT_MAX-1;
   dis[sd]=0;ms(vis,0);
   priority_queue<node> q;
   rep(i,0,n+1) bikes[i]=INT_MAX-1,return_bikes[i]=INT_MAX-1;
   int x=c_max-num[sd];
   if(x>0) bikes[sd]=x,return_bikes[sd]=0;
   else return_bikes[sd]=-x,bikes[sd]=0;
   num[zd]=c_max;
   q.push(node(sd,0,bikes[sd],return_bikes[sd]));
   while(!q.empty()){
       node now=q.top();
       q.pop();
       int u=now.u;
       vis[u]=1;
       for(int i=head[u];i!=-1;i=edge[i].next){
          int v=edge[i].v;
          if(vis[v]) continue;
          int return_b=num[v]-c_max,send_b=-return_b;
          if(dis[v]>dis[u]+edge[i].dis){
             dis[v]=dis[u]+edge[i].dis;
             if(send_b>0)
                bikes[v]=bikes[u]+send_b,return_bikes[v]=return_bikes[u];
             else{
                 int c=bikes[u]-return_b;
                 if(c>0) bikes[v]=c,return_bikes[v]=return_bikes[u];
                 else bikes[v]=0,return_bikes[v]=-c+return_bikes[u];
             }
             pre[v]=u;
             q.push(node(v,dis[v],bikes[v],return_bikes[v]));
          }
          else if(dis[v]==dis[u]+edge[i].dis){
            if(send_b>0){
                if(bikes[v]>bikes[u]+send_b){
                  bikes[v]=bikes[u]+send_b;
                  return_bikes[v]=return_bikes[u];
                  pre[v]=u;
                  q.push(node(v,dis[v],bikes[v],return_bikes[v]));
                }
                else if(bikes[v]==bikes[u]+send_b && return_bikes[v]>return_bikes[u]){
                    return_bikes[v]=return_bikes[u];
                    pre[v]=u;
                    q.push(node(v,dis[v],bikes[v],return_bikes[v]));
                }
            }
            else{
                    int c=bikes[u]-return_b;
            if(c>0){
                    if(bikes[v]>c){
                        bikes[v]=c;
                        return_bikes[v]=return_bikes[u];
                        pre[v]=u;
                        q.push(node(v,dis[v],bikes[v],return_bikes[v]));
                    }
                    else if(bikes[v]==c && return_bikes[v]>return_bikes[u]){
                        return_bikes[v]=return_bikes[u];
                        pre[v]=u;
                        q.push(node(v,dis[v],bikes[v],return_bikes[v]));
                    }
            }
            else{
                if(bikes[v]>0){
                    bikes[v]=0;
                    return_bikes[v]=-c+return_bikes[u];
                    pre[v]=u;
                    q.push(node(v,dis[v],bikes[v],return_bikes[v]));
                }else if(bikes[v]==0 && return_bikes[v]>-c+return_bikes[u]){
                    return_bikes[v]=-c+return_bikes[u];
                    pre[v]=u;
                    q.push(node(v,dis[v],bikes[v],return_bikes[v]));
                }
            }
           }

          }
       }
   }
   printf("%d ",bikes[zd]);
   dfs(zd,sd);
   printf("%d\n",return_bikes[zd]);

}
int main(){
    //freopen("d://input.txt","r",stdin);
    int c_max,n,zd,m;
    while(scanf("%d %d %d %d",&c_max,&n,&zd,&m)!=EOF){
        rep(i,1,n+1) scanf("%d",&num[i]);
        ms(head,-1);tot=0;
        int u,v,d;
        rep(i,0,m){
          scanf("%d %d %d",&u,&v,&d);
          add_edge(u,v,d);
          add_edge(v,u,d);
        }
        dijkstra(zd,0,c_max/2,n);
    }
return 0;
}
