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
const int N=255,inf=1e6+5;
typedef long long LL;
int n;
int a[N],dp[N][N];
int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(len,1,n+1){
        rep(i,1,n+1){
            int j=i+len-1;
            if(j>n) break;
            if(j==i) {dp[i][j]=a[i];continue;}
            rep(k,i,j){
                if(dp[i][k]!=0 && dp[i][k]==dp[k+1][j])
                    dp[i][j]=max(dp[i][j],dp[i][k]+1);
                //else dp[i][j]=max(dp[i][j],max(dp[i][k],dp[k+1][j]));
            }
        }
    }
    int ans=0;
    rep(i,1,n+1) rep(j,i,n+1) ans=max(ans,dp[i][j]);
    cout<<ans<<endl;
return 0;
}
