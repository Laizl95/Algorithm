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
int n,m,x,y;
int a[N],b[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&x,&y);
        while(n>=40){
            if(x>0){
                --x;
                n=n/2+10;
            }else break;
        }
        if(n-y*10>0){
            while(n>=20){
                if(x>0){
                    --x;
                    n=n/2+10;
                }else break;
            }
            if(n-y*10>0) puts("NO");
            else puts("YES");
        }else puts("YES");
    }
return 0;
}
