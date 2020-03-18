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
int a[N],b[N];
int main(){
    int t;
    scanf("%d",&n);
    int tot=0,num=0;
    rep(i,0,n) scanf("%d",&a[i]);
    rep(i,0,n){
        scanf("%d",&b[i]);
        num+=b[i];
        if(a[i] && b[i]) a[i]=0,++tot;
    }
    int cnt=0,x=num-tot+1;
    rep(i,0,n) cnt+=a[i];
    if(x<0) puts("1");
    else{
        if(cnt==0) puts("-1");
        else cout<<max(1,x/cnt+(x%cnt!=0))<<endl;
    }
return 0;
}
