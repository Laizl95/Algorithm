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
int dp[405][405];
string s;
int judge(string x,string y){
    int tot=0;
    rep(i,0,x.length())
        if(x[i]==y[tot]){
            ++tot;
            if(tot==y.length()) return 1;
        }
    return 0;
}
int solve(string a,string b){
    ms(dp,-1);
    dp[0][0]=0;
    rep(i,0,s.length()){
        rep(j,0,a.length()){
             if(dp[i][j]==-1) continue;
            if(s[i]==a[j]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
        }
        rep(j,0,a.length()+1){
            if(dp[i][j]==-1) continue;
            if(s[i]==b[dp[i][j]]) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        }
       //rep(j,0,a.length()+1) cout<<dp[i+1][j]<<" ";cout<<endl;
    }
    return dp[s.length()][a.length()]==b.length();
}
int main(){
    int t;string a;
    scanf("%d",&t);
    while(t--){
        cin>>s>>a;
        if(judge(s,a)){
            cout<<"YES"<<endl;
            continue;
        }
        int ok=0;
        rep(i,1,a.length()){
            string c=a.substr(0,i),d=a.substr(i,a.length()-i);
            //cout<<c<<" "<<d<<endl;
            if(solve(c,d)){ok=1;break;}
        }
        puts(ok?"YES":"NO");
    }
return 0;
}
