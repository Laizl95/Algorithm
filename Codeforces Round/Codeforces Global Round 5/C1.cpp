#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
int n;
struct node{
    int x,y,z,id;
    node(){}
    node(int _x,int _y,int _z,int _id){
        x=_x;y=_y;z=_z;id=_id;
    }
};
LL get_dis(node a,node b){
    return 1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y)+1LL*(a.z-b.z)*(a.z-b.z);
}
vector<node> a;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
            int x,y,z;
        rep(i,0,n){
            scanf("%d %d %d",&x,&y,&z);
            a.pb(node(x,y,z,i+1));
        }
        rep(i,0,n/2){
            LL dis=-1;int id;
            rep(i,1,a.size()){
                LL x=get_dis(a[0],a[i]);
                if(dis==-1 || x<dis)
                    id=i,dis=x;
            }
            printf("%d %d\n",a[0].id,a[id].id);
            a.erase(a.begin());
            a.erase(a.begin()+id-1);
        }
    }
return 0;
}
