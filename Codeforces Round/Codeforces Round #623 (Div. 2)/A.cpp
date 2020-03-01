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

int judge(int a,int b){
    if(a>=0 && a<n && b>=0 && b<m) return 1;
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,ans=-1;
        scanf("%d %d %d %d",&n,&m,&a,&b);

        int x=a-1;
        if(x>=0 && x<n){
            int s=(x+1)*(m);
            if(s>ans) ans=s;
        }
        x=a+1;
        if(x>=0 && x<n){
            int s=(n-x)*(m);
            if(s>ans) ans=s;
        }
        int y=b-1;
        if(y>=0 && y<m){
            int s=(y+1)*(n);
            if(s>ans) ans=s;
        }
        y=b+1;
        if(y>=0 && y<m){
            int s=(m-y)*(n);
            if(s>ans) ans=s;
        }
        printf("%d\n",ans);

    }
return 0;
}
