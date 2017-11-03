#include <fstream>
#define nmax 6000001
using namespace std;

ifstream fin("ssm.in");
ofstream fout("ssm.out");

int ssm[nmax];

int main()
{
    int n,a,i=1,ci=1,resi=1,resj=1;
    fin>>n;
    fin>>a;
    ssm[i] = a;
    int rez = ssm[i];
    i++;
    while(fin>>a){
        if(ssm[i-1] >= 0)
            ssm[i] = ssm[i-1] + a;
        else {
            ssm[i] = a;
            ci = i;
        }
        if(ssm[i] > rez || (ssm[i] == rez && (i-ci) < (resj-resi))){
            rez = ssm[i];
            resj = i;
            resi = ci;
        }
        i++;
    }
    fout<<rez;
    fout<<" "<<resi<<" "<<resj;

    ///global
    int sp[nmax];
    for(i=1;i<=n;i++)
        sp[i] = sp[i-1] + x[i];

}


    return 0;
}
