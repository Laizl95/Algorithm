#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
using namespace std;
const int N=1e2+5,inf=1e9+5;
typedef long long LL;

int n,m;
string s;
int solve(int k,int n,char x,int &tot){

    if(k<n && k>=0 && s[k]==x){
        tot+=1;
        s.erase(k,1);
        return 1;
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&n);
    cin>>s;
    int ok=1,tot=0;
    per(i,0,26){
        ok=1;
        while(ok){
                ok=0;
            n=s.length();
            rep(j,0,n){
                if(s[j]=='a'+i){
                   ok=solve(j+1,n,s[j]+1,tot);
                   if(ok) break;
                   ok=solve(j-1,n,s[j]+1,tot);
                }
                 if(ok) break;
            }
        }
    }
    cout<<tot<<endl;
return 0;
}
