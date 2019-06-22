#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(i) push_back(i)
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
const int N=1500000;
int n,tot;
int a[1<<17];
char s[N];
map<LL,int> mp;
map<LL,int>::iterator it;
int dfs(int pos,int len,int d){
    if(pos>len) return 0;
     if(s[pos]=='['){
        int now=dfs(pos+1,len,d+1);
        if(s[now]==',') dfs(now+1,len,d+1);
        else{
        while(now<=len && s[now]==']') now+=1;
         dfs(now+1,len,d+1);
        }
     }
     else if(s[pos]>='0' && s[pos]<='9'){
            int num=0,i=pos;
        while(s[i]>='0' && s[i]<='9'){
            num=num*10+(s[i]-'0');
            ++i;
        }
        ++tot;
     //a[++tot]=num;
     mp[(num*1LL)*(1<<d)]+=1;
     //printf("%lld\n",(num*1LL)*(1<<d));
     return i;
     }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
     scanf("%s",s);
     int len=strlen(s)-1;
     tot=0;
     mp.clear();
     dfs(0,len,0);
     //rep(i,1,tot) printf("%d ",a[i]);puts("");
     int maxx=0;
     for(it=mp.begin();it!=mp.end();++it) maxx=max(maxx,it->second);
     printf("%d\n",tot-maxx);
    }
}
