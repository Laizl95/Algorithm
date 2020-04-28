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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int dp[15][15];//n个球放到m个不同的盒子方法数
int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    dp[0][0]=1;

    rep(i,1,n+1){
        rep(j,1,r+1){
            dp[i][j]=j*dp[i-1][j]+j*dp[i-1][j-1];
        }
    }
    printf("%d\n",dp[n][r]);
return 0;
}
