#pragma GCC optimize(2)
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
LL n,a,b,k;
LL c[N],num[N];
int main(){
    int t;
    scanf("%lld %lld %lld %lld",&n,&a,&b,&k);
    rep(i,1,n+1) scanf("%lld",&c[i]);
    rep(i,1,n+1){
        LL x=c[i]/(a+b),y=c[i]%(a+b);
        if(y==0){
            y=b;
            LL q=y/a;
            if(y%a!=0) q+=1;
            num[i]=q;
        }
        else{
           y-=a;
           if(y<=0) num[i]=0;
           else{
            LL q=y/a;
            if(y%a!=0) q+=1;
            num[i]=q;
           }
        }
        //cout<<"jj "<<num[i]<<endl;
    }
    sort(num+1,num+n+1);
    int ans=0;
    rep(i,1,n+1){
        if(k>=num[i]){
            ans+=1;
            k-=num[i];
        }else break;
    }
    printf("%d\n",ans);
return 0;
}
