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
char _s[N];
LL dp[N];
int main(){
    scanf("%s",_s+1);
    int len=strlen(_s+1);
    dp[0]=1;
    rep(i,1,len+1){
        if(_s[i]!='0'){
            if(_s[i]=='*') dp[i]=(dp[i]+dp[i-1]*9)%mod;
            else dp[i]=(dp[i]+dp[i-1])%mod;
        }
        if(i-2>=0){
            if(_s[i]=='*'){
                if(_s[i-1]=='1') dp[i]=(dp[i]+dp[i-2]*9)%mod;
                if(_s[i-1]=='2') dp[i]=(dp[i]+dp[i-2]*6)%mod;
                if(_s[i-1]=='*') dp[i]=(dp[i]+dp[i-2]*15)%mod;
            }else{
                if(_s[i-1]!='0' && _s[i-1]!='*' && (_s[i-1]-'0')*10+(_s[i]-'0')<=26){
                    dp[i]=(dp[i]+dp[i-2])%mod;
                }
                if(_s[i-1]=='*') {
                       if(_s[i]<='6') dp[i]=(dp[i]+dp[i-2]*2)%mod;
                       else dp[i]=(dp[i]+dp[i-2])%mod;
                }


            }

        }
        //cout<<dp[i]<<endl;
    }
    cout<<dp[len]<<endl;
return 0;
}
