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
char s[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d %d %s",&a,&b,&n,s);
        int cost=0,len=strlen(s),ans=1;
        per(i,0,len-1){
            if(i==len-2 || s[i]!=s[i+1]){
                if(s[i]=='B') cost+=b;
                else cost+=a;
            }
            //cout<<cost<<endl;
            if(cost>n){
                ans=i+2;break;
            }
        }
        printf("%d\n",ans);

    }
return 0;
}
