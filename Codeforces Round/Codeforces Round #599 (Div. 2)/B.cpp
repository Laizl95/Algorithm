#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;
//15:28
char s1[N],s2[N];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s %s",s1,s2);
        vector<pair<char,char> >v;
        rep(i,0,n)
            if(s1[i]!=s2[i]) v.pb(make_pair(s1[i],s2[i]));
        int m=v.size();
        cout<<m<<endl;
        if(m!=0 && m!=2) puts("No");
        else{
            if(m==0) puts("Yes");
            else{
                if(v[0].first==v[1].first && v[0].second==v[1].second) puts("Yes");
                else puts("No");
            }
        }
    }
return 0;
}

