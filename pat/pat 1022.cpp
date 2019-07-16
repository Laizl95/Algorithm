#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define per(i,x,y) for(int i=y-1;i>=x;--i)
#define ms(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
using namespace std;
const int N=10005;
struct node{
 int id,year;
 char name[85],author[85],publisher[85];
 vector<string> key;
 void print(){
   printf("name=%s\nauthor:%s\npub:%s\n",name,author,publisher);
   rep(i,0,key.size())cout<<key[i]<<endl;
 }
}book[N];
//map<string,int> book_name,author,key,publisher;
void solve(map<string,int> *_mp,char name[],int &id,int x,vector<int> v[]){
    string str=name;
    if((*_mp).count(str)==0) (*_mp)[str]=id;
    id+=1;
    //cout<<str<<" "<<(*_mp)[str]<<endl;
    v[(*_mp)[str]].pb(x);
}
void prints(vector<int> v[],int id){
     if(id==0)puts("Not Found");
     rep(i,0,v[id].size()) printf("%07d\n",v[id][i]);
}
void sorts(vector<int> v[],int tot){
       rep(i,0,tot){
         sort(v[i].begin(),v[i].end());
       }
}
int main(){
    //freopen("d://output.txt","w",stdout);
    int n,m,id_b,id_a,id_k,id_p,id_l;
    map<string,int> book_name,author,key,publisher;
    map<int,int> year;
    vector<int> v_book_name[N],v_author[N],v_key[N],v_publisher[N],v_year[N];
    char buffer[105];

    while(scanf("%d\n",&n)!=EOF){

            id_b=id_a=id_k=id_p=id_l=1;
        rep(i,0,n){
            scanf("%d\n%[^\n]\n%[^\n]",&book[i].id,book[i].name,book[i].author);
            scanf("\n%[^\n]",buffer);
            int len=strlen(buffer);
            string a;
            rep(j,0,len+1){
              if(j==len || buffer[j]==' ')
                {book[i].key.pb(a),a.clear();continue;};
              a+=buffer[j];
            }
            scanf("\n%[^\n] %d",book[i].publisher,&book[i].year);
            //book[i].print();
            solve(&book_name,book[i].name,id_b,book[i].id,v_book_name);
            solve(&author,book[i].author,id_a,book[i].id,v_author);
            solve(&publisher,book[i].publisher,id_p,book[i].id,v_publisher);
            rep(j,0,book[i].key.size()){
                if(key.count(book[i].key[j])==0) key[book[i].key[j]]=id_l++;
                v_key[key[book[i].key[j]]].pb(book[i].id);
                //solve(&key,book[i].key[j],id_k,book[i].id,v_key);
            }//cout<<book[i].year<<endl;
            if(year.count(book[i].year)==0) year[book[i].year]=id_k++;
                v_year[year[book[i].year]].pb(book[i].id);
        }
        sorts(v_book_name,id_b);
        sorts(v_author,id_a);
        sorts(v_publisher,id_p);
        sorts(v_key,id_l);
        sorts(v_year,id_k);
        scanf("%d",&m);
        int id;
        rep(i,0,m){
           scanf("%d: %[^\n]",&id,buffer);
           printf("%d: %s\n",id,buffer);
           if(id==1){
                int t=book_name[buffer];
              prints(v_book_name,t);
           }else if(id==2){
                int t=author[buffer];
                prints(v_author,t);
           }else if(id==3){
                int t=key[buffer];
                prints(v_key,t);
           }else if(id==4){
                 int t=publisher[buffer];
                prints(v_publisher,t);
           }else{
               int t=0;
               rep(i,0,strlen(buffer)) t=t*10+buffer[i]-'0';
                prints(v_year,year[t]);
           }
        }
    }
    return 0;
}
