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
int a[N];
int n;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       rep(i,0,n) scanf("%d",&a[i]);
       sort(a,a+n);
       int ans=1,now=1,need=inf;
       rep(i,0,n){
           a[i]-=i+1;
           if(a[i]<=0) ans=i+2;
        }

       cout<<ans<<endl;
    }
return 0;
}
