#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=205;
int n,t,station_t[N],m1,start_0[N],m2,start_1[N];
int dp[N][N],vis[N][N][2];//t时刻在车站i等待的最短时间 t时刻有车到达i车站
//dp[i][j]=min(dp[i-1][j-t],dp[i+1][j-t],dp[i][j-1]+1) t:在t时刻有火车从i-1经过i
int main(){
    int cas=1;
    while(scanf("%d",&n)!=EOF && n){
        scanf("%d",&t);
        rep(i,1,n+1) rep(j,0,t+1) dp[i][j]=dp[i][j]=-1,vis[i][j][0]=vis[i][j][1]=0;
        dp[1][0]=0;
        rep(i,1,n) scanf("%d",&station_t[i]);
        scanf("%d",&m1);
        rep(i,1,m1+1){
            scanf("%d",&start_0[i]);
            int t1=start_0[i];
            vis[1][t1][0]=1;
            rep(j,1,n)  t1+=station_t[j],vis[j+1][t1][0]=1;
        }
        scanf("%d",&m2);
        rep(i,1,m2+1){
            scanf("%d",&start_1[i]);
            int t1=start_1[i];
            vis[n][t1][1]=1;
            per(j,1,n)  t1+=station_t[j],vis[j][t1][1]=1;
        }
        rep(j,1,t+1){
            rep(i,1,n+1){
              if(dp[i][j-1]!=-1) dp[i][j]=dp[i][j-1]+1;
              if(i>1 && vis[i][j][0] && j-station_t[i-1]>=0 && dp[i-1][j-station_t[i-1]]!=-1)
                if(dp[i][j]==-1 || dp[i][j]>dp[i-1][j-station_t[i-1]])
                    dp[i][j]=dp[i-1][j-station_t[i-1]];
              if(i<n && vis[i][j][1] && j-station_t[i]>=0 && dp[i+1][j-station_t[i]]!=-1)
                if(dp[i][j]==-1 || dp[i][j]>dp[i+1][j-station_t[i]])
                    dp[i][j]=dp[i+1][j-station_t[i]];

            }
        }
        printf("Case Number %d: ",cas++);
        if(dp[n][t]!=-1) printf("%d\n",dp[n][t]);
        else puts("impossible");
    }
return 0;
}
