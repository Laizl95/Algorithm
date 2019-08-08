#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
char s[N];
int judge(int p1,int p2){
    int p=(p2-p1+1)/2+p1;
    rep(j,p1,p) if(s[j]!=s[p2+p1-j]) return 0;
    return 1;
}
int main(){
    cin.getline(s,1001);
    //rep(i,0,1000) printf("%c",s[i]);
    int len=strlen(s),ans=0;
    rep(i,0,len) per(j,i,len)
        if(judge(i,j)) ans=max(ans,j-i+1);
     printf("%d\n",ans);

return 0;
}
