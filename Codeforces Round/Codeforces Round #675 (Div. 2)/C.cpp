#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5,mod=1e9+7;
typedef long long LL;
int n,m,x;
char s[N];
LL sum[N],p[N];
int main(){
   scanf("%s",s);
   int len=strlen(s);
   LL temp=1;
   p[0]=1;
   rep(i,1,len+1){
        sum[i]=(sum[i-1]+i*temp%mod)%mod;
        temp=temp*10%mod;
        p[i]=p[i-1]*10%mod;
   }
   //rep(i,1,len+1) printf("%d ",sum[i]);cout<<endl;
   LL ans=0;
   rep(i,0,len){
        int k1=i,k2=len-i-1,x=s[i]-'0';
        LL t1=(1+k1)*1LL*k1/2%mod*p[k2],t2=sum[k2];
        //cout<<t1<<" "<<t2<<endl;
        ans=(ans+x*(t1+t2)%mod)%mod;
   }
   cout<<ans<<endl;
return 0;
}
