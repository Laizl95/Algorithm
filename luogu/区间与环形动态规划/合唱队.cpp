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
const int N=1005,inf=1e6+5,mod=19650827;
typedef long long LL;
int n;
int a[N],dp[N][N][2];// 0:最后一个进入的第i个人的方案数 1:最后一个进入的第j个的方案数
int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(len,1,n+1){

        rep(i,1,n+1){
            if(len==1) {dp[i][i][1]=1;continue;}
            int j=i+len-1;
            if(j>n) break;
            if(a[i]<a[j]) dp[i][j][0]=(dp[i][j][0]+dp[i+1][j][1])%mod;
            if(a[i]<a[i+1]) dp[i][j][0]=(dp[i][j][0]+dp[i+1][j][0])%mod;
            if(a[j]>a[i]) dp[i][j][1]=(dp[i][j-1][0]+dp[i][j][1])%mod;
            if(a[j]>a[j-1]) dp[i][j][1]=(dp[i][j-1][1]+dp[i][j][1])%mod;
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%mod<<endl;
return 0;
}
