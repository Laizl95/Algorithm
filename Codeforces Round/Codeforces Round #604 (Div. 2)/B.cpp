#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int pos[N];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int x;
        rep(i,0,n) {
            scanf("%d",&x);
            pos[x]=i+1;
        }
        int l=n+1,r=-1;
        rep(i,1,n+1){
           l=min(pos[i],l);
           r=max(pos[i],r);
           if(r-l+1==i) printf("1");
           else printf("0");
        }
        puts("");
    }
}
