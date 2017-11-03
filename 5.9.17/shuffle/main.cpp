#include <fstream>
#include <vector>
using namespace std;
vector <pair<int,int> > q;
ifstream fin("shuffle.in");
ofstream fout("shuffle.out");
int n,x[10],cx[10],sol[10],g;
void init(){
    fin>>n;
    int i;
    for(i=1;i<=n;i++)
        fin>>x[i];
    for(i=1;i<=n;i++){
        if(i==1){
            q.push_back({0,x[i+1]});
        }
        else if(i==n){
            q.push_back({x[i-1],0});
        }
            else {
                q.push_back({x[i-1],x[i+1]});
            }
    }
}
void print(){
    for(int i=1;i<=n;i++)
        fout<<sol[i]<<" ";
    fout<<'\n';
    g=1;
}
int ok(int d){
    if(sol[0]){
        for(int i=1;i<=n;i++)
            if(d == cx[i]){
                if((sol[sol[0]] == q[i-1].first) || (sol[sol[0]] == q[i-1].second))
                    return 0;
                else return 1;
            }
        }
return 1;
}
int free(int d){
    if(!sol[0]) return 1;
    for(int i=1;i<=sol[0];i++)
        if(d == sol[i])
            return 0;
    return 1;
}
void bk(){
    if(sol[0] == n) {
        print();
        return;
    }
    for(int i=1;i<=n;i++){
        if(free(x[i]))
            if(ok(x[i])){
                sol[++sol[0]] = x[i];
                bk();
                sol[0]--;
            }
        }
}
void srt(){
    int i,j;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(x[i] > x[j])
                swap(x[i] , x[j]);
}
void duplicate(){
    for(int i=1;i<=n;i++)
        cx[i] = x[i];
}
int main()
{
    init();
    duplicate();
    srt();
    bk();
    if(!g) fout<<"nu exista";
    return 0;
}
