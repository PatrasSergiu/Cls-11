#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
ofstream fout("flici.out");
vector <int> f,g;
int n;
void input(){
    ifstream fin("flici.in");
    fin>>n;
    int i,x;
    for(i=1;i<=n;i++){
        fin>>x;
        f.push_back(x);
        }
    for(i=1;i<=n;i++){
        fin>>x;
        g.push_back(x);
        }
}
int main()
{
    input();
    sort(f.begin(),f.end());
    sort(g.begin(),g.end());
    int s=0;
    for(int i=0;i<n;i++)
        s+= abs(f[i]-g[i]);
    fout<<s;
   /* for(int i=0;i<n;i++)
        fout<<f[i]<<" ";
    fout<<'\n';
    for(int i=0;i<n;i++)
        fout<<g[i]<<" ";
    */
    return 0;
}
