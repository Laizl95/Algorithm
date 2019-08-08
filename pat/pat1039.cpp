#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=500005;
vector<int> v[N];
map<string,int> mp;
int main(){
    int n,k;

    while(scanf("%d %d",&n,&k)!=EOF){
        int id,m,tot=1;

        string name;
        rep(j,0,k){
            scanf("%d %d",&id,&m);
            rep(i,0,m){
                cin>>name;
                if(!mp.count(name)) mp[name]=tot++;
                v[mp[name]].pb(id);
            }
        }
        rep(i,0,n){
            cin>>name;
            int t=mp[name];
            sort(v[t].begin(),v[t].end());
            cout<<name<<" "<<v[t].size();
            rep(j,0,v[t].size()){
                printf(" %d",v[t][j]);
            }puts("");
        }
    }
return 0;
}
