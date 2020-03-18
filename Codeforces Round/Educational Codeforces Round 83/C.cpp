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
int n,k;
LL a[N],b[N];
int vis[100];
int solve(int i,int p){
    while(a[i]!=0){
            int ok=0;
        per(j,0,p){
            if(vis[j]) continue;
            if(a[i]%b[j]==0){
                a[i]-=b[j];
                vis[j]=1;
                ok=1;
                break;
            }
        }
        if(!ok) return 0;
    }
    return a[i]==0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        LL x=0;
        rep(i,0,n) scanf("%lld",&a[i]),x=max(x,a[i]);
        sort(a,a+n);
        int p=0;LL y=1LL;
        while(y<=x){
            b[p++]=y;
            y*=k;
        }
        int ok=1;
        per(i,0,n){
           if(!solve(i,p)){ok=0;break;}
        }
        puts(ok?"YES":"NO");
        rep(i,0,p) vis[i]=0;
    }
return 0;
}
