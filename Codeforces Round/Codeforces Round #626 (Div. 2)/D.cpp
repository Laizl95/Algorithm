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
const int N=4e5+5,inf=1e9+5;
typedef long long LL;
//2个数和的异或
int n;
int a[N],b[N];
int solve(int i,int x,int y){
     int l=lower_bound(b+i+1,b+n,x)-b;
     int r=lower_bound(b+i+1,b+n,y)-b;
     return r-l;
}
int main(){
     //cout<<(1<<25)<<endl;
     //cout<<(1<<24)<<endl;
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",&a[i]);
    LL ans=0;
    rep(i,1,26){
        rep(j,0,n) b[j]=a[j]%(1<<i);
        sort(b,b+n);
        int num=0;
        rep(j,0,n){
            int l1=1<<(i-1),r1=1<<i,l2=(1<<i)+(1<<(i-1)),r2=(1<<(i+1))-1;
            num+=solve(j,l1-b[j],r1-b[j]);
            num+=solve(j,l2-b[j],r2-b[j]);
        }
        if(num&1) ans+=1<<(i-1);
    }
    cout<<ans<<endl;
return 0;
}
