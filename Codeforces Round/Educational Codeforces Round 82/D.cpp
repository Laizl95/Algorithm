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
struct cmp{
    bool operator()(const LL &a,const LL &b){
        return a<b;
    }
};
int main(){
    int t,m;
    LL n;
    scanf("%d",&t);
    multiset<LL>::iterator it;
    while(t--){
        scanf("%lld %d",&n,&m);
        multiset<LL,cmp> s;
        LL x;
        rep(i,0,m){
            scanf("%lld",&x);
            s.insert(x);
        }
        vector<LL> bit;
        int k=0;
        while(n){
            if(n&1) bit.pb(1LL<<k);
            ++k;
            n>>=1;
        }
        //for(auto it:bit) printf("%lld ",it);puts("");
        LL ans=0;int p=0;
    while(p<bit.size() && s.size()>0){
        x=*s.begin();
        n=bit[p];
        //cout<<n<<" "<<x<<endl;
        if(x<n){
                int r=0;
            for(it=s.begin();it!=s.end();){
                if(*it!=x){
                    break;
                }
                else ++it,++r;
            }
            rep(i,0,r/2) s.insert(x*2);
            s.erase(x);
        }else{
            int len=0,p1=0,now=bit.size();
            LL y=x;
            while(n) n>>=1,++p1;
            while(x) x>>=1,++len;
            ans+=len-p1;
            rep(i,p+1,bit.size()) if(bit[i]>=y){
                now=i;
                break;
            }
            p=now;
            s.erase(s.begin());
        }
    }
    if(p==bit.size())  printf("%lld\n",ans);
    else puts("-1");
    }
return 0;
}
