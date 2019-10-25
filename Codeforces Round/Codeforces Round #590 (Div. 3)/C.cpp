#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define lson l,mid,i<<1
#define rson mid+1,r,i<<1|1
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
//16
char s[2][N];
int dp[2][N][4];
//up:0 down:1 l:2 r:3
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,2) rep(j,0,4) rep(k,0,n+1) dp[i][k][j]=0;
        dp[0][0][3]=1;
        scanf("%s %s",s[0]+1,s[1]+1);
        rep(j,1,n+1){
            rep(i,0,2){
               if(s[i][j]=='1' || s[i][j]=='2'){
                    if(j-1>=0 && dp[i][j-1][3]==1) dp[i][j][3]=1;
               }else{
                   if(j-1>=0 && dp[i][j-1][3]==1) dp[i][j][0]=1,dp[i][j][1]=1;
               }
            }
            if(s[1][j]>='3' && dp[0][j][1]==1) dp[1][j][3]=1;
            if(s[0][j]>='3' && dp[1][j][0]==1) dp[0][j][3]=1;
        }
            puts(dp[1][n][3]==1?"YES":"NO");
           // cout<<dp[1][n][3]<<endl;
    }
return 0;
}
