#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;
int a[N];
int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",&a[i]);
    LL ans=0;
    int pre=0;
    rep(i,0,n){
        ans+=a[i]/2;
        if((a[i]&1) && pre) ans+=1,pre=0;
        else pre=(a[i]&1);
    }
    cout<<ans<<endl;
return 0;
}
