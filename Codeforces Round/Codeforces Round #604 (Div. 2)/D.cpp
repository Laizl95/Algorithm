#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int a[4];
int main(){
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
    if(a[0]-a[1]>=2 || (a[0]-a[1]==1 && (a[2] || a[3]))) {puts("NO");return 0;}
    if(a[3]-a[2]>=2 || (a[3]-a[2]==1 && (a[0] || a[1]))){puts("NO");return 0;}
    if(a[1]>=a[0] && a[2]>=a[3]){
        a[1]-=a[0];a[2]-=a[3];
        int x=max(a[1],a[2]);
        if(x-a[1]>=2 || x-a[2]>=2 ){puts("NO");return 0;}
        puts("YES");
        if(x-a[2]) printf("1 ");
        rep(i,0,a[0]) printf("0 1 ");
        rep(i,0,min(a[1],a[2])) printf("2 1 ");
        rep(i,0,a[3]) printf("2 3 ");
        if(x-a[1]) printf("2"); puts("");
    }else{
        if(a[0]-a[1]==1){puts("YES");
            rep(i,0,a[1]) printf("0 1 ");printf("0\n");
        }else{puts("YES");
            printf("3 ");rep(i,0,a[2]) printf("2 3 ");puts("");
        }
    }
return 0;
}
