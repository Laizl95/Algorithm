#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=2e5+5,inf=1e9+5;
typedef long long LL;

int n,m;
string s;
vector<int> v1,v2;
int main(){
    cin>>s;
    int tot=0;
    int l=0,r=s.length()-1;
    while(l<r){
        if(s[l]=='(' && s[r]==')'){
            v1.pb(l);
            v2.pb(r);
            l++;r--;
        }else if(s[l]==')') l++;
        else if(s[r]=='(') r--;
    }
    if(v1.size()==0){puts("0");return 0;}
    puts("1");
    printf("%d\n",v1.size()*2);
    for(auto it:v1) printf("%d ",it+1);
    per(i,0,v2.size()) printf("%d ",v2[i]+1);puts("");

return 0;
}
