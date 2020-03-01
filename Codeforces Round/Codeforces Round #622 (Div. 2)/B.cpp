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
            int x,y;
        scanf("%d %d %d",&n,&x,&y);
        int t=x+y+1,l=1,r=x+y-1;
        if(t-1>=n) l=t-n;
        //n-l+1
        if(l>=n) l=n;
        if(r>=n) r=n;
        printf("%d %d\n",l,r);

    }
return 0;
}
