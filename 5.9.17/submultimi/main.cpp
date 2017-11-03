#include <fstream>
using namespace std;
int n,sol[18];
ifstream fin("submultimi.in");
ofstream fout("submultimi.out");
void afisare(){
    for(int i=1;i<=sol[0];i++)
        fout<<sol[i]<<" ";
    if(sol[0]) fout<<'\n';
}
void bk(){
    if(sol[0] == n) return;
    for(int i=sol[0]+1;i<=n;i++){
        if(i > sol[sol[0]]){
            sol[++sol[0]] = i;
            afisare();
            bk();
            sol[0]--;
        }

    }
}
int main(){
    fin>>n;
    bk();
    return 0;
}
