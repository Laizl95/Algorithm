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
        rep(i,0,n) scanf("%d",&a[i]);
        int ans=1e9;
        sort(a,a+n);
        rep(i,0,n){
            if(m%a[i]==0 && m/a[i]==1) ans=1;
            else{
                ans=min(ans,max((m+a[i]-1)/a[i],2));
            }
        }
        cout<<ans<<endl;
    }
return 0;
}
