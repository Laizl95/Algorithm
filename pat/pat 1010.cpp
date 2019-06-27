#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=15;
typedef long long ll;
ll get(char s[],char str[],int radix){
  int len=strlen(s),len2=strlen(str);
  int dight=1;
  ll ans=0;
  per(i,0,len){
     if(s[i]>='0' && s[i]<='9') ans+=(s[i]-'0')*dight;
     else ans+=(s[i]-'a'+10)*dight;
     dight*=radix;
  }
  //printf("%d\n",ans);
  rep(i,2,36){
      //printf("%d\n",i);
      vector<int> v;
      ll x=ans;
       while(x>0){
        v.pb(x%i);
        x/=i;
       }
       int t=v.size(),flag=1;
     // rep(i,0,t) printf("%d ",v[i]);puts("");rep(i,0,len2) printf("%c ",str[i]);puts("");
       if(t==len2)
         rep(j,0,len2){
         if(str[j]>='0' && str[j]<='9' && str[j]-'0'!=v[len2-j-1])
            {flag=0;break;}
         else if(str[j]>='a' && str[j]<='z' && str[j]-'a'+10!=v[len2-j-1]){flag=0;break;}
         }
    else flag=0;
       if(flag) return i;
  }
  return -1;
}
int main(){
    char s1[N],s2[N];
    int tag,radix;
    while(scanf("%s %s %d %d",s1,s2,&tag,&radix)!=EOF){
         int id;
         if(tag==1) id=get(s1,s2,radix);
         else id=get(s2,s1,radix);
         if(id==-1) puts("Impossible");
         else printf("%d\n",id);
    }
return 0;
}
