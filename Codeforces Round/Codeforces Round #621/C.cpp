#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
char s[N];
int num[N][35];
LL dp[35][35];

int main(){
    scanf("%s",s);
    int len=strlen(s),tot=1;
    LL ans=0;
    rep(i,0,len){
        rep(j,0,26)
            if(i>0) num[i][j]+=num[i-1][j];
        num[i][s[i]-'a']+=1;
    }
    rep(i,0,26) ans=max(ans,1LL*num[len-1][i]);
    rep(i,0,len){
        rep(j,0,26){
            if(num[len-1][j]==0) continue;
            dp[s[i]-'a'][j]+=num[len-1][j]-num[i][j];
        }
    }
    rep(i,0,26) rep(j,0,26) ans=max(ans,dp[i][j]);
    printf("%lld\n",ans);
return 0;
}
