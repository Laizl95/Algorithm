#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
int need[N],num[N];
int main(){
    int t,x,n;
    scanf("%d %d",&t,&x);
    int goal=0;
    need[0]=1;
    rep(i,0,t){
        scanf("%d",&n);
        num[n%x]++;
        //cout<<goal<<" "<<need[goal%x]<<" "<<num[goal%x]<<endl;
        if(num[goal%x]>=need[goal%x]){
            while(goal<=i && num[goal%x]>=need[goal%x])
                ++need[(++goal)%x];
            printf("%d\n",goal);
        }
        else printf("%d\n",goal);
    }
return 0;
}
