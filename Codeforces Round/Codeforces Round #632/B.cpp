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
int n,m;
int a[N],b[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);
        rep(i,0,n) scanf("%d",&b[i]);
        int l=0,r=0,ok=1;
        rep(i,0,n){
            if(a[i]<b[i] && r==0) ok=0;
            if(a[i]>b[i] && l==0) ok=0;
            if(a[i]>0) r=1;
            if(a[i]<0) l=1;
        }
        puts(ok?"YES":"NO");
    }
return 0;
}
