#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
int bill[24];
struct consumer{
   string name;
   int mon,day,h,m;
   string status;
   consumer(){}
   consumer(string _name,int _mon,int _day,int _h,int _m,string _status){
      name=_name;
      mon=_mon;day=_day;h=_h;m=_m;
      status=_status;
   }
   void print(){
    printf("%02d:%02d:%02d",day,h,m);
   }
};
bool cmp(consumer &a,consumer &b){
  if(a.name!=b.name) return a.name<b.name;
  if(a.mon!=b.mon) return a.mon<b.mon;
  if(a.day!=b.day) return a.day<b.day;
  if(a.h!=b.h) return a.h<b.h;
  return a.m<b.m;
}
double cal(consumer a){
    int toal_v=0;
    rep(i,0,24) toal_v+=bill[i];
    double fee=a.day*60*toal_v+bill[a.h]*a.m;
    rep(i,0,a.h) fee+=bill[i]*60;
    return fee/100;
}
int get_time(consumer a){
    return a.day*24*60+a.h*60+a.m;
}
int main(){
    map<string,int> mp;
    vector<consumer> v,cons[N];
  rep(i,0,24) scanf("%d",&bill[i]);
  int n,id=0;
  scanf("%d",&n);
  string name,status;
  int mon,day,h,m;
  rep(i,0,n){
    cin>>name;
    scanf("%d:%d:%d:%d",&mon,&day,&h,&m);
    cin>>status;

    v.pb(consumer(name,mon,day,h,m,status));
  }
  sort(v.begin(),v.end(),cmp);
  int t=v.size();
  rep(i,0,t){
      if(v[i].name==v[i-1].name && v[i].status=="off-line" && v[i-1].status=="on-line"){
        if(mp.count(v[i].name)==0) mp[v[i].name]=id++;
        cons[mp[v[i].name]].pb(v[i-1]);
        cons[mp[v[i].name]].pb(v[i]);
      }
  }
  rep(i,0,id){
     int t2=cons[i].size();
    cout<<cons[i][0].name;printf(" %02d\n",cons[i][0].mon);
    double ans=0;
     for(int j=1;j<t2;j+=2){
         cons[i][j-1].print();printf(" ");cons[i][j].print();
         printf(" %d ",get_time(cons[i][j])-get_time(cons[i][j-1]));
         double m=cal(cons[i][j])-cal(cons[i][j-1]);
         ans+=m;
         printf("$%.3lf\n",m);
     }
     printf("Total amount: $%.2lf\n",ans);
  }
return 0;
}
