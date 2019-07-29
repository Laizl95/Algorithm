#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
int a[N];
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
            int p=0;
        while(n>0){
            a[p++]=n%m;
            n/=m;
        }
        int t=p/2+1,ok=1;
        rep(i,0,t) if(a[i]!=a[p-1-i]){ok=0;break;}
        puts(ok?"Yes":"No");
        per(i,0,p) printf("%d%c",a[i],i==0?'\n':' ');
    }
return 0;
}
