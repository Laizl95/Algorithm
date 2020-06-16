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
const int N=1e3+5,inf=1e6+5,mod=1000000007;
typedef long long LL;
char s[N],p[N];
int dp[N][N];
int main(){
    scanf("%s %s",s+1,p+1);
    int len1=strlen(s+1),len2=strlen(p+1);
    dp[0][0]=1;
    rep(i,1,len2+1){
        dp[0][i]=dp[0][i-1]&(p[i]=='*');
    }
    rep(i,1,len1+1) dp[i][0]=0;
    rep(i,1,len1+1){
        rep(j,1,len2+1){
            if(s[i]==p[j]) dp[i][j]|=dp[i-1][j-1];
            if(p[j]=='*'){
                dp[i][j]|=dp[i][j-1];
                dp[i][j]|=dp[i-1][j-1];
                dp[i][j]|=dp[i-1][j];
            }
            if(p[j]=='?'){
               // dp[i][j]|=dp[i][j-1];
                dp[i][j]|=dp[i-1][j-1];

            }
        }
    }

    cout<<dp[len1][len2]<<endl;
return 0;
}
