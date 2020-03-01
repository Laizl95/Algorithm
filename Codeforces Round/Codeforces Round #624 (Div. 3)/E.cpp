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

int n,m;
int d[N],a[N],fa[N];
int main(){
    int t,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int sum=n*(n-1)/2-m,l=2,r=n;
        rep(i,1,n+1) d[i]=1;
        while(sum>0){
            while(l<r && (sum-r+l<0 || d[l]==1<<(l-1)))
                l++;
            if(l>=r) break;
            sum-=r-l;
            d[l]+=1;
            d[r]-=1;
            if(d[r]==0) r-=1;
        }
        if(sum!=0){puts("NO");continue;}
        puts("YES");
        rep(i,1,n+1) a[i]=d[i]+a[i-1];
        rep(i,2,n+1){
            if(d[i]==0) break;
            int x=d[i],id=a[i-1]+1;
            rep(j,a[i-2]+1,a[i-1]+1){
                fa[id]=j;
                --x;++id;
                if(!x) break;
                fa[id]=j;
                 --x;++id;
                if(!x) break;
            }
        }
        //rep(i,1,n+1) printf("%d ",d[i]);puts("");
        rep(i,2,n+1) printf("%d ",fa[i]);puts("");
    }
return 0;
}
