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
    LL n,p,w,d;
    scanf("%lld %lld %lld %lld",&n,&p,&w,&d);
    rep(i,0,w+1){
        if(i*d<=p && (p-i*d)%w==0 && i+(p-i*d)/w<=n ){
            printf("%lld %d %lld",(p-i*d)/w,i,n-(p-i*d)/w-i);
            return 0;
        }
    }
    cout<<"-1"<<endl;
return 0;
}
