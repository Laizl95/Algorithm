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
int n,m,k;
int a[N],vis[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,1,n+1) vis[i]=0;
        int num=0,y;
        rep(i,0,n){
            scanf("%d",&k);
            int x,ok=0;
            rep(j,0,k){
                scanf("%d",&x);
                if(!ok && !vis[x]) ok=1,vis[x]=1;
            }
            num+=ok;
            if(ok==0) y=i;
        }
        if(num==n) puts("OPTIMAL");
        else{
           rep(i,1,n+1){
            if(!vis[i]){
                puts("IMPROVE");
                printf("%d %d\n",y+1,i);
                break;
            }
           }
        }
    }
return 0;
}
