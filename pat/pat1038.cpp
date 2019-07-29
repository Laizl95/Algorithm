#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005;
char a[N][15];
struct node{
    int v_4;char v[15];
    bool operator <(const node &a) const{
    return v_4<a.v_4;
    }

}b[N];
void get(int i){
   int len=strlen(a[i]),x=0;
   rep(j,0,len) x=x*10+(a[i][j]-'0');
   strcpy(b[i].v,a[i]);
   int j=len,p=0;
   while(j<8){
     x=x*10+(a[i][p]-'0');
     p=(p+1)%len;j+=1;
   }
   b[i].v_4=x;
   //printf("%s %d\n",b[i].v,b[i].v_4);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,0,n){
            scanf("%s",a[i]);
            get(i);
        }
        sort(b,b+n);
        vector<char> ans;
        rep(i,0,n) rep(j,0,strlen(b[i].v)) ans.pb(b[i].v[j]);
        int len=ans.size(),p=0;
        while(p<len && ans[p]=='0') p+=1;
        rep(j,p,len) printf("%c",ans[j]);
        if(p==len) printf("0");
        puts("");
    }
return 0;
}
