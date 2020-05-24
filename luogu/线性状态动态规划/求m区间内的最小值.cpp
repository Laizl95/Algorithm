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
const int N=2e6+5,inf=1e6+5;
typedef long long LL;
//单调队列维护
int a[N],q[N];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    rep(i,1,n+1) scanf("%d",&a[i]);
    int head=1,tail=0;
    rep(i,1,n+1){
        while(i-q[head]>m && head<=tail) ++head;
        printf("%d\n",a[q[head]]);
        while(a[i]<a[q[tail]] && head<=tail) --tail;
        q[++tail]=i;
    }
return 0;
}
