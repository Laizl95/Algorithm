#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

char s1[N],s2[N];
int solve(int p,int len){
    char c=s1[p-1];int pos=-1,ok=0;
    rep(i,p,len)
        if(s1[i]<=c && s1[i]<s1[p-1]){ok=1;c=s1[i];pos=i;}
    if(ok) swap(s1[p-1],s1[pos]);
    return ok;
}
int main(){
    int t,n;
    //printf("%d\n",strcmp("ca","ab"));
    scanf("%d",&t);
    while(t--){
       scanf("%s %s",s1,s2);
       int len=strlen(s1);
       rep(i,0,len){
            if(solve(i+1,len)) break;
       }
       if(strcmp(s1,s2)==-1) puts(s1);
       else puts("---");
    }
return 0;
}
