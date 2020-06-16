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
const int N=1e3+5,inf=1e6+5,mod=998244353;
typedef long long LL;
char s1[N],s2[N];
int dp[N][N][N][N];

int main(){
    scanf("%s %s",s1,s2);
    int len=strlen(s1);
    cout<<solve(0,len-1)<<endl;
return 0;
}
