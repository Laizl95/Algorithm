#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int a[4];
int main(){
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
    int toal=a[0]+a[1]+a[2]+a[3],ok=0;

    rep(i,0,4){

        int st=i;
        int b[4]={a[0],a[1],a[2],a[3]}; vector<int> ans;
          //rep(i,0,4) printf("%d ",b[i]);
        while(a[st]>0){
            a[st]-=1;
            ans.pb(st);
            if(st-1>=0 && a[st-1]>0){
                st=st-1;
            }else if(st+1<=3 && a[st+1]>0){
                st=st+1;
            }else break;
        }
        rep(i,0,4) a[i]=b[i];
         if(ans.size()==toal) {
                ok=1;puts("YES");
         rep(i,0,ans.size()) printf("%d ",ans[i]);puts("");
            break;
         }
    }
    if(!ok) puts("NO");
return 0;
}
