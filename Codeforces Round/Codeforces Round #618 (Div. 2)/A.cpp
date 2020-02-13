#pragma GCC optimize(2)
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
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int cnt=0,tot=0;
        rep(i,0,n) scanf("%d",&a[i]),cnt+=a[i];
        rep(i,0,n){
            if(a[i]==0) ++tot;
        }
        if(cnt!=0 && tot==0) puts("0");
        else{
            int ans=cnt+tot;
            if(ans==0) printf("%d\n",tot+1);
            else printf("%d\n",tot);
        }

    }
return 0;
}
