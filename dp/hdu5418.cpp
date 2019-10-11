#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcpy(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=20,inf=1e9;
typedef long long LL;
int dis[N][N];
int dp[1<<N][N];//经历城市集合s到达i的最小值
int n,m;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       int u,v,w;
       scanf("%d %d",&n,&m);
       rep(i,1,n+1) rep(j,1,n+1)  if(i!=j)dis[i][j]=inf;
       rep(i,1,1<<n) rep(j,0,n) dp[i][j]=inf;
       rep(i,0,m){
            scanf("%d %d %d",&u,&v,&w);
            dis[u][v]=min(dis[u][v],w);
            dis[v][u]=min(dis[v][u],w);
       }
       rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1)
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
       dp[1][0]=0;
       int up=1<<n;
       rep(S,1,up){
           //if(S&1==0) continue;
            rep(j,2,n+1)
                if((S>>(j-1))&1){
                    if(S==(1<<(j-1)))dp[S][j-1]=dis[1][j];
                    rep(k,1,n+1){
                        if(k!=j && (1<<(k-1)&S))
                            dp[S][j-1]=min(dis[k][j]+dp[(1<<(j-1))^S][k-1],dp[S][j-1]);
                    }
                }
       }
       int ans=inf;
       rep(j,0,n){
        ans=min(ans,dp[up-1][j]+dis[j+1][1]);}
        cout<<ans<<endl;
    }
return 0;
}
