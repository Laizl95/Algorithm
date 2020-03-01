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
int main(){
   scanf("%d %d %d",&n,&m,&k);
   if(4*n*m-2*n-2*m<k){puts("NO");return 0;}
        vector<pair<char,int> > ans;
        int r=1,c=1;
        while(c<m){
                ++c;
            if(k>0){
                    k-=1;
                 ans.pb(mp('R',1));
            }
            if(k>=n-1){
                k-=n-1;
                if(n-1>0) ans.pb(mp('D',n-1));
            }else{
                if(k>0) ans.pb(mp('D',k));
                k=0;
            }
            if(k>=n-1){
                k-=n-1;
                if(n-1>0) ans.pb(mp('U',n-1));
            }else{
                if(k>0) ans.pb(mp('U',k));
                k=0;
            }
        }
        if(k>m-1){
            if(m-1>0) ans.pb(mp('L',m-1));
            k-=m-1;
        }else{
            if(k>0) ans.pb(mp('L',k));
            k=0;
        }
        while(r<n){
            r+=1;
            if(k>0){
                k-=1;
                ans.pb(mp('D',1));
            }
            if(k>=m-1){
                k-=m-1;
                if(m-1>0)ans.pb(mp('R',m-1));
            }else{
                if(k>0) ans.pb(mp('R',k));
                k=0;
            }
            if(k>=m-1){
                k-=m-1;
                if(m-1>0)ans.pb(mp('L',m-1));
            }else{
                if(k>0) ans.pb(mp('L',k));
                k=0;
            }
        }
        if(k>0) ans.pb(mp('U',k));
        puts("YES");
        printf("%d\n",ans.size());
        for(auto it:ans)
            printf("%d %c\n",it.second,it.first);
return 0;
}
