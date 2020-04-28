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
int a[N],ans[N];
int main(){
    scanf("%d %d",&n,&m);
    int ok=1;
    rep(i,1,m+1){
        scanf("%d",&a[i]);
        if(a[i]+i-1>n) ok=0;
    }
    if(!ok){puts("-1");return 0;}
    int pre=n;
    per(i,1,m+1){
       int p=pre+1-a[i];
       ans[i]=max(p,i);
       pre=ans[i]-1;
    }
    if(ans[1]>1) puts("-1");
    else {rep(i,1,m+1) printf("%d ",ans[i]);puts("");}
return 0;
}
