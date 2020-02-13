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
LL a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        map<LL,int> mp;
        rep(i,1,n+1){
           if(s[i]=='L') a[i]=-1;
           if(s[i]=='R') a[i]=1;
           if(s[i]=='U') a[i]=6e5;
           if(s[i]=='D') a[i]=-6e5;
        }
        LL tot=0,ans=-1;
        int ansl,ansr;
        mp[0]=0;
        rep(i,1,n+1){
           tot+=a[i];//cout<<tot<<endl;
           if(mp.count(tot)){
              int l=mp[tot]+1;
              if(ans>i-l+1 || ans==-1){
                ans=i-l+1;
                ansl=l;ansr=i;
              }
              mp[tot]=i;
           }else mp[tot]=i;

        }
        if(ans!=-1)
        printf("%d %d\n",ansl,ansr);
        else puts("-1");
    }
return 0;
}
