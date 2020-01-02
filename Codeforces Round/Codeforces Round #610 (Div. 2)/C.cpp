#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
struct node{
    LL level,t;
    node(){}
    node(LL _t,LL _level){t=_t;level=_level;}
    bool operator < (const node &a) const{
        return t<a.t || (t==a.t && level<a.level);
    }
}s[N];
LL num[2],t,a,b;
int n;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
      scanf("%d %lld %lld %lld",&n,&t,&a,&b);
      ms(num,0);
      rep(i,0,n){
        scanf("%lld",&s[i].level);
        if(s[i].level==0) num[0]+=1;
        else num[1]+=1;
        s[i].level=(s[i].level==0?a:b);
      }
      rep(i,0,n) scanf("%lld",&s[i].t);
      s[n].t=t+1;s[n].level=0;
      sort(s,s+n+1);
      LL ans=0,p=0;

      LL a1=0,a2=0,x1=0,x2=0,pre=0;
      s[n+1].t=s[n-1].t+1;
      while(p<=n){
         if(s[p].t-1>t) break;
         LL now_t=s[p].t-1-pre;
         if(now_t<0){
            pre+=s[p].level;
            if(s[p].level==a) a1+=1;
            else if(s[p].level==b) a2+=1;
            p+=1;
            if(p<n && s[p].t==s[p-1].t){
                while(p<n && s[p].t==s[p-1].t){
                    pre+=s[p].level;
                    if(s[p].level==a) a1+=1;
                    else if(s[p].level==b) a2+=1;
                    p+=1;
                }
            }
            continue;
         }
         x1=a1;x2=a2;
        // cout<<s[p].t<<" "<<pre<<" "<<now_t<<" "<<x1<<" "<<x2<<endl;
         if(now_t/a+a1>num[0]){
            now_t-=(num[0]-a1)*a;
            if(x2+now_t/b>num[1]) x2=num[1];
            else x2+=now_t/b;
            x1=num[0];
        }else x1+=now_t/a;
        ans=max(ans,x1+x2);
            pre+=s[p].level;
            if(s[p].level==a) a1+=1;
            else if(s[p].level==b) a2+=1;
            p+=1;
            if(p<n && s[p].t==s[p-1].t){
                while(p<n && s[p].t==s[p-1].t){
                    pre+=s[p].level;
                    if(s[p].level==a) a1+=1;
                    else if(s[p].level==b) a2+=1;
                    p+=1;
                }
            }
      }
      printf("%lld\n",ans);
    }
return 0;
}
