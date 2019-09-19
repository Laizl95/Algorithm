#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=5*1e5+5;
char s[N];
int main(){

    while(scanf("%s",s)!=EOF){
        int len=strlen(s),min_='z';
        rep(i,0,len){
          if(s[i]>min_) puts("Ann");
          else puts("Mike");
          min_=min(min_,(int)s[i]);
        }
    }
return 0;
}
