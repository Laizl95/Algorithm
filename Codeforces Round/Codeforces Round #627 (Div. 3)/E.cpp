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
const int N=2e3+5,inf=1e9+5;
typedef long long LL;
int n,m,k;
int dp[N][N],a[N][N],b[N];
int main(){
     int h,l,r;
    scanf("%d %d %d %d",&n,&h,&l,&r);
    rep(i,1,n+1) scanf("%d",&b[i]);
    a[0][0]=1;
    rep(i,1,n+1){
        rep(j,0,h){
            if(a[i-1][j]==0) continue;
            int k=(j+b[i]-1+h)%h;
            a[i][k]=1;
            int t=0;
            if(l<=k && k<=r) t=1;
            dp[i][k]=max(dp[i][k],t+dp[i-1][j]);
            k=(j+b[i])%h;
            a[i][k]=1;
            t=0;
            if(l<=k && k<=r) t+=1;
            dp[i][k]=max(dp[i][k],t+dp[i-1][j]);
        }
    }
    int ans=0;

    rep(j,0,h) {ans=max(dp[n][j],ans);}
    cout<<ans<<endl;
return 0;
}
