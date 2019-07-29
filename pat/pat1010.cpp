#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
typedef long long ll;
ll cal(char s[],int radix){
    int len=strlen(s);
    ll dight=1;
    ll ans=0;
    per(i,0,len){
        if(s[i]>='0' && s[i]<='9') ans+=(s[i]-'0')*dight;
        else ans+=(s[i]-'a'+10)*dight;
        dight*=radix;
        if(ans<0) return -1;
  }
  return ans;
}
ll get(char s[],char str[],int radix){
  ll r=cal(s,radix)+1,l=0;
  ll v1=r-1;
  int len=strlen(str);
  rep(i,0,len){
       if(str[i]>='0' && str[i]<='9') l=max((str[i]-'0')*1ll,l);
        else l=max((str[i]-'a'+10)*1ll,l);
  }
  l+=1;
  while(l<=r){
    ll mid=l+r >>1;
    ll v2=cal(str,mid);
    if(v2>v1 || v2==-1) r=mid-1;
    else if(v2<v1) l=mid+1;
    else return mid;
  }
  return -1;
}
int main(){
    char s1[N],s2[N];
    int tag,radix;
    while(scanf("%s %s %d %d",s1,s2,&tag,&radix)!=EOF){
         ll ans;
         if(tag==1) ans=get(s1,s2,radix);
         else ans=get(s2,s1,radix);
         if(ans==-1) puts("Impossible");
         else printf("%lld\n",ans);
    }
return 0;
}
