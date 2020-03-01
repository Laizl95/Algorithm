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
        rep(i,0,3) if(a[i]>0) a[i]-=1,ans++;
        per(i,0,3) rep(j,0,i){
            if(a[i]>0 && a[j]>0){
                --a[i];
                --a[j];
                ++ans;
            }
        }
        if(a[0] && a[1] && a[2]) ++ans;
        printf("%d\n",ans);

    }
return 0;
}
