#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5,mod=1e9+7;
typedef long long LL;

int n,m;
char s[N];
LL dp[N][2];
int main(){
    int t;
    scanf("%s",s+1);
    int len=strlen(s+1),p=1,ok=0;;
    LL ans=1;
    while(p<=len){
        if(s[p]=='u' || s[p]=='n'){
            int tmp=0,l=p;char c=s[p];

            while(p<=len && s[p]==c){
                if(p==l){
                    dp[p][0]=1;dp[p][1]=0;
                    dp[p-1][0]=1;dp[p-1][1]=0;}
                else{
                    dp[p][0]=(dp[p-1][0]+dp[p-1][1])%mod;
                    dp[p][1]=(dp[p-2][0]+dp[p-2][1])%mod;
                }
                //cout<<dp[p][0]<<" "<<dp[p][1]<<endl;
                ++p;
            }
            ans=(ans*(dp[p-1][0]+dp[p-1][1])%mod)%mod;
        }else{
            if(s[p]=='w' || s[p]=='m') ok=1;
            ++p;
        }
    }
        if(!ok) cout<<ans<<endl;
        else cout<<0<<endl;
return 0;
}
