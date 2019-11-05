#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005,inf=1e9+5;
typedef long long LL;
int a[N],dp[N];
int main(){
    int n,m,d;
    while(scanf("%d %d %d",&n,&m,&d)!=EOF){
        rep(i,0,m) scanf("%d",&a[i]);
        ms(dp,0);
        int k=0;
        rep(i,0,m){
            dp[k+d]=i+1;
            rep(j,0,a[i]){
                dp[k+d+j]=i+1;
            }
            k=k+d+a[i]-1;
        }
        //1cout<<k<<endl;
        if(k+d>=n+1){
            printf("YES\n");
            int maxx=0,pos;
            rep(i,1,n+1) if(dp[i]>maxx) maxx=dp[i],pos=i;
            while(maxx<=m){
                dp[pos+d]=maxx;

                maxx+=1;
            }
            rep(i,1,n+1) printf("%d ",dp[i]);
            puts("");
        }else printf("NO\n");
    }
}
