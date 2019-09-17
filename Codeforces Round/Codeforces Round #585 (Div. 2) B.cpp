#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=200005;

int a[N];
int sum1[N],sum2[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        long long ans=0;
        rep(i,0,n+1) sum1[i]=sum2[i]=0;
        rep(i,1,n+1){
            scanf("%d",&a[i]);
            if(a[i]<0) sum2[i]=sum1[i-1]+1,sum1[i]=sum2[i-1];
            else sum1[i]=sum1[i-1]+1,sum2[i]=sum2[i-1];
        }
        long long ans1=0,ans2=0;
        rep(i,1,n+1) ans1+=sum1[i],ans2+=sum2[i];
        printf("%I64d %I64d\n",ans2,ans1);
    }
return 0;
}
