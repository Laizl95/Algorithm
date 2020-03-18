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
        scanf("%d",&n);
        map<int,LL> mp;
        rep(i,1,n+1){
            scanf("%d",&a[i]);
            mp[a[i]-i]+=a[i];
        }
        int l=-4e5+5,r=4e5+5;
        LL ans=-1;
        rep(i,l,r+1){
            //if(mp.count(i)==0) continue;
            ans=max(mp[i],ans);
        }
        cout<<ans<<endl;

return 0;
}
