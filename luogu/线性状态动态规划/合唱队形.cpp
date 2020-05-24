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
const int N=1e5+5,inf=1e6+5;
typedef long long LL;
int dp[N][2],a[N];
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(i,1,n+1){
        dp[i][0]=i-1;
        per(j,1,i){
            if(a[j]<a[i])
                dp[i][0]=min(dp[i][0],dp[j][0]+i-j-1);
        }
    }
    per(i,1,n+1){
        dp[i][1]=n-i;
        rep(j,i+1,n+1){
            if(a[j]<a[i])
                dp[i][1]=min(dp[i][1],dp[j][1]+j-i-1);
        }
    }
    int ans=inf;
    rep(i,1,n+1) ans=min(ans,dp[i][0]+dp[i][1]);
    cout<<ans<<endl;
return 0;
}
