#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=105;
int ans[10],vis[10];
int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        ms(vis,0);
        int c=abs(a+b),dig=0;
        while(c){
            ans[dig++]=c%10;
            c/=10;
            if(dig%3==0) vis[dig-1]=1;
        }
        if(a+b<0) printf("-");
     for(int i=dig-1;i>=0;--i){
        if(i!=dig-1 && vis[i])printf(",%d",ans[i]);
        else printf("%d",ans[i]);
     }
     if(a+b==0) printf("0");
     puts("");
    }
return 0;
}
