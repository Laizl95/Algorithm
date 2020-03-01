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

int main(){
    int t;
    scanf("%d",&t);
    string s[15];
    while(t--){
        scanf("%d",&n);
        map<string,int> mp;
        rep(i,0,n){
            cin>>s[i];
            mp[s[i]]+=1;
        }
        int ans=0;
       rep(i,0,n){
            if(mp[s[i]]==1) continue;
            ans+=1;
            mp[s[i]]-=1;
            string a=s[i];
            int ok=0;
            rep(j,0,4){
                rep(k,0,10){
                 a[j]=k+'0';
                 if(mp.count(a)==0){
                    mp[a]=1;
                    s[i]=a;
                    ok=1;break;
                 }
                 if(ok) break;
                }
                if(ok) break;
            }

       }
        printf("%d\n",ans);
        rep(i,0,n) cout<<s[i]<<endl;

    }
return 0;
}
