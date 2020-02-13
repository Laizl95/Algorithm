#pragma GCC optimize(2)
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
char s[N],ans[N];
int main(){
    int t,r,ss,p;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) ans[i]='0';
        rep(i,0,n) scanf("%d %d %d",&r,&p,&ss);
        scanf("%s",s);
        int tmp=0;
        rep(i,0,n){
            if(s[i]=='R'){
                if(p>0){
                    p-=1;
                    ans[i]='P';++tmp;
                }
            }else if(s[i]=='P'){
                if(ss>0){
                    ss-=1;
                    ans[i]='S';++tmp;
                }
            }else if(r>0){r-=1;ans[i]='R';++tmp;}
        }
        if(tmp>=(n+1)/2){
            puts("YES");
            rep(i,0,n)
                if(ans[i]=='0'){
                    if(r>0){r-=1;printf("R");}
                    else if(ss>0){ss-=1;printf("S");}
                    else if(p>0){p-=1;printf("P");}
                }
                else printf("%c",ans[i]);
                puts("");
        }else puts("NO");
    }
return 0;
}
