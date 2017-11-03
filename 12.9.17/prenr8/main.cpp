#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
int n,sol[18],sol2[18],x[18];
int s1,s2,nr,fr[100];
ifstream fin("in.in");
void afisare(){
    for(int i=1;i<=sol[0];i++)
        cout<<sol[i]<<" ";
    if(sol[0]) cout<<'\n';
}


void dr(){
      if(sol2[0] == n) return;
        for(int i=sol2[0]+1;i<=n;i++){
        if(x[i] > sol2[sol2[0]]){
            sol2[++sol2[0]] = x[i];
            s2 += sol2[sol2[0]];
//            if(s1 == s2 && !eq()) nr++;
            dr();
            s2 -= sol2[sol2[0]];
            sol2[0]--;
        }

    }
}


void st(){
    if(sol[0] == n) return;
    for(int i=sol[0]+1;i<=n;i++){
        if(x[i] > sol[sol[0]]){
            sol[++sol[0]] = x[i];
            fr[x[i]] = 1;
            cout<<x[i];
            s1 += sol[sol[0]];
           // dr();
            st();
            s1 -=sol[sol[0]];
            fr[x[i]] = 0;
            sol[0]--;
        }

    }
}

int main(){
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>x[i];
sort(x+1,x+n);
    st();
    cout<<nr;
    return 0;


}
