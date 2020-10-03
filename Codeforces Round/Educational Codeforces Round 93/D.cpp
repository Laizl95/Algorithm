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
const int N=2e2+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int a[N],b[N],c[N];
int dp[N][N][N];
int main(){
    int x1,x2,x3;
    scanf("%d %d %d",&x1,&x2,&x3);
    rep(i,1,x1+1) scanf("%d",&a[i]);
    rep(i,1,x2+1) scanf("%d",&b[i]);
    rep(i,1,x3+1) scanf("%d",&c[i]);
    //sort(a+1,a+1+x1);
    //sort(b+1,b+1+x2);
    //sort(c+1,c+1+x3);
    int ans=0;
    rep(i,0,x1+1){
        rep(j,0,x2+1){
            rep(k,0,x3+1){
                if(i&&j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]*b[j]);
                if(i&&k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i]*c[k]);
                if(j&&k) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+b[j]*c[k]);
                ans=max(ans,dp[i][j][k]);
            }
        }
    }
    cout<<ans<<endl;
return 0;
}
