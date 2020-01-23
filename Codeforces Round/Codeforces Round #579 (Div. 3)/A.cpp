#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=2e5+5;
typedef long long LL;
int a[N];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,0,n) scanf("%d",&a[i]);
        int p,x=1;
        rep(i,0,n) if(a[i]==1){
            p=i;
            break;
        }
        int flag=1;
        per(i,0,p+1){
            if(a[i]==x){
                x+=1;
            }
            else{flag=0;break;}
        }
        if(flag){
            per(i,p+1,n)
                if(a[i]==x) x+=1;
                else{flag=0;break;}
        }
        if(flag){puts("YES");}
        else{
        flag=1;x=1;
        rep(i,p,n){
             if(a[i]==x){
                x+=1;
            }
            else{flag=0;break;}
        }
        if(flag){
             rep(i,0,p)
                if(a[i]==x) x+=1;
                else{flag=0;break;}
        }
        if(flag)puts("YES");
       else puts("NO");}
    }
return 0;
}
