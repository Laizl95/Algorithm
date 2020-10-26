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
const int N=2e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
char s[N];
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %s",&n,s+1);
        s[0]=s[1];
        int num=0;
        vector<int> v;
        rep(i,1,n+1){
            if(s[i]==s[i-1]){
                ++num;
            }else{
                v.pb(num);
                num=1;
            }
        }
        if(num) v.pb(num);
        //for(auto &x:v) printf("%d ",x);cout<<endl;
        int p=0,ans=0;
        for(int i=0;i<(int)v.size();){

            p=max(p,i);
            if(v[i]>1){
                ++ans;
                i+=1;
            }else{
                while(p<v.size() && v[p]==1) ++p;
                if(p>=v.size()){
                    i+=2;
                    ++ans;
                }else {
                    ++ans;
                    v[p]-=1;
                    i+=1;
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}
