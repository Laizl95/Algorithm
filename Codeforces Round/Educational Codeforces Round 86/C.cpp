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

int main(){
    int t,a,b,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&q);
        if(a>b) swap(a,b);
        int lcm=a*b/__gcd(a,b);
        vector<int> v;
        rep(i,0,lcm) if(i%a%b==i%b%a) v.pb(i);
        //for(auto x:v) printf("%d ",x);
        LL l,r;
        while(q--){
            scanf("%lld %lld",&l,&r);
            LL ans=0;
            for(auto x:v){
                if(x>=l && x<=r) ans+=1;
                ans+=(r-x)/lcm-(l-1-x)/lcm;
            }
            printf("%lld ",r-l+1-ans);
        }
        cout<<endl;
    }
return 0;
}
