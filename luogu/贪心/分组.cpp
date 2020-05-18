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
const int N=2e5+5,inf=1e6+5;
typedef long long LL;
int n,m;
int a[N],cnt[N],c[N];

int main(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",&a[i]);
    sort(a,a+n);
    m=0;cnt[0]=1;c[0]=a[0];
    rep(i,1,n){
        int l=0,r=m;
        while(l<=r){
            int mid=(l+r)>>1;
            if(c[mid]+1>a[i]) r=mid-1;
            else l=mid+1;
        }
        if(r<0) c[++m]=a[i],cnt[m]=1;
        else{
            if(c[r]+1==a[i]) cnt[r]+=1,c[r]=a[i];
            else cnt[++m]=1,c[m]=a[i];
        }
    }
    //rep(i,0,m+1) cout<<cnt[i]<<endl;
    int ans=n+1;
    rep(i,0,m+1) ans=min(ans,cnt[i]);
    cout<<ans<<endl;
return 0;
}
