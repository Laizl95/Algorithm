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
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        rep(i,0,n) scanf("%d",&a[i+1]);
        sort(a+1,a+1+n);
        int num=unique(a+1,a+n+1)-a-1;
        int ans=m;
        rep(i,1,num+1){
            int y=m+i-1;
            //cout<<y<<" "<<a[i]<<endl;
            if(y<a[i]-1) break;
            if(y>=a[i]) y+=1;
            ans=max(ans,max(y,a[i]));
        }
        cout<<ans<<endl;
    }
return 0;
}
