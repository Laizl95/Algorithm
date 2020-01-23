#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=3e4+5;
typedef long long LL;
int dp[105][N];
struct node{
    int x,y;
}a[N];
int main(){
        int n,m;
        scanf("%d %d",&n,&m);
        dp[0][n]=1;
        rep(i,0,n){
            scanf("%d %d",&a[i].x,&a[i].y);

        }
        rep(i,1,n+1){
            rep(j,0,30301){
                if(dp[i-1][j]!=1) continue;
                rep(k,1,n+1){
                    if(a[k].x<=j && j+a[k].y>=0) dp[i][j+a[k].y]=1;
                }
            }
        }int ok=0;
        rep(j,0,30301) if(dp[n][j]==1) ok=1;
        puts(ok?"YES":"NO");
return 0;
}
