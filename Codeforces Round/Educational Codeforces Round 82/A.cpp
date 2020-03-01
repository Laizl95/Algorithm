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
char s[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        int l=len+1,r=-1;
        rep(i,0,len){
            if(s[i]=='1'){l=min(l,i);r=max(r,i);}
        }
        int ans=0;
        if(l<=r){
            rep(i,l,r+1) if(s[i]=='0') ++ans;
        }
        printf("%d\n",ans);

    }
return 0;
}
