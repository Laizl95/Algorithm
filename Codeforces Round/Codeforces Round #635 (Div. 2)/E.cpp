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
const int N=3e3+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m,k;
int dp[N][N];//s构成t串的子串t[i-j]的方法数
char s[N],t[N];

int main(){
    scanf("%s %s",s,t);
    int lent=strlen(t),lens=strlen(s);
    rep(len,1,lens+1){
        int i=len-1;
        rep(l,0,lens){
            int r=l+len-1;
            if(r>=lens) break;
            //cout<<s[i]<<" "<<t[l]<<endl;
            //cout<<l<<" "<<lent<<endl;
            if(l==r && (s[i]==t[l] || l>=lent || r>=lent )){
                dp[l][r]=(dp[l][r]+1)%mod;
                continue;
            }
            if(l>=lent || s[i]==t[l]) dp[l][r]=(dp[l][r]+dp[l+1][r])%mod;
            if(r>=lent || s[i]==t[r]) dp[l][r]=(dp[l][r]+dp[l][r-1])%mod;
        }
    }
    LL ans=0;
    rep(i,lent-1,lens) ans=(ans+dp[0][i])%mod;
    cout<<ans*2%mod<<endl;
return 0;
}
