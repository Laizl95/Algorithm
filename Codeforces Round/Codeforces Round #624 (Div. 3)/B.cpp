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
int b[N];
struct node{
    int x,p;
}a[N];
bool cmp(const node &a,const node &b){
    return a.x<b.x || (a.x==b.x && a.p<b.p);
}
int main(){
    int t,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        rep(i,1,n+1) scanf("%d",&a[i].x),a[i].p=i;
        sort(a+1,a+1+n,cmp);
        rep(i,1,n+1) b[i]=0;
        int x;
        rep(i,1,m+1) scanf("%d",&x),b[x]=1;
        int ok=1;
        rep(i,1,n+1){
            int p=a[i].p;
            rep(j,i,p)
                if(!b[j]) ok=0;
        }
        puts(ok?"YES":"NO");
    }
return 0;
}
