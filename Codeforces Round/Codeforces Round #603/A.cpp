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
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        int ans=0;
        int d=a[2]-a[1];
        ans+=min(d,a[0]);
        if(a[0]>=d) a[0]-=d,a[2]-=d;
        else d-=a[0],a[0]=0,a[2]-=d;
        sort(a,a+3);
        int x=a[0]/2;
        a[1]-=x;
        ans+=x;
        if(a[0]&1) ++x;
        a[2]-=x;
        ans+=x;
        ans+=min(a[1],a[2]);
        printf("%d\n",ans);

    }
return 0;
}
