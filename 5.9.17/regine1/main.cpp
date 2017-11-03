#include <iostream>
using namespace std;
int n,x[11][11];
void print(){
    int i,j;
    for(i=1;i<=n;i++,cout<<'\n')
        for(j=1;j<=n;j++)
            if(x[i][j] == 0)
                cout<<"-";
            else cout<<"*";
    n=0;
}
int possible(int a,int b){
    int i,j;
    for(i=1;i<=n;i++)
        if(x[a][i] == 1)
            return false;
    for(i=1;i<=n;i++)
        if(x[i][b] == 1)
            return false;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if((i+j) == (a+b) || (i-j) == (a-b)){
                    if((i!=a || j != b) && x[i][j] == 1)
                        return false;
        }
    return true;
}
void bk(int l){
    if(l > n){
        if(n)
            print();
        return;
    }
    for(int j=1;j<=n;j++)
        if(possible(l,j)){
            x[l][j]++;
            bk(l+1);
            x[l][j]--;
        }
}
int main()
{
    cin>>n;
    bk(1);
    return 0;
}
