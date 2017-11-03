#include <fstream>
#include <stdlib.h>
using namespace std;
ifstream fin("sirab.in");
ofstream fout("sirab.out");
int s,n,g,sol[10];
void print(){
    for(int i=1;i<=n;i++)
        fout<<sol[i]<<" ";
    fout<<'\n';
g=1;
}
int ok(int d){
    for(int i = 1; i<=sol[0];i ++)
        if(((sol[i]+d) % abs(sol[i]-d)) != 0)
            return false;
    return true;
}
void bk(){
    if(sol[0] == n){
        print();
        return;
    }
    for(int i=sol[sol[0]]+1;i<=s;i++)
        if(ok(i)){
            sol[++sol[0]] = i;
            bk();
            sol[0]--;
        }
}
int main()
{
    fin>>s>>n;
    bk();
if(!g) fout<<0;
    return 0;
}
