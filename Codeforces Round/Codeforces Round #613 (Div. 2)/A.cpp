#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n,m;
char s[N];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int l=0,r=0;
    rep(i,0,n){
        if(s[i]=='L') l-=1;
        else r+=1;
    }
    printf("%d\n",r-l+1);
return 0;
}
