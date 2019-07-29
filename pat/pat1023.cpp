#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=25;
char a[N];
int main(){
    int vis[10];
   while(scanf("%s",a)!=EOF){
        ms(vis,0);
     int len=strlen(a);
     rep(i,0,len) vis[a[i]-'0']+=1;
     int p=0;
     per(i,0,len){
         int x=(a[i]-'0')*2+p;
         a[i]=(x%10)+'0';
         p=x/10;
     }
     if(p) vis[p]-=1;
     rep(i,0,len) vis[a[i]-'0']-=1;
     int ok=1;
     //rep(i,1,10) printf("%d ",vis[i]);puts("");
     rep(i,0,10) if(vis[i]!=0) ok=0;
     puts(ok?"Yes":"No");
     if(p) printf("%d",p);
     rep(i,0,len) printf("%d",a[i]-'0');
     puts("");
   }
return 0;
}
