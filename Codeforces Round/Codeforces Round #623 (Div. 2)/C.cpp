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
int a[N],vis[N],b[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,1,2*n+1) vis[i]=0;
        rep(i,1,n+1) scanf("%d",&a[i]),vis[a[i]]=1;
        rep(i,1,n+1) b[i*2-1]=a[i];
        int ok=1;
        rep(i,1,n+1){
            int x=b[i*2-1]+1;
            while(x<=2*n){if(!vis[x]) {vis[x]=1;break;}++x;}
            if(x>2*n) {ok=0;break;}
            b[i*2]=x;
        }
        if(ok) {rep(i,1,2*n+1) printf("%d ",b[i]);puts("");}
        else puts("-1");

    }
return 0;
}
