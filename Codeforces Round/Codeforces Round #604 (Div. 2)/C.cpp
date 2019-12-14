#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=4e5+5,inf=1e9+5;
typedef long long LL;

int a[N],sum[N];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n)  scanf("%d",&a[i]);
        int id=-1,ans=-1,a1,a2,a3;
        rep(i,0,n)
            if(i>0 && a[i]==a[i-1]) sum[id]+=1;
            else sum[++id]=1;
        id+=1;
        rep(i,1,id) sum[i]+=sum[i-1];
        //rep(i,0,id) printf("%d ",sum[i]);puts("");
        rep(i,0,id){
            int g=sum[i],s=-1,b=-1;
            int l=i+1,r=id-2;
            while(l<=r){
                int mid=l+r>>1;
                if(sum[mid]-sum[i]>g) r=mid-1;
                else l=mid+1;
            }
            if(l>id-2) continue;
            s=sum[l]-sum[i];
            b=n/2-g-s;
            if(b<=0) continue;
            int p=l;
            l+=1;r=id-1;
            while(l<=r){
                int mid=l+r>>1;
                if(sum[mid]-sum[p]>b) r=mid-1;
                else l=mid+1;
            }
            if(l==p+1) continue;
            l-=1;
            b=sum[l]-sum[p];
            if(b<=g) continue;
            if(g+s+b>ans){
                ans=g+s+b;
                a1=g;a2=s;a3=b;
            }
        }
        if(ans==-1) printf("0 0 0\n");
        else printf("%d %d %d\n",a1,a2,a3);
    }
return 0;
}
