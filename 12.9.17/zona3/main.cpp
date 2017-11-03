#include <fstream>
#include <queue>
using namespace std;
int n,m,x[101][101],nr=1;
queue <pair<int,int> > q;
const int di[] = { -1, 0, 1, 0 },
          dj[] = { 0, 1, 0, -1 };
void input(){
    ifstream fin("zona3.in");
    fin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>x[i][j];
    fin.close();

}
void print(){
    ofstream fout("zona3.out");
    int i,j;
    for(i=1;i<=n;i++ , fout<<'\n')
        for(j=1;j<=m;j++)
            fout<<x[i][j]<<" ";
    fout.close();
}
bool ok(int i,int j){
    if(i > n || i < 1 || j > m || j < 1)
        return false;
return true;
}
void cnt(){
    x[q.front().first][q.front().second] = -1;
    for(int i,j,iv,jv;!q.empty(); ){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int d = 0; d<4; d++){
            iv = i + di[d];
            jv = j + dj[d];
            if(ok(iv,jv) && x[iv][jv] == 1){
                nr++;
                q.push({iv,jv});
                  x[iv][jv] = -1;
            }
        }

    }
}
void fil(){
    for(int i,j,iv,jv; !q.empty(); ){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        x[i][j] = nr;
        for(int d = 0; d<4; d++){
            iv = i + di[d];
            jv = j + dj[d];
            if(ok(iv,jv) && x[iv][jv] == -1){
                q.push({iv,jv});
            }
        }
    }
}
int main()
{
   int i,j;
   input();
   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(x[i][j] == 1){
            q.push({i,j});
            cnt();
            q.push({i,j});
            fil();
            nr = 1;
        }
    print();
    return 0;
}
