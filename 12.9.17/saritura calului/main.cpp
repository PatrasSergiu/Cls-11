#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("saritura_calului1.in");
ofstream fout("saritura_calului1.out");
int a[101][101],n,m;
int g=1;
void print(){
    if(g){
        int i,j;
        for(i=1;i<=n;i++,fout<<'\n')
            for(j=1;j<=m;j++)
                fout<<a[i][j]<<" ";
        g=0;
    }
}

bool ok(int i,int j){
    if(i < 1 || j < 1 || i > n || j > m)
        return false;
return true;
}

void bk(int pas,int i,int j){
    if(!g) return;
    if(ok(i,j) && a[i][j] == 0){
        a[i][j] = pas;
        if((n*m) == pas) print();
        else {
            bk(pas+1,i-2,j-1);
            bk(pas+1,i-2,j+1);
            bk(pas+1,i-1,j+2);
            bk(pas+1,i+1,j+2);
            bk(pas+1,i+2,j+1);
            bk(pas+1,i+2,j-1);
            bk(pas+1,i+1,j-2);
            bk(pas+1,i-1,j-2);
        }
        a[i][j] = 0;
    }

}

int main()
{
    int x,y;
    fin>>n>>m>>x>>y;
    bk(1,x,y);
    fin.close();
    fout.close();
    return 0;
}
