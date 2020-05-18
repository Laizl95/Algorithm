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
const int N=2e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m,k;


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y,a,b;
        scanf("%d %d %d %d",&x,&y,&a,&b);
        LL ans1=min(x,y)*1LL*b+(max(x,y)-min(x,y))*1LL*a,ans2=x*1LL*a+y*1LL*a;
        //cout<<ans1<<" "<<ans2<<endl;
        cout<<min(ans1,ans2)<<endl;
    }
return 0;
}
