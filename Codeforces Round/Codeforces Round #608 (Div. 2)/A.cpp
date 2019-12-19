#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int solve(int a,int b,int c,int d,int e,int f){
    int ans1=0; int k1=min(b,c);
     int x=min(a,d);
        ans1+=x*e;
        a-=x;d-=x;
        x=min(k1,d);
        ans1+=f*x;
        return ans1;
}
int main(){
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    int k1=min(b,c);
    int ans1=0,ans2=0;
     ans1=solve(a,b,c,d,e,f);
        int x=min(k1,d);
        ans2+=x*f;
        k1-=x;d-=x;
        x=min(a,d);
        ans2+=e*x;
        printf("%d\n",max(ans1,ans2));

return 0;
}
