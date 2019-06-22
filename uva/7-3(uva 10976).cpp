#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define per(i,x,y) for(int i=y;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
typedef long long LL;
using namespace std;
vector<pair<int,int> > v;
int main(){
    int t=0;
    int s=t?2:-2;
    cout<<s<<endl;
int k;
while(scanf("%d",&k)!=EOF){
    int y=k+1,num=0,x=k*y;//cout<<y<<" "<<x<<endl;
    v.clear();
    while(true){
     if((k*y)%(y-k)==0){
        ++num;
        v.push_back(make_pair((k*y)/(y-k),y));
        if((k*y)/(y-k)==y) break;
     }
     ++y;
    }
    printf("%d\n",num);
    y=v.size()-1;
    rep(i,0,y){
    printf("1/%d = 1/%d + 1/%d\n",k,v[i].first,v[i].second);
    }
}
return 0;
}
