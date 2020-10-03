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
const int N=1e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d",&n,&m);
       int x1=m/2,x2=m%2;
       int ans1=x1*n+x2*(n+1)/2;
       x1=n/2;x2=n%2;
       int ans2=x1*m+x2*(m+1)/2;
       cout<<min(ans1,ans2)<<endl;
    }
return 0;
}
