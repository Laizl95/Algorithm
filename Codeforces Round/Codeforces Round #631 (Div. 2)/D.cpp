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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
LL dp[N];
int main(){
    int t,d,m;
    //cout<<(1<<30)<<endl;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&d,&m);

        rep(i,0,30){
            int r=min(1<<(i+1),d+1),l=1<<i;
            int num=r-l;
            if(num<0) num=0;
            ++num;
            if(i>0) dp[i]=dp[i-1]*num%m;
            else dp[i]=num*1LL;
        }
        cout<<((dp[29]-1)%m+m)%m<<endl;
    }
return 0;
}
