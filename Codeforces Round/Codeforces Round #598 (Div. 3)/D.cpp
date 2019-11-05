#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1e6+5,inf=1e9+5;
typedef long long LL;
char s[N];

int main(){
    int t,n;LL k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %lld",&n,&k);
        scanf("%s",s);
        vector<int> v;
        rep(i,0,n){
            if(s[i]=='0') v.pb(i);
        }
        int now=0;
        rep(i,0,v.size()){
            int step=v[i]-now;

            if(k>=step){
                k-=step;
                swap(s[now],s[v[i]]);
            }else{
                int pos=-1;
                rep(j,v[i]-k,v[i]) if(s[j]=='1'){pos=j;break;}
                if(pos!=-1)  swap(s[pos],s[v[i]]);
                break;
            }
            now+=1;
        }
        printf("%s\n",s);
    }
return 0;
}
