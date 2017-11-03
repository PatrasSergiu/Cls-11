#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("numere8.in");
ofstream fout("numere8.out");
int x[11],a[11],b[11],na,nb;
int n = 10,nr = 0,g=1;
int s1,s2,rs=-1;
void input(){
    for(int i=1;i<=n;i++)
        fin>>x[i];

}

void reCreate(int i,int j){
    na = 0;
    nb = 0;
    for(int k=0;k<n;k++){
        if(i & (1<<k))
            a[++na] = x[k+1];
        if(j & (1<<k))
            b[++nb] = x[k+1];
    }
}

int main()
{
    input();
    int i,j,k,z;
    for(i=1;i<(1<<n);i++){
        s1 = 0;
        for(k=0;k<n;k++)
            if(i & (1<<k))
                s1  += x[k+1];
        for(j = i+1; j<(1<<n); j++){
                s2=0;
                if((i & j) == 0){
                    for(k=0;k<n;k++)
                        if(j & (1<<k))
                            s2 += x[k+1];
                }
                if(s1 == s2) {
                        nr++;
                        if(s1 > rs){
                            rs = s1;
                            reCreate(i,j);
                        }
                }
        }
    }
    fout<<nr<<" "<<rs<<'\n';
    for(i=1;i<=na;i++)
        fout<<a[i]<<" ";
    fout<<'\n';
    for(i=1;i<=nb;i++)
        fout<<b[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
