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

int n,m;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int ans=0,x;
        scanf("%d",&x);
        ans+=x;
        rep(i,1,n){
            scanf("%d",&x);
            int day=i*x;
            if(day<=m) ans+=x,m-=day;
            else ans+=m/i,m=0;
        }
        cout<<ans<<endl;
    }
return 0;
}
