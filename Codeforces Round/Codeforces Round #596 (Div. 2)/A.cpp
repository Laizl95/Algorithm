#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2*1e5+5;
typedef long long LL;
int n,m;
int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        if(a==9 && b==1){
            printf("%d %d%d\n",a,b,0);
            continue;
        }
        if(b-a!=0 && b-a!=1){
            puts("-1");
            continue;
        }
        if(a==b){
            printf("%d%d %d%d\n",a,0,b,1);
        }
        else printf("%d%d %d%d\n",a,9,b,0);
    }
return 0;
}
