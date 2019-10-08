#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e4+5,inf=INT_MAX;
typedef long long LL;
int head[N],vis[N],dis[N],cost[N],c[N],tot=1;
int prime[1005];
vector<int> p;
map<LL,int> mp;
struct E{
    int v,w,cost,next;
    E(){}
    E(int _v,int _w,int _cost,int _next){
        v=_v;w=_w;cost=_cost;next=_next;
    }
}edge[2*N];
void prim(){
    for(int i=2;i<=1e3;++i)  prime[i]=1;
    for(int i=2;i<=1e3;++i){
        if(prime[i])
        for(int j=2*i;j<=1e3;j+=i)
            prime[j]=0;
    }
    for(int i=2;i<=1e3;i++) if(prime[i]) p.pb(i);
    /*LL t=1;int tot=0;
    for(int i=2;i<=1e3;i++)
            if(prime[i]){
                if(1e18/i<t) break;
                t=t*i;
             cout<<i<<" "<<t<<endl;
                tot+=1;

            }
    cout<<t<<" "<<tot<<endl;*/
}
struct node{
    int u,w,c;
    node(){}
    node(int _u,int _w,int _c):u(_u),w(_w),c(_c){}
    bool operator < (const node &a) const{
      return w>a.w || (w==a.w && c<a.c);
   }
};
void add_edge(int u,int v,int w,int cost){
    edge[tot]=E(v,w,cost,head[u]);
    head[u]=tot++;
}

void dijkstra(int n,int sd,int zd){
     //cout<<sd<<" "<<zd<<endl;
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
    int n,m;
    LL dis;prim();
    while(scanf("%d %d",&n,&m)!=EOF){
            int sd=-1,zd=-1;
            LL d1,d2;
            ms(head,-1);
        mp.clear();
        rep(i,0,n){
            scanf("%lld",&dis);
            mp[dis]=i+1;
            LL buf=1;
           rep(j,0,p.size()){
               if(dis/p[j]<buf){c[i+1]=j;break;}
               buf*=p[j];
            }
            if(sd==-1 || d1>dis) sd=i+1,d1=dis;
            if(zd==-1 || d2<dis) zd=i+1,d2=dis;
        }

        LL u,v;int d;
        rep(i,0,m){
            scanf("%lld %lld %d",&u,&v,&d);
            int x=mp[u],y=mp[v];
            add_edge(x,y,d,c[y]);
            add_edge(y,x,d,c[x]);
        }
        dijkstra(n,sd,zd);
    }
return 0;
}
