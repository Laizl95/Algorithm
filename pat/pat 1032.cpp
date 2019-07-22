#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=100005;
int head[N],num[N];
int main(){
    int sd1,sd2,n;
    while(scanf("%d %d %d",&sd1,&sd2,&n)!=EOF){
        int now,next;char x;
        rep(i,0,n){
          scanf("%d %c %d",&now,&x,&next);
          head[now]=next;
          //head[next]=-1;
          num[now]=0;
        }
        int ans=-1;
        for(int i=sd1;i!=-1;i=head[i]) num[i]+=1;
        for(int i=sd2;i!=-1;i=head[i])
            if(num[i]) {ans=i;break;}
        if(ans!=-1)printf("%05d\n",ans);
        else printf("%d\n",ans);
    }
return 0;
}
