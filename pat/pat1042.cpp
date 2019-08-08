#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105;
int a[N],b[N],shuff[N];

int main(){
    int k;
    char s[5]={'S','H','C','D','J'};
    while(scanf("%d",&k)!=EOF){
        rep(i,0,54) scanf("%d",&shuff[i]),a[i]=i;
        rep(i,0,k){
            rep(j,0,54) b[shuff[j]-1]=a[j];
            rep(j,0,54) a[j]=b[j];
        }
        rep(i,0,54)
          if(i==0) printf("%c%d",s[a[i]/13],a[i]%13+1);
          else printf(" %c%d",s[a[i]/13],a[i]%13+1);
          puts("");

    }
return 0;
}
