#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("reteta.in");
ofstream fout("reteta.out");
int n,m;
int pret[21],fr[21],poz=0;
double sum,rsum=2000000;
struct reteta {
    int q;
    int comp;
    int med[300];
}; reteta e[30];

void input(){
    fin>>n>>m;
    for(int i=1;i<=m;i++){
        fin>>e[i].comp;
        fin>>e[i].q;
        for(int j=1;j<=e[i].q;j++)
            fin>>e[i].med[j];
    }
    for(int i=1;i<=n;i++)
        fin>> pret[i];
}

bool solved(){
    int i;
    for(i=1;i<=n;i++)
        if(!fr[i])
            return false;
    return true;
}

int ok(int j){
    int i,g=1;
    for(i=1;i<=e[j].q && g;i++)
        if(fr[e[j].med[i]])
            g=0;
    if(g){
        for(i=1;i<=e[j].q;i++){
            fr[e[j].med[i]] = 1;
            if(e[j].comp == 2)
                sum += (double)(pret[e[j].med[i]] / 2);
            else sum += (double)pret[e[j].med[i]];
        }
    }
return g;
}

void free(int j){
    for(int i=1;i<=e[j].q;i++){
        fr[e[j].med[i]] = 0;
        sum -= pret[e[j].med[i]];
    }
}

void bk(){
    if(pret[0] == m) {
               if(solved()){
                if(sum < rsum)
                    rsum = sum;
               }
                return;
    }
    for(int i=pret[0]+1;i<=m;i++)
      if(i > poz){
        if(ok(i)) {
            pret[0]++;
            bk();
            pret[0]--;
            free(i);
        }
        else {
            pret[0]++;
            bk();
            pret[0]--;
        }
      }

}
int main()
{
    input();
    bk();
    fout<<rsum;
    fin.close();
    fout.close();
    return 0;
}
