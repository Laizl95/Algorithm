#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5;
typedef long long LL;
int a[N],num[N];
int main(){
    int n,x;
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&x);
        num[x]+=1;
    }

    rep(i,1,150001){
        if(i>1 && num[i]>0 && num[i-1]+a[i-1]<=0) a[i-1]+=1,num[i]-=1;
        if((a[i]>0 && num[i]>0) || num[i]>1)
            a[i+1]+=1,num[i]-=1;
    }

    int ans=0; if(num[0]+a[0]>0) a[1]+=1;
     rep(i,1,150002) if(a[i]+num[i]>0) ans+=1;
     printf("%d\n",ans);
return 0;
}
