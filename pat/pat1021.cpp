#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005;
struct E{
 int v,next;
 E(){}
 E(int _v,int _next){v=_v;next=_next;}
}edge[N*2];
int tot,head[N],n,in[N],vis[N];
void add_edge(int u,int v){
  edge[tot]=E(v,head[u]);
  head[u]=tot++;
}
int dfs(int u){
        vis[u]=1;
        int num=1;
   for(int i=head[u];i!=-1;i=edge[i].next){
       int v=edge[i].v;
       if(vis[v]) continue;
        num+=dfs(v);
   }
   return num;
}
int solve(int u){
        vis[u]=1;
        int num=0;
   for(int i=head[u];i!=-1;i=edge[i].next){
       int v=edge[i].v;
       if(vis[v]) continue;
        num=max(solve(v),num);
        vis[v]=0;
   }
   vis[u]=0;
   return num+1;

}
int main(){
    while(scanf("%d",&n)!=EOF){
            if(n==1){puts("1");continue;}
        int u,v;tot=0;
        rep(i,1,n+1) head[i]=-1,in[i]=0,vis[i]=0;
        rep(i,0,n-1){
         scanf("%d %d",&u,&v);
         add_edge(u,v);
         add_edge(v,u);
         in[u]+=1;in[v]+=1;
        }
        int num=dfs(1);
        if(num==n){
                int _max=0;
                int ans[N],id=0;rep(i,1,n+1) vis[i]=0;
            rep(i,1,n+1){
                if(in[i]==1){
                    int num=solve(i);//cout<<num<<endl;
                    if(num>_max) _max=num,id=0,ans[id++]=i;
                    else if(num==_max) ans[id++]=i;
                }
            }

            rep(i,0,id) printf("%d\n",ans[i]);
        }else{
            int tot=1;
           rep(i,2,n+1) if(!vis[i]) dfs(i),tot+=1;
           printf("Error: %d components\n",tot);
        }
    }
return 0;
}
