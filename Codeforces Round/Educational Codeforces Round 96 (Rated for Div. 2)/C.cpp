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
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int a[N];
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<pii> v;
        int now=n,p=n-1;
        while(p>0){
            v.pb(mp(now,p));
            //cout<<now<<" "<<p<<endl;
            if((now+p)%2==0)
            now=(now+p)/2;
            else  now=(now+p)/2+1;
            p--;
        }
        cout<<now<<endl;
        for(auto &x:v) printf("%d %d\n",x.fi,x.se);
    }
return 0;
}
