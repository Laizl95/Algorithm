#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=1e5+5,inf=1e9+5;
typedef long long LL;
char s[N];
int n,m;
int num[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        scanf("%s",s+1);
        int len=strlen(s+1);
        rep(i,1,len+1)
            if(s[i]=='0') num[i]=num[i-1]+1;
            else num[i]=num[i-1]-1;

        if(num[len]==0){
                int ok=0;
            rep(i,1,len+1)
                if(num[i]==m){ok=1;break;}
            if(ok) puts("-1");
            else puts("0");
        }else{
            int ans=0;
            rep(i,1,len+1)
                if((m-num[i])%num[len]==0 && (m-num[i])/num[len]>=0)
                    ++ans;
            if(m==0) ++ans;
            printf("%d\n",ans);
        }
    }
return 0;
}
