#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
char a[N][15],b[N][15];
int main(){
    int n,m,q,x;
    scanf("%d %d",&n,&m);
    rep(i,1,n+1) scanf("%s",a[i]);
    rep(i,1,m+1) scanf("%s",b[i]);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        int id1=x%n,id2=x%m;
        if(id1==0) id1=n;
        if(id2==0) id2=m;
        printf("%s%s\n",a[id1],b[id2]);
    }
return 0;
}
