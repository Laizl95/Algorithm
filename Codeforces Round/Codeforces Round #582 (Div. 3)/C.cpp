#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=150005;
typedef long long LL;
int a[10],b[10];
int judge(){
    rep(i,0,10) if(a[i]>1) return 1;
    return 0;
}
int main(){
    int t;LL n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&m);
        ms(a,0);
        long long q=n/m;int x=0,tot=0;
        m%=10;
        while(!judge()){
            x+=m;
            a[x%10]+=1;
            if(!judge()) b[tot++]=x%10;
        }
        long long z=q/tot;int y=q%tot,z_sum=0;
        rep(i,0,10) if(a[i]>=1) z_sum+=i;
        long long sum=z_sum*1LL*z;
        rep(i,0,y) sum+=b[i];
        printf("%lld\n",sum);
    }
return 0;
}
