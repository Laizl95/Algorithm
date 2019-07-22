#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long LL;
const int N=35;
const int T=1005;
int a[N],b[N],c[N];
int n;
int main(){
    int t=0;
    while(scanf("%d",&n)&&n){
        rep(i,1,n) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int x=0,num=0;
        while(++x<T){
            num=0;
            rep(i,1,n) if(c[i]<=a[i]) ++num;
            if(num==n) break;
            rep(i,1,n){
            if(c[i]==a[i]+b[i] || (c[i]==a[i] && num>=n-num)) c[i]=0;
               ++c[i];
            }
        }
        if(x==T) x=-1;
         printf("Case %d: %d\n", ++t, x);
    }
return 0;
}