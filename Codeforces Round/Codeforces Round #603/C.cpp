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


int a[N];
int main(){
    int t;
    scanf("%d",&t);
    LL n;
    while(t--){
        scanf("%lld",&n);
        vector<int> v;
        for(int i=1;i*1LL*i<=n;++i){
            int x=n/i;
            if(n/x==i){
                if(x!=i) v.pb(x),v.pb(i);
                else v.pb(i);
            }
        }
        v.pb(0);
        sort(v.begin(),v.end());
        cout<<v.size()<<endl;
        for(auto it:v) printf("%d ",it);puts("");

    }
return 0;
}
