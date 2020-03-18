#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m,k;
int a[N],b[N],d1[N],d2[N];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(i,1,m+1) scanf("%d",&b[i]);
    int tot=0;LL ans=0;
    rep(i,1,n+1){
        if(a[i]) ++tot,d1[tot]+=1;
        else{
            tot=0;
        }
    }tot=0;
    rep(i,1,m+1){
         if(b[i]) ++tot,d2[tot]+=1;
        else{
            tot=0;
        }
    }
    per(i,1,n+1) d1[i]+=d1[i+1];
    per(i,1,m+1) d2[i]+=d2[i+1];
    //rep(i,1,n+1) printf("%d ",d1[i]); puts("");
    //rep(i,1,m+1) printf("%d ",d2[i]); puts("");
    rep(i,1,40001){
        if(k%i==0 && k/i<=40000) ans+=d1[i]*d2[k/i];
    }
    cout<<ans<<endl;
return 0;
}
