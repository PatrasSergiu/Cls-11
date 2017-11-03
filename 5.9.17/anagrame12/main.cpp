#include <fstream>
using namespace std;
ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");
int n,x[30],sol[30];
void input(){
    fin>>n;
    char c;
    for(int i=1;i<=n;i++){
        fin>>c;
        x[i] = c;
    }
}
void srt(){
    int i,j;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(x[i] > x[j])
                swap(x[i],x[j]);
}
void print(){
    for(int i=1;i<=n;i++)
        fout<<(char)sol[i];
fout<<'\n';
}
int ok(int d){
    for(int i=1;i<=sol[0];i++)
        if(d == sol[i])
            return 0;
    return 1;
}
void bk(){
    if(sol[0] == n){
            print();
            return;
    }
    for(int i=1;i<=n;i++){
        if(ok(x[i])){
            sol[++sol[0]] = x[i];
            bk();
            sol[0]--;
        }
    }
}
int main()
{
    input();
    srt();
    bk();
    return 0;

}
