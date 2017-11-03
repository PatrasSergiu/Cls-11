#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int n,gmax;
struct obiect {
    int g;
    int v;
    double rat;
};
obiect e[1005];
bool cmp(obiect a,obiect b){
    if(a.rat==b.rat)
        return (a.v > b.v);
    else
        return (a.rat > b.rat);
}
void input(){
    freopen("rucsac.in","r",stdin);
    cin>>n>>gmax;
    int a,b;
    for(int i=0;i<n;i++){
       cin>>a>>b;
       e[i].g = a;
       e[i].v = b;
       e[i].rat = (double)b/a;
    }
}
int main()
{
    input();
    sort(e,e+n,cmp);
    int gc = 0,i=0;
    double val = 0;
     while(gc < gmax && i < n){
        if((gc+e[i].g) <= gmax){
            gc+=e[i].g;
            val+=e[i].v;
            }
        else {
            int r = gmax - gc;
            val = val + (r*e[i].rat);
            gc = gmax;
        }
        i++;
    }

    cout<<val;
    return 0;
}
