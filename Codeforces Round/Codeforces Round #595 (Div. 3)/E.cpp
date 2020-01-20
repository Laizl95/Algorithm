#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5;
typedef long long LL;

int a[N],b[N],dp[N][2];
int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) scanf("%d",&b[i]);
    dp[1][1]=c;
    rep(i,2,n+1){
        dp[i][1]=min(dp[i-1][1]+b[i-1],dp[i-1][0]+c+b[i-1]);
        dp[i][0]=min(dp[i-1][1]+a[i-1],dp[i-1][0]+a[i-1]);
    }
    rep(i,1,n+1) printf("%d ",min(dp[i][0],dp[i][1]));
    puts("");
return 0;
}
