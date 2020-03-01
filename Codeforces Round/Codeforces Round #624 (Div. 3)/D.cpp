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
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
            int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int x=0;
        int ans=-1,t1,t2,t3;
          for(int i=1;i<=10000;i++)
            for(int j=i;j<=10000+i;j+=i)
                for(int k=j;k<=10000+j;k+=j){
                        //++x;
                    int cnt=abs(a-i)+abs(b-j)+abs(c-k);
                    if(ans==-1 || cnt<ans){
                        ans=cnt;
                        t1=i;
                        t2=j;
                        t3=k;
                    }
                }
        printf("%d\n%d %d %d\n",ans,t1,t2,t3);
    }
return 0;
}
