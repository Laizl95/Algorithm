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
const int N=1e5+5,inf=1e6+5,mod=19650827;
typedef long long LL;
int ans[N];
char s[N];
int main(){
    int t,x;
    scanf("%d",&t);
    while(t--){
        scanf("%s %d",s+1,&x);
        int len=strlen(s+1),ok=1;
        rep(i,1,len+1) ans[i]=-1;
        rep(i,1,len+1){
            if(s[i]=='1'){
                int l=i-x,r=i+x;
                if(l<1 && r>len) {ok=0;break;}
                if(l>=1 && r<=len){
                    if(ans[l]==0 && ans[r]==0) {ok=0;break;}
                    if(ans[l]==1 || ans[r]==1) continue;
                    if(ans[l]==-1) ans[l]=1;
                    else if(ans[r]==-1) ans[r]=1;
                    continue;
                }
                if(l>=1){
                    if(ans[l]==0){ok=0;break;}
                    ans[l]=1;
                }
                if(r<=len){
                    if(ans[r]==0){ok=0;break;}
                    ans[r]=1;
                }

            }else{
                int l=i-x,r=i+x;
                if(l<1 && r>len) continue;
                if(l>=1 && r<=len){
                    if(ans[l]==1 || ans[r]==1) {ok=0;break;}
                    ans[l]=0;
                    ans[r]=0;
                    continue;
                }
                if(l>=1) {
                    if(ans[l]==1){ok=0;break;}
                    ans[l]=0;
                }
                if(r<=len){
                    if(ans[r]==1){ok=0;break;}
                    ans[r]=0;
                }
            }
        }
        if(!ok) puts("-1");
        else{
            rep(i,1,len+1)
                if(ans[i]==-1) printf("0");
                else printf("%d",ans[i]);
            puts("");
        }
    }
return 0;
}
