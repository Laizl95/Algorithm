
## Dijksra 优先队列O(ElogV)


```
struct E{
    int v,w,cost,next;
    E(){}
    E(int _v,int _w,int _cost,int _next){
        v=_v;w=_w;cost=_cost;next=_next;
    }
}edge[2*N];
struct node{
    int u,w,c;
    node(){}
    node(int _u,int _w,int _c):u(_u),w(_w),c(_c){}
    bool operator < (const node &a) const{
      return w>a.w || (w==a.w && c<a.c); //最小堆
   }
};
void add_edge(int u,int v,int w,int cost){
    edge[tot]=E(v,w,cost,head[u]);
    head[u]=tot++;
}

void dijkstra(int n,int sd,int zd){
   rep(i,1,n+1) vis[i]=0,dis[i]=inf,cost[i]=0;
   priority_queue<node> q;
   vis[sd]=1;dis[sd]=0;cost[sd]=c[sd];
   q.push(node(sd,0,c[sd]));
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
                q.push(node(v,dis[v],cost[v]));
            }else if(dis[v]==dis[u]+edge[i].w && cost[v]<cost[u]+edge[i].cost){
                cost[v]=cost[u]+edge[i].cost;
                q.push(node(v,dis[v],cost[v]));
            }
        }
   }
   printf("%d\n",cost[zd]);
}
int main(){
    tot=0;
    ms(head,-1);
}
```
