#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e3+5,mod=1e9+7;
typedef long long LL;
LL dp[25][N];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    rep(j,1,n+1) dp[0][j]=1LL;
    rep(i,1,2*m+1)
        rep(j,1,n+1)
           rep(k,1,j+1){
                dp[i][k]=(dp[i-1][j]+dp[i][k])%mod;
              //  cout<<j<<" "<<k<<" "<<dp[j][k]<<endl;
            }
    LL ans=0;
    rep(j,1,n+1)  ans=(ans+dp[2*m-1][j])%mod;
    printf("%lld\n",ans);
return 0;
}
