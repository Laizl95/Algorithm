#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=3005;
struct node{
 string name;
 int c,m,e,a;
 node(){}
 node(string _name,int _c,int _m,int _e):name(_name),c(_c),m(_m),e(_e){}
}stu[N];
map<string,pair<int,char> > mp;
bool cmpa(const node &a,const node &b){
      return a.a>b.a;
}
bool cmpc(const node &a,const node &b){
	 return a.c>b.c;

}
bool cmpm(const node &a,const node &b){
	 return a.m>b.m;
}
bool cmpe(const node &a,const node &b){
	 return a.e>b.e;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
            string name;int a,b,c;
        rep(i,0,n){
         cin>>name;
         scanf("%d %d %d",&a,&b,&c);
         stu[i]=node(name,a,b,c);
         stu[i].a=(a+b+c+1.5)*1.0/3;
        }
        int order=0,pre=-1;
        sort(stu,stu+n,cmpa);
        rep(i,0,n){
           if(stu[i].a!=pre) order=i+1,pre=stu[i].a;
           mp[stu[i].name]=make_pair(order,'A');

        }
        sort(stu,stu+n,cmpc);
        order=0,pre=-1;
        rep(i,0,n){
          pair<int,char> a=mp[stu[i].name];
          if(stu[i].c!=pre) order=i+1,pre=stu[i].c;
          if(a.first>order) mp[stu[i].name]=make_pair(order,'C');

        }
        sort(stu,stu+n,cmpm);
        order=0,pre=-1;
        rep(i,0,n){
          pair<int,char> a=mp[stu[i].name];
          if(stu[i].m!=pre) order=i+1,pre=stu[i].m;
          if(a.first>order) mp[stu[i].name]=make_pair(order,'M');

        }
        sort(stu,stu+n,cmpe);
         order=0,pre=-1;
        rep(i,0,n){
          pair<int,char> a=mp[stu[i].name];
          if(stu[i].e!=pre) order=i+1,pre=stu[i].e;
          if(a.first>order) mp[stu[i].name]=make_pair(order,'E');

        }
        rep(i,0,m){
         cin>>name;
         if(mp.count(name)) printf("%d %c\n",mp[name].first,mp[name].second);
         else puts("N/A");
        }
    }
}
