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
int a[N],num[N],b[N];
int main(){
    scanf("%d %d",&n,&m);
    int ok=1;
    rep(i,0,n){
        scanf("%d",&a[i]);
        int x=a[i]%m;
        num[x]+=1;
        b[x]=i;
        if(num[x]>1) ok=0;
    }
    if(!ok){puts("0");return 0;}
    LL ans=1;
    rep(i,0,1000){
        if(num[i]==0) continue;
        int id=b[i];
        rep(j,0,1000){
            if(num[j]==0) continue;
            if(b[j]>id) ans=ans*abs(a[id]-a[b[j]])%m;
        }
    }
    cout<<ans<<endl;

return 0;
}
