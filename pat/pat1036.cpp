#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
typedef long long  LL;
const int N=100005;
struct stu{
    char name[15],id[15];
    char c;
    int score;
    stu(){}
    stu(char _name[],char _c,char _id[],int _score){
        strcpy(name,_name);strcpy(id,_id);c=_c;
        score=_score;
    }
};
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        char name[15],id[15];char c;int score;
        stu female,male;
        female.score=-1;male.score=101;
        rep(i,0,n){
            scanf("%s %c %s %d",name,&c,id,&score);
            if(c=='F' && score>female.score)
                female=stu(name,c,id,score);
            else if(c=='M' && score<male.score)
                male=stu(name,c,id,score);
        }
        if(female.score==-1) puts("Absent");
        else printf("%s %s\n",female.name,female.id);
        if(male.score==101) puts("Absent");
        else printf("%s %s\n",male.name,male.id);
        if(male.score==101 || female.score==-1) puts("NA");
        else printf("%d\n",female.score-male.score);
    }
return 0;
}
