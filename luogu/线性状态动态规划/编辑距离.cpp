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
const int N=2e3+5,inf=1e6+5,mod=998244353;
typedef long long LL;
int dp[N][N];
char s1[N],s2[N];

int main(){
    scanf("%s %s",s1+1,s2+1);
    int len1=strlen(s1+1),len2=strlen(s2+1);
    //insert dp[i][j-1]+1 delete dp[i-1][j]+1
    rep(i,1,len2+1) dp[0][i]=i;
    rep(i,1,len1+1) dp[i][0]=i;
    rep(i,1,len1+1){
        rep(j,1,len2+1){
            if(s2[j]==s1[i]) dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            }
        }
    }
    cout<<dp[len1][len2]<<endl;
return 0;
}
