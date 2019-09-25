#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
//19:26
int a[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,0,n) scanf("%d",&a[i]);
        int ans=-1;
        rep(i,0,n){
            int cost=0;
            rep(j,0,n) cost+=abs(a[j]-a[i])%2;
            if(ans==-1 || cost<ans) ans=cost;
        }
        printf("%d\n",ans);
    }
return 0;
}
