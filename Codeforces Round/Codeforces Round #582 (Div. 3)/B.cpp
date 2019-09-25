#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=150005;
int a[N];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);
        int minx=a[n-1],ans=0;
        per(i,0,n) {if(a[i]>minx) ans+=1;minx=min(minx,a[i]);}
        printf("%d\n",ans);
    }
return 0;
}
