#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
vector <pair<int,int> > q;
ifstream fin("spectacole.in");
ofstream fout("spectacole.out");
int n;
int main()
{
    fin>>n;
    int a,b;
    for(int i=1;i<=n;i++){
        fin>>a>>b;
        q.push_back({b,a});
    }
    sort(q.begin(),q.end());
    int start = 0, rez = 0;
    for(int i=0;i<n;i++)
        if(q[i].second >= start){
            start = q[i].first;
            rez++;
        }
    fout<<rez;
    fin.close();
    fout.close();
    return 0;
}
