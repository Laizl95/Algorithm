#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
typedef long long LL;
using namespace std;
int a[25];
int main(){
int n,cas=0;
while(scanf("%d",&n)!=EOF){
    //if(cas) puts("");
    rep(i,1,n) scanf("%d",&a[i]);
    int t=1;LL ans=0;
    rep(l,1,n){
     rep(r,l,n){
       LL num=1;
       rep(k,l,r) num*=a[k];
       ans=max(ans,num);
     }
    }
    printf("Case #%d: The maximum product is %lld.\n\n",++cas,ans);
}
return 0;
}
