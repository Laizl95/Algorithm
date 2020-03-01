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
int l_x[N],r_x[N],l_y[N],r_y[N];
int main(){
    int n;
    scanf("%d",&n);
    int x,y,a,b;
    rep(i,0,n){
        scanf("%d %d %d %d",&x,&y,&a,&b);
        l_x[i]=x;r_x[i]=x+a;
        l_y[i]=y;r_y[i]=y+b;
    }
    scanf("%d %d",&x,&y);
    int ans=-1;
    per(i,0,n) if(x>=l_x[i] && x<=r_x[i] && y>=l_y[i] && y<=r_y[i]){
        ans=i+1;break;
    }
    printf("%d\n",ans);
return 0;
}
