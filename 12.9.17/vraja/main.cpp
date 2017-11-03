#include <iostream>
#include <fstream>
using namespace std;
int n,x[1001],rez;
void getSeq(int &a,int &b){
    a = 0;
    b = 0;
    int i;
    for(i=1;i<=n;i++){
        if(!a && x[i])
            a = i;
        else if(!x[i] && a){
            b = i-1;
            break;
        }
    }
    if(a && !b) b = n;
}
int smin(int a,int b){
    int i,minz=1000001;
    for(i=a;i<=b;i++)
        if(x[i] < minz)
          minz = x[i];
return minz;
}
void cut(int size,int a,int b){
    for(int i=a;i<=b;i++)
        x[i] = x[i] - size;
if(size) rez++;
}
int main()
{
    int i,j,minz;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>x[i];

    do{
        getSeq(i,j);
        minz = smin(i,j);
        cut(minz,i,j);
    } while(i && j);
cout<<rez;

    return 0;
}
