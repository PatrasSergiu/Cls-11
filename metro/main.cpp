#include <iostream>
#include <cmath>
#define NMAX 10001
using namespace std;
double a[NMAX][NMAX];
bool diag[NMAX][NMAX];
int n,m,k;
int main()
{
    cin>>n>>m;
    cin>>k;
    int i,j,x,y;

    for(i=1;i<=k;i++){
        cin>>x>>y;
        diag[x][y] = true;
    }
    ///
    for(i=1;i<=n;i++)
        a[i][0] = a[i-1][0] + 100;
    for(j=1;j<=m;j++)
        a[0][j] = a[0][j-1] + 100;
    ///

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
           a[i][j] = min(a[i-1][j],a[i][j-1]) + 100;
           if(diag[i][j]){
                a[i][j] = min(a[i][j],a[i-1][j-1]+100*sqrt(2));
           }
    }
    cout<<round(a[n][m]);
    return 0;
}
