#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005,mod=1e9+7;
//())(())(()(((((())()())()())()((()(((()()))())(((()()(((())())))()()))))(()))))))(((((((())))(())(())(()()((()))))))()((())))))(())))))(
//char s[N];
//(()())
string s;
int dp[N];
int main(){
    while(cin>>s){
        int len=s.length();
        //int len=strlen(s);
        rep(i,0,len) dp[i]=0;
        rep(i,0,len){
            if(i>0 && s[i]==')' && s[i-1]=='('){
                if(i>1) dp[i]=dp[i-2]+2;
                else dp[i]=2;
            }
            if(i>0 && s[i]==')' && s[i-1]==')' && i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                dp[i]=dp[i-1]+dp[max(i-dp[i-1]-2,0)]+2;
        }
        int ans=0;
        rep(i,0,len) cout<<dp[i]<<endl;
        rep(i,0,len) ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
return 0;
}
