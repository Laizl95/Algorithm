#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define ms(x,y) memset(x,y,sizeof(x))
typedef long long LL;
using namespace std;
const int N=3005;
struct node{
 int id,y;
 node(){}
 node(int _id,int _y){
  id=_id;
  y=_y;
 }
 bool operator < (const node &a) const{
   return y<a.y || (y==a.y && id<a.id);
 }
}s[N];
int num[N],cost[N];
int main(){
    freopen("d://input.txt","r",stdin);
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        ms(num,0);
        int max_id=-1,max_sum=0;
        int a,b;
        rep(i,1,n){
         scanf("%d %d",&a,&b);
         num[a]+=1;cost[a]=b;
         if(max_sum<=num[i]) max_id=i,max_sum=num[i];
        }
        int cnt=0;
        rep(i,1,3000) if(num[i]) s[++cnt]=node(i,num[i]);
        sort(s+1,s+1+cnt);
        /*priority_queue<p> q;
        q.push(p(1,num[1]));
        rep(i,2,3000) if(!num[i]) q.push(p(i,num[i]));*/
        rep(i,1,cnt) printf("%d %d\n",s[i].id,s[i].y);
        LL sum=0;int tot=1;
        while(max_id!=1){
           while(tot<=cnt && s[tot].id==1) ++tot;
           if(tot>cnt) break;
            sum+=s[tot].y;
           num[s[tot].id]-=1;
           num[1]+=1;
           max_sum=0;
           rep(i,1,3000){
           if(max_sum<=num[i]) max_id=i,max_sum=num[i];
           }
        }
        printf("%lld\n",sum);
    }
return 0;
}
