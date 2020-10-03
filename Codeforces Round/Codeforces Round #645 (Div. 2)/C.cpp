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
    int t,x1,x2,y1,y2;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
       printf("%lld\n",(x2-x1)*1LL*(y2-y1)+1);

    }

return 0;
}
