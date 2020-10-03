#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<long long,long long>
#define fi first
#define se second
using namespace std;
const int N=1e3+5,inf=1e6+5,mod=1000000007;
typedef long long LL;
char a[N],b[N];
int dp[N][N];
int main(){
    scanf("%s %s",a+1,b+1);
    a[0]='1';b[0]='1';
    int len1=strlen(a+1),len2=strlen(b+1);
    dp[0][0]=1;
    //rep(i,1,len2+1) dp[0][i]=1;
    //rep(i,1,len1+1) dp[i][0]=1;
    rep(i,0,len1+1){
        rep(j,0,len2+1){
            if(b[j]!='*'){
                if(b[j]==a[i] || b[j]=='.')
                    if(i && j) dp[i][j]=dp[i-1][j-1];
            }else{
                if(j && b[j-1]!=a[i] && b[j-1]!='.'){
                    if(j>=2) dp[i][j]=dp[i][j-2];
                    //else dp[i][j]=0;
                }else{
                    if(j>=2) dp[i][j]=dp[i][j-2];
                    if(j) dp[i][j]|=dp[i][j-1];
                    if(i) dp[i][j]|=dp[i-1][j];
                }
            }
        }
    }
    bool ans=dp[len1][len2]==1;
    cout<<ans<<endl;
return 0;
}
