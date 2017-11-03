#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("inel.in");
ofstream fout("inel.out");
int n,x[20],fr[20],r;
int p[36] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0};
void bk(){
    if(x[0] == n){
         if(p[1+x[n]])
            r++;
         return;
    }
    for(int i=2;i<=n;i++)
        if((p[i+x[x[0]]]==1) && !fr[i]){
                x[++x[0]] = i;
                fr[i] = 1;
                bk();
                x[0]--;
                fr[i] = 0;
            }
}

int main()
{
    ifstream fin("inel.in");
    ofstream fout("inel.out");
    fin>>n;
    fr[1] = 1;
    x[++x[0]] = 1;
    bk();
    fout<<r;
    fin.close();
    fout.close();
    return 0;
}
