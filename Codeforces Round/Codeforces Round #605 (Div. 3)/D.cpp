#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int a[N],l[N],r[N];
int main(){
    //...a,b<=c,d... 1.delete b 2.delete c
    int n;
    scanf("%d",&n);
    l[0]=1;
    rep(i,0,n){
        scanf("%d",&a[i]);
        if(i>0 && a[i]>a[i-1]) l[i]=l[i-1]+1;
        else if(i>0 && a[i]<=a[i-1]) l[i]=1;

    }
    r[n-1]=1;
    per(i,0,n){
        if(i<n-1 && a[i]<a[i+1]) r[i]=r[i+1]+1;
        else if(i<n-1 && a[i]>=a[i+1]) r[i]=1;
    }
    int ans=1;
    rep(i,0,n) ans=max(max(ans,l[i]),r[i]);

    rep(i,0,n){
        if(i>0 && a[i-1]<a[i+1]) ans=max(ans,l[i-1]+r[i+1]);
        if(i+2<n && a[i]<a[i+2]) ans=max(ans,l[i]+r[i+2]);
    }
        printf("%d\n",ans);
return 0;
}
