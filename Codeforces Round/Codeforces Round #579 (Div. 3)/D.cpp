#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5;
typedef long long LL;
char s[N],a[N];
int pos[N];
int main(){
    scanf("%s %s",s,a);
    int len_s=strlen(s),len_a=strlen(a);
    int p=len_a-1;
    per(i,0,len_s){
        if(s[i]==a[p]) {
            pos[p]=i;
            p-=1;
            if(p<0) break;
        }
    }
    int ans=0,t=0;
    //rep(i,0,len_a) printf("%d ",pos[i]);puts("");
    rep(i,0,len_s){
        p=len_s-1;
        if(t<len_a) p=pos[t]-1;
        ans=max(ans,p-i+1);
        if(t<len_a && s[i]==a[t]) t+=1;
    }
    cout<<ans<<endl;
return 0;
}
