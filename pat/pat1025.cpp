#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=105;
struct stu{
    int score,group_id,rank1,rank2;
    char id[15];
    bool operator < (const stu &a)const{
       if(score!=a.score) return score>a.score;
       return strcmp(id,a.id)<0;
    }
}s[3*N*N];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
            int k,sd=0;
        rep(i,0,n){
            scanf("%d",&k);
            rep(j,0,k){
                scanf("%s %d",s[sd+j].id,&s[sd+j].score);
                s[sd+j].group_id=i+1;
            }
            sort(s+sd,s+k+sd);
            int ranks=1,pre=s[sd].score;
            rep(j,0,k){
                if(s[sd+j].score!=pre)  ranks=j+1,pre=s[sd+j].score;
                s[sd+j].rank2=ranks;
            }
            sd=sd+k;
            //rep(j,0,k) printf("%s %d\n",s[i][j].id,s[i][j].score);
        }
        sort(s,s+sd);
        int ranks=1,pre=s[0].score;
        rep(i,0,sd){
            if(s[i].score!=pre)  ranks=i+1,pre=s[i].score;
            s[i].rank1=ranks;
        }
        printf("%d\n",sd);
        rep(i,0,sd) printf("%s %d %d %d\n",s[i].id,s[i].rank1,
                           s[i].group_id,s[i].rank2);
    }
return 0;
}
