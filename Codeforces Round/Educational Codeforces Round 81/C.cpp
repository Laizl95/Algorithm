#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N=3e5+5,inf=1e9+5;
typedef long long LL;
char s[N],a[N];
int n,m;
int solve(int pre,const vector<int> &v,int k){
    int y=v.size()-1;
    int l=k,r=y;
    while(l<=r){
        int mid=(l+r)>>1;
        if(v[mid]>pre) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",s,a);
        vector<int> v[35];
        int len=strlen(s);
        int now[35]={0};
        ms(now,-1);
        rep(i,0,len){
            v[s[i]-'a'].pb(i);
        }
        len=strlen(a);
        //cout<<len<<" "<<strlen(s)<<endl;
        int pre=-1,ans=0,i=0;
        while(i<len){
            int x=a[i]-'a';int y=v[x].size();
            int p=solve(pre,v[x],now[x]+1);
            if(p<y){
                if(pre==-1) ans+=1;
                pre=v[x][p];
                now[x]=p;
                ++i;
            }
            else{
                if(pre==-1){ans=-1;break;}
                pre=-1;
                ms(now,-1);
            }
        }

        printf("%d\n",ans);
    }
return 0;
}
