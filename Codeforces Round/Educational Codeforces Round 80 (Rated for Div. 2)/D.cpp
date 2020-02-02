#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;

int n,m,num1,num2;
int a[N][10];
int solve(int mid){
    int bit[1<<10]={0};
     rep(i,0,n){
            int g=0;
            rep(j,0,m){
                if(a[i][j]>=mid){
                    g+=1<<(m-j-1);
                }
            }
            bit[g]=i+1;
        }

        int g=(1<<m),a_l=-1,a_r=-1;
        rep(i,0,g){
            rep(j,0,g){
                if(bit[i] && bit[j] && (i|j)==g-1){
                    a_l=bit[i];a_r=bit[j];break;
                }
            }
            if(a_l!=-1) break;
        }
    if(a_l!=-1) {num1=a_l;num2=a_r;return 1;}
    return 0;
}
int main(){

    scanf("%d %d",&n,&m);
    rep(i,0,n) rep(j,0,m) scanf("%d",&a[i][j]);
    int l=0,r=1e9;
    while(l<=r){
        int mid=l+r>>1;
        if(solve(mid)) l=mid+1;
        else r=mid-1;
    }
    solve(l-1);
    printf("%d %d\n",num1,num2);
return 0;
}
