#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=505;
int dist[N][N],dis[N],rescue[N],num_rescue[N],num_dis[N];
int dijkstra(int sd,int zd,int n){
    int vis[N];
    num_rescue[sd]=rescue[sd];
    num_dis[sd]=1;
    rep(i,0,n-1){
        if(i==sd) continue;
        vis[i]=0;
        if(dist[i][sd]!=-1)
            dis[i]=dist[i][sd],num_rescue[i]=rescue[i]+num_rescue[sd],num_dis[i]=1;
        else dis[i]=-1,num_rescue[i]=0,num_dis[i]=0;
    }
        vis[sd]=1;

    rep(i,1,n-1){
      int min_dist=-1,u;
      rep(j,0,n-1)
       if(!vis[j] && dis[j]!=-1){
         if(min_dist==-1) min_dist=dis[j],u=j;
         else if(min_dist>dis[j]) min_dist=dis[j],u=j;
       }
       vis[u]=1;
       rep(j,0,n-1)
         if(!vis[j] && dist[j][u]!=-1){
            if(dist[j][u]+dis[u]<dis[j] || dis[j]==-1){
                dis[j]=dist[j][u]+dis[u];
                num_rescue[j]=num_rescue[u]+rescue[j];
                num_dis[j]=num_dis[u];
            }
            else if(dist[j][u]+dis[u]==dis[j]){
                num_rescue[j]=max(num_rescue[j],num_rescue[u]+rescue[j]);
                num_dis[j]+=num_dis[u];
            }
         }
        //rep(i,0,n-1) printf("%d %d\n",dis[i],num_rescue[i]);puts("");
    }

    printf("%d %d\n",num_dis[zd],num_rescue[zd]);
}
int main(){
int n,m,sd,zd;
while(scanf("%d %d %d %d",&n,&m,&sd,&zd)!=EOF){
     rep(i,0,n-1) num_dis[i]=0,scanf("%d",&rescue[i]);

     rep(i,0,n-1) rep(j,0,n-1) if(i!=j) dist[i][j]=-1; else dist[i][j]=0;
     int a,b,c;
     rep(i,1,m){
      scanf("%d %d %d",&a,&b,&c);
      dist[a][b]=dist[b][a]=c;
     }
     dijkstra(sd,zd,n);
}
return 0;
}
