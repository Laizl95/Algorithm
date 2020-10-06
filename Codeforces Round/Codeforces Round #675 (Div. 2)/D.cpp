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
const int N=1e5+5,inf=2e9+5;
typedef long long LL;
int n,m,tot;
int head[N],vis[N],dis[N];
struct E{
    int v,w,next;
    E(){}
    E(int _v,int _w,int _next){
        v=_v;w=_w;next=_next;
    }
}edge[4*N];
struct node{
    int u,w;
    node(){}
    node(int _u,int _w):u(_u),w(_w){}
    bool operator < (const node &a) const{
      return w>a.w;
   }
};
void add_edge(int u,int v,int w){
    edge[tot]=E(v,w,head[u]);
    head[u]=tot++;
}

void dijkstra(int n){
   rep(i,1,n+1) vis[i]=0,dis[i]=inf;
   priority_queue<node> q;
   dis[0]=0;
   q.push(node(0,0));
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
                q.push(node(v,dis[v]));
            }
        }
   }
}
struct u{
    int x,y,id;
}a[N],b[N];
bool cmp(const u &a,const u &b){
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool cmp2(const u &a,const u &b){
    return a.y<b.y || (a.y==b.y && a.x<b.x);
}
int main(){
  scanf("%d %d",&n,&m);
  int sx,sy,zx,zy;
  scanf("%d %d %d %d",&sx,&sy,&zx,&zy);
  a[0].id=0;
  a[0].x=sx;
  a[0].y=sy;
  b[0]=a[0];
  rep(i,1,m+1){
    scanf("%d %d",&a[i].x,&a[i].y);
    a[i].id=i;
    b[i]=a[i];
  }
  sort(a,a+m+1,cmp);
  rep(i,0,m+1) head[i]=-1;
  rep(i,1,m+1){
    add_edge(a[i-1].id,a[i].id,a[i].x-a[i-1].x);
    add_edge(a[i].id,a[i-1].id,a[i].x-a[i-1].x);
  }
  sort(a,a+m+1,cmp2);
  rep(i,1,m+1){
    add_edge(a[i-1].id,a[i].id,a[i].y-a[i-1].y);
    add_edge(a[i].id,a[i-1].id,a[i].y-a[i-1].y);
  }
  dijkstra(m);
  int ans=2e9;
  rep(i,0,m+1){
    ans=min(ans,dis[i]+abs(zx-b[i].x)+abs(zy-b[i].y));
  }
  printf("%d\n",ans);
return 0;
}
