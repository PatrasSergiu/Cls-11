#include <fstream>
using namespace std;
ifstream fin("submultimi.in");
ofstream fout("submultimi.out");
int x[30];
int main()
{
    int n;
    fin >> n;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int i=1;i<(1<<n);i++,fout<<'\n')
        for(int j=0;j<n;j++)
            if(i&(1<<j))  fout<<(x[j+1])<<" ";
}
