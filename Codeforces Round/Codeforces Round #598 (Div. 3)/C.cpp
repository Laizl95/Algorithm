#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005,inf=1e9+5;
typedef long long LL;
int a[N],p[N];
int main(){
    int n,m,d;
    while(scanf("%d %d %d",&n,&m,&d)!=EOF){
            int sum=0;
        rep(i,0,m) scanf("%d",&a[i]),sum+=a[i];
        ms(p,0);
        if(n+1-sum<=d){
                int k=0;
            rep(i,0,m){
                rep(j,1,a[i]+1) p[k+j]=i+1;
                k+=a[i];
            }
            puts("YES");
            rep(i,1,n+1) printf("%d ",p[i]); puts("");
        }else{
            int need=n+1-sum-d;
            int x=need/m,y=need%m;
            //cout<<x<<" "<<y<<endl;
            if(x>d-1 || (x==d-1 && y!=0) ) puts("NO");
            else{

                int k=1;
                rep(i,0,m){
                    int step;
                    if(m-i<=y) step=x+1;
                    else step=x;
                    p[k+step]=i+1;
                    rep(j,0,a[i]){
                        p[k+step+j]=i+1;
                    }
                    k+=step+a[i];
                }
                    puts("YES");
                    rep(i,1,n+1) printf("%d ",p[i]); puts("");

            }
        }
    }
}
