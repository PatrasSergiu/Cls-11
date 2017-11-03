#include <iostream>
#include <fstream>
using namespace std;
int n,a,x,y,sol[100001],l;
void getElements(int d){
    int c = d;
    while(d+x <= n){
        sol[++l] = d+x;
        d+=x;
    }
    d = c;
    while(d+y <= n){
        sol[++l] = d+y;
        d+=y;
    }
}
void srt(){
    int i,j;
    for(i=1;i<l;i++)
        for(j=i+1;j<=l;j++)
            if(sol[i] > sol[j])
                swap(sol[i],sol[j]);
}
void print(){
    for(int i=1;i<=l;i++)
        cout<<sol[i]<<" ";
}
int main()
{
    freopen("generare2.in","r",stdin);
    cin>>n>>a>>x>>y;
    sol[++l] = a;
    getElements(a);
    srt();
    print();
    return 0;
}
