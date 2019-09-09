#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=205,mod=1e9+7;

class Solution{
 public:
     Solution(){}
     Solution(int n){rep(i,0,n)rep(j,0,n) dp[i][j]=0;dp[0][0]=1;}
     int solve(string s){
       int len=s.length()+1;
        rep(i,0,len)rep(j,0,len) dp[i][j]=0,sum[i][j]=(i==0);
        dp[0][0]=1;
        rep(i,1,len)
            rep(j,0,i+1){
                if(s[i-1]=='D'){
                    //rep(k,j,i) dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                    if(j>0) dp[i][j]=(sum[i-1][i-1]-sum[i-1][j-1]+mod)%mod;
                    else dp[i][j]=sum[i-1][i-1]%mod;
                }
                else
                    //rep(k,0,j)dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                    if(j>0) dp[i][j]=sum[i-1][j-1]%mod;
                if(j>0) sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
                else sum[i][j]=dp[i][j];
            }
        int ans=0;
        //rep(i,0,len) rep(j,0,i+1){
        //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        //}
        rep(i,0,len) ans=(ans+dp[len-1][i])%mod;
        printf("%d\n",ans);
         //return ans;
     }
 private:
    int dp[N][N],sum[N][N];
};
int main(){
    string s;
    while(cin>>s){
      int len=s.length();
      Solution a(len);
      a.solve(s);
    }
return 0;
}
