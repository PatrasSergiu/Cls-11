#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("permutari2.in");
ofstream fout("permutari2.out");
int n,x[15],sol[15];
void afisare(){
    for(int i=1;i<=sol[0];i++)
        fout<<sol[i]<<" ";
fout<<'\n';
}
bool ok(int x){
    for(int i=1;i<=sol[0];i++)
        if(x == sol[i])
            return false;
    return true;
}
void srt(){
    int i,j;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(x[i] > x[j])
                swap(x[i],x[j]);
}
void bk(){
    if(sol[0] == n) {
        afisare();
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
    int i;
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>x[i];
    srt();
    bk();
    return 0;
}
