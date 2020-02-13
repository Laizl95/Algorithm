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
    scanf("%d %d",&n,&m);
    scanf("%s",s);
    rep(i,0,n){
        if(m<=0) break;
        if(i==0 && i!=n-1 && s[i]!='1') {--m,s[i]='1';continue;}
        if(i==0 && n==1) {--m;s[i]='0';continue;}
        if(i>0 && s[i]!='0') --m,s[i]='0';
    }
    rep(i,0,n) printf("%c",s[i]);puts("");
return 0;
}
