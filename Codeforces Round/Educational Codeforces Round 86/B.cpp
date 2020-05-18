#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5,inf=1e9+5,mod=998244353;
typedef long long LL;
int n,m,k;
char s[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s),num1=0,num2=0,fi=-1;
        rep(i,0,len){
            if(s[i]=='0') {if(fi==-1)fi=0;num1++;}
            if(s[i]=='1') {if(fi==-1)fi=1;num2++;}
        }
        if(!num1 || !num2){
            printf("%s\n",s);
        }else{
            vector<char> ans;
            int x=max(num1,num2);
            rep(i,0,len){
                printf("%d%d",fi,1-fi);
            }
            puts("");
        }
    }
return 0;
}
