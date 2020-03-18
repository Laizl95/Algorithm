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
            int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int x=0;
        int ans=-1,t1,t2,t3;
        //2a+k不如从1开始 2b+k不如从i开始
        for(int i=1;i<2*a;++i){
            for(int j=i;j<2*b;j+=i){
                rep(k,0,2){
                    int now_c=j*(c/j)+k*j;
                    int num=abs(i-a)+abs(j-b)+abs(now_c-c);
                    if(num<ans || ans==-1){
                            ans=num;
                        t1=i;t2=j;t3=now_c;
                    }
                }
            }
        }
        printf("%d\n%d %d %d\n",ans,t1,t2,t3);
    }
return 0;
}
