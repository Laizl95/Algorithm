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
            int ok=0;
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);
        rep(i,0,n){
            if(vis[a[i]] && vis[a[i]]+1<i+1) ok=1;
            if(!vis[a[i]]) vis[a[i]]=i+1;
        }
        puts(ok?"YES":"NO");
       rep(i,0,n) vis[a[i]]=0;
    }
return 0;
}
