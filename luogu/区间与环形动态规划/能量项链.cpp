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
const int N=305,inf=1e9+5,mod=998244353;
typedef long long LL;
int a[N],dp[N][N];
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]),a[i+n]=a[i];
    rep(len,1,n+1){
        rep(i,1,2*n+1){//环形n后面的点也要处理
            int j=len+i-1;
            if(j>2*n) break;
            rep(k,i,j){
                dp[i][j]=max(dp[i][j],a[i]*a[k+1]*a[j+1]+dp[i][k]+dp[k+1][j]);
            }
        }
    }
    int ans=0;
    rep(i,1,n+1){
        ans=max(ans,dp[i][i+n-1]);
    }
    cout<<ans<<endl;
return 0;
}
