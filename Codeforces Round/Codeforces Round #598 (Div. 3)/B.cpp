#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105,inf=1e9+5;
typedef long long LL;
int a[N],vis[N];

int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);
        ms(vis,0);
        int tot=1;
        while(tot<=1000){
            per(i,0,n){
             if(i>0 && a[i]<a[i-1] && !vis[i]) vis[i]=1,swap(a[i],a[i-1]);
            }
            tot+=1;
        }
        rep(i,0,n) printf("%d ",a[i]);puts("");

    }
return 0;
}
