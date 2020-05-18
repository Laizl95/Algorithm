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
const int N=1e2+5,inf=1e6+5,mod=1000007;
typedef long long LL;
int dp[N][N][N],a[N];


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    rep(i,0,n) scanf("%d",&a[i+1]);
    rep(i,1,n+1) dp[0][i][a[i]]=1;
    rep(i,0,m+1){
        rep(j,1,n+1){
            rep(k,1,a[j]+1){
                dp[i+1][j][k-1]=(dp[i+1][j][k-1]+dp[i][j][k])%mod;
            }
                if(i)
                rep(k,0,a[j]+1)
                rep(l,j+1,n+1){

                    dp[i+1][l][a[l]-1]=(dp[i+1][l][a[l]-1]+dp[i][j][k])%mod;
                }
        }
    }
    int ans=0;
    /*rep(i,0,m+1){
        rep(j,1,n+1){
            printf("%d\n",j);
            rep(k,0,a[j]+1) printf("%d ",dp[i][j][k]);puts("");
        }
        puts("");
    }*/
    rep(i,1,n+1) rep(j,0,a[i]+1) ans=(ans+dp[m][i][j])%mod;
    cout<<ans<<endl;
return 0;
}
