#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=1005;
int a[N];
struct node{
    int l,r,x;
    node(){}
    node(int _l,int _r,int _x){l=_l;r=_r;x=_x;}
}s[N];
int tot;
int build(int num,int l,int r,int ok){

        if(l>r){
            int id=tot;++tot;
            s[id]=node(-1,-1,num);
            return id;
        }
        int l1=-1,r1=-1,l2=-1,r2=-1;
        rep(i,l,r+1)
            if(ok && a[i]>=num){l1=l;r1=i-1;l2=i;r2=r;break;}
            else if(!ok && a[i]<num) {l1=l;r1=i-1;l2=i;r2=r;break;}
        int id=tot; ++tot;
        //cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<num<<endl;
        s[id]=node(-1,-1,num);
        if(l1<=r1)
            s[id].l=build(a[l1],l1+1,r1,ok);
        if(l2<=r2)
            s[id].r=build(a[l2],l2+1,r2,ok);
        return id;
}
int judge(int root){
    if(root==-1) return 0;
    int v=s[root].x;
    int v_l=judge(s[root].l),v_r=judge(s[root].r);
    if(v_l==-1 || v_r==-1) return -1;
    if(v_l>=v) return -1;
    if(v_r!=0 && v_r<v) return -1;
    return max(v_r,v);
}
void solve(int root,int p){
    if(root==-1) return;
    solve(s[root].l,p);
    solve(s[root].r,p);
    if(root==p) printf("%d",s[root].x);
    else printf("%d ",s[root].x);
    return;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        tot=0;
        rep(i,0,n) scanf("%d",&a[i]);
        if(n==1){puts("YES");printf("%d\n",a[0]);continue;}
        build(a[0],1,n-1,1);
        if(judge(0)!=-1){
            puts("YES");solve(0,0);puts("");continue;
        }
        build(a[0],1,n-1,0);
        if(judge(0)!=-1){
            puts("YES");solve(0,0);puts("");continue;
        }
        puts("NO");
    }
return 0;
}
