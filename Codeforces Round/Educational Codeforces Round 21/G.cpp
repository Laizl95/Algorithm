#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define pdi pair<double,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int dp[2][N];//dp[N][N];前缀函数为j匹配到第i个字符时最大出现次数
int pi[N],aut[N][30];//前缀函数为j时匹配当前字符的前缀函数
char s[N],t[N];
//dp[i+1][pi[aut[j][t[i]]-1]]=max(dp[i+1][pi[aut[j][t[i]]]],dp[i][j]+1)   aut[j][t[i]]>=len2
//dp[i+1][aut[j][t[i]]]=max(dp[i+1][aut[j][t[i]]],dp[i][j])
void prefixFunction(int len){
    pi[0]=0;
    rep(i,1,len){
        int j=pi[i-1];
        while(j>0 && s[j]!=s[i]) j=pi[j-1];
        if(s[i]==s[j]) ++j;
        pi[i]=j;
    }
}
int main(){
    scanf("%s %s",t,s);
    int lent=strlen(t),lens=strlen(s);
    prefixFunction(lens);
    rep(c,0,26) aut[0][c]=(s[0]==c+'a');
    rep(i,1,lens){
        rep(c,0,26){
            /*int j=i;
            while(j>0 && s[j]!=c+'a') j=pi[j-1];
            if(s[j]==c+'a') ++j;
            aut[i][c]=j;*/  //aaaaaaaaaaaaaa z 退化为 n^2
            if('a'+c!=s[i]) aut[i][c]=aut[pi[i-1]][c];
            else aut[i][c]=i+1;
        }
    }
    rep(j,0,lens) dp[0][j]=-1;
    dp[0][0]=0;
    int k=0;
    rep(i,0,lent){
        rep(j,0,lens) dp[k^1][j]=-1;
        rep(j,0,lens){
            if(dp[k][j]==-1) continue;
            rep(c,0,26){
                if(t[i]!='?' && t[i]!=c+'a') continue;
                int p=aut[j][c];
                if(p==lens) dp[k^1][pi[p-1]]=max(dp[k^1][pi[p-1]],dp[k][j]+1);
                else dp[k^1][p]=max(dp[k^1][p],dp[k][j]);
            }
        }
        k^=1;
    }
    int ans=0;
    rep(i,0,lens)  ans=max(ans,dp[k][i]);
    cout<<ans<<endl;
    return 0;
}