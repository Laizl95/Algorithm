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

int n,m;
string s;
string rev_s[N],sub[N],s2[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      cin>>s;
      int len=s.length();
      rep(i,0,len) {rev_s[i].clear();sub[i].clear();s2[i].clear();}
      rep(i,0,len){
            rep(j,i,len) s2[i]+=s[j];
      }
      rev_s[0]=s[0];
      sub[0]=s[0];
      rep(i,1,len){
          sub[i]=sub[i-1]+s[i];
          rev_s[i]=sub[i];
          reverse(rev_s[i].begin(),rev_s[i].end());
      }
      string ans=s;int p=0;
      rep(i,1,len){
         string b=s2[i];
         if((len-i)&1) b+=rev_s[i-1];
         else b+=sub[i-1];
         if(b<ans){ans=b;p=i;}
      }
      cout<<ans<<endl;cout<<p+1<<endl;
      }
return 0;
}
