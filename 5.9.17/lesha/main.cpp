#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n,sol[101],nr;
int main()
{

    int s=0,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x == 0) continue;
        if(s + x == 0){
            sol[++nr] = i-1;
            s = x;
        }
        else {
            s += x;
        }

    }
    if(s!=0) {
        sol[++nr] = n;
    }
    if(!nr) cout<<"NO";
    else {
        cout<<"YES"<<'\n';
        cout<<nr<<'\n';
        int st = 1;
        for(int i=1;i<=nr;i++){
            cout<<st<<" "<<sol[i];
            cout<<'\n';
            st = sol[i] + 1;
        }
    }

    return 0;
}
