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
int n,m,k;
char s[N];
int c[N],ans[N],l[26],max_c[26];
int main(){
    int t;
    scanf("%d %s",&n,s);
    int len=strlen(s);
    ms(max_c,-1);
    rep(i,0,n){
        int x=s[i]-'a',num=0;
        if(l[x]==-1) l[x]=i;
        int f=-1;
        rep(j,0,26){
            if(l[j]==-1) continue;
            if(j>x && l[j]<i)
                f=max(f,max_c[j]);
        }
        if(f==-1){
            max_c[x]=1;
            ans[i]=1;
        }else{
            max_c[x]=f+1;
            ans[i]=f+1;
        }
    }
    int e=-1;
    rep(i,0,26) e=max(e,max_c[i]);
    printf("%d\n",e);
    rep(i,0,n)  printf("%d ",ans[i]);
    puts("");

return 0;
}
