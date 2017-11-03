#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int x[1025][1025],n;
void print(){
    int i,j;
    for(i=1;i<=n;i++,cout<<'\n')
        for(j=1;j<=n;j++)
            cout<<x[i][j]<<" ";
}
void fil(int i,int j, int l){
    int a,b;
    for(a=i;a<i+l;a++)
        for(b=j;b<j+l;b++)
            x[a][b] = 1;
}
void choose(int i,int j,int l){
    if(l<1) return;
    fil(i,j,l);
    choose(i,j+l,l/2);
    choose(i+l,j,l/2);
    choose(i+l,j+l,l/2);
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>n;
    int l = pow(2.0,n);
    n = l;
    l = l/2;
    choose (1,1,l);
    print();
    return 0;
}
