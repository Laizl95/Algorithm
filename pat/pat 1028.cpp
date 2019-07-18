#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e5+5;
struct stu{
    int id,score;
    char name[15];
}s[N];
bool cmp1(stu &a,stu &b){
  return a.id<b.id;
}
bool cmp2(stu &a,stu &b){
     int judge=strcmp(a.name,b.name);
     if(!judge) return a.id<b.id;
     return judge<0;//judge==-1;
}
bool cmp3(stu &a,stu &b){
     if(a.score!=b.score) return a.score<b.score;
     return a.id<b.id;
}
int main(){
    int d=1;
    cout<<(d<0)<<endl;
   int n,k;
   while(scanf("%d %d",&n,&k)!=EOF){
      rep(i,0,n) scanf("%d %s %d",&s[i].id,s[i].name,&s[i].score);
      if(k==1) sort(s,s+n,cmp1);
      if(k==2) sort(s,s+n,cmp2);
      if(k==3) sort(s,s+n,cmp3);
      rep(i,0,n) printf("%06d %s %d\n",s[i].id,s[i].name,s[i].score);
   }
}
