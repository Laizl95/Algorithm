#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int a[N];
map<int,int> mp;
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
            mp.clear();
        scanf("%d",&n);
        int tot=0;
        rep(i,1,2*n+1){
            scanf("%d",&a[i]);
            if(a[i]==1) tot++;
            else tot--;
        }
        int num=tot;
        tot=0;
        rep(i,n+1,2*n+1){
            if(a[i]==1) tot-=1;
            else tot+=1;
            if(!mp.count(tot)){
               mp[tot]=i;
            }
        }
        int ans=2*n;
        if(num==0) ans=0;
        tot=0;
        per(i,1,n+1){
            if(a[i]==1) tot-=1;
            else tot+=1;

            if(mp.count(-(num+tot))){
                ans=min(mp[-(num+tot)]-i+1,ans);
            }

        }

        if(mp.count(-num)) ans=min(mp[-num]-n,ans);
        mp.clear();
        tot=0;
        per(i,1,n+1){
            if(a[i]==1) tot-=1;
            else tot+=1;
            if(!mp.count(tot)){
               mp[tot]=i;
            }
        }
        tot=0;
        if(mp.count(-num)) ans=min(n-mp[-num]+1,ans);
        tot=0;
        rep(i,n+1,2*n+1){
            if(a[i]==1) tot-=1;
            else tot+=1;

            if(mp.count(-(num+tot))){
                ans=min(i-mp[-(num+tot)]+1,ans);
            }

        }
        printf("%d\n",ans);
    }
return 0;
}
