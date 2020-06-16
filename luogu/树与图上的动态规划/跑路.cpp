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
const int N=65,inf=1e7+5;
typedef long long LL;
int a[N][N][N],dis[N][N];//i->jÊÇ·ñ´æÔÚ2^kµÄ±ß
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    int u,v;
    rep(i,1,n+1) rep(j,1,n+1) if(i!=j) dis[i][j]=inf;
    rep(i,1,m+1){
        scanf("%d %d",&u,&v);
        dis[u][v]=1;
        a[u][v][0]=1;
        //dis[v][u]=1;
       // a[v][u][0]=1;
    }
    rep(t,1,64){
        rep(k,1,n+1){
            rep(i,1,n+1){
                rep(j,1,n+1){
                    if(a[i][k][t-1] && a[k][j][t-1]){
                        a[i][j][t]=1;
                        dis[i][j]=1;
                    }
                }
            }
        }
    }
    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1)
        dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
    cout<<dis[1][n]<<endl;
return 0;
}
