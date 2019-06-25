#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
struct record{
  char name[20];
  int sh,sm,ss,zh,zm,zs;
  bool operator < (const record &a) const{
    return sh<a.sh || (sh==a.sh && sm<a.sm) || (sh==a.sh && sm==a.sm && ss<a.ss);
  }
}re[N];
bool cmp(const record &a,const record &b){
	if(a.zh!=b.zh) return a.zh<b.zh;
	if(a.zm!=b.zm) return a.zm<b.zm;
	if(a.zs!=b.zs) return a.zs<b.zs;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,0,n) scanf("%s %d:%d:%d %d:%d:%d",re[i].name,&re[i].sh,&re[i].sm
                         ,&re[i].ss,&re[i].zh,&re[i].zm,&re[i].zs);
        sort(re,re+n);
        printf("%s ",re[0].name);
        sort(re,re+n,cmp);
        printf("%s\n",re[n-1].name);
    }
return 0;
}
