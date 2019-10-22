#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define mc(x,y) memcpy(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=205,inf=1e9;
typedef long long LL;
int dp[505][N],c[N],w[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int V,n;
        scanf("%d %d",&V,&n);
        rep(i,0,n) scanf("%d %d",&c[i+1],&w[i+1]);
        rep(i,0,n+1) rep(j,0,V+1) dp[i][j]=0;
        rep(i,1,n+1){
            rep(j,1,V+1){
                dp[i][j]=dp[i-1][j];
                if(j-c[i]>=0) dp[i][j]=max(dp[i-1][j-c[i]]+w[i],dp[i-1][j]);
            }
        }
        cout<<dp[n][V]<<endl;
    }
return 0;
}
