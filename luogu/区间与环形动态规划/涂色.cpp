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
const int N=55,inf=1e6+5,mod=19650827;
typedef long long LL;
char s[N];
int dp[N][N];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    rep(i,1,n+1) rep(j,i,n+1) dp[i][j]=inf;
    //隔开来讨论不一定有最优值 ABCDADCBA
    rep(len,1,n+1){
        rep(i,1,n+1){
            if(len==1){dp[i][i]=1;continue;}
            int j=i+len-1;
            if(j>n) break;
            if(s[i]==s[j]){
                dp[i][j]=min(min(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1]+1);
            }
            else{
                rep(k,i,j){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<dp[1][n]<<endl;
return 0;
}
