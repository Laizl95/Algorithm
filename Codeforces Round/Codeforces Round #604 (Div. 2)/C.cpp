#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=4e5+5,inf=1e9+5,M=1e6+5;
typedef long long LL;

int a[N],sum[N],vis[M];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int x,cnt=0;
        rep(i,1,n+1) sum[i]=0;
        rep(i,0,n){
            scanf("%d",&x);
            a[i]=x;
            if(!vis[x]) vis[x]=++cnt;
            sum[vis[x]]+=1;
        }
        //rep(i,1,cnt+1) printf("%d ",sum[i]);puts("");
        rep(i,1,cnt+1){
            sum[i]+=sum[i-1];
            if(sum[i]>n/2) {cnt=i-1;break;}
        }
        int g=0,s=0,b=0;
        rep(i,1,cnt+1){
            int l=i+1,r=cnt,num=sum[i];
            if(sum[i]*3>=n/2) break;
            while(l<=r){
                int mid=l+r>>1;
                if(sum[mid]<=2*sum[i]) l=mid+1;
                else r=mid-1;
            }
            int x1=sum[i],x2=sum[l]-x1,x3=sum[cnt]-sum[l];
            if(l>=cnt || x3==0 || x1>=x2 || x1>=x3) continue;
            if(x1+x2+x3>g+s+b){
                g=x1;s=x2;b=x3;
            }
        }
         printf("%d %d %d\n",g,s,b);
         rep(i,0,n) vis[a[i]]=0;
    }
return 0;
}
