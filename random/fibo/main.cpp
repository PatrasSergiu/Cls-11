#include <iostream>
#define nmax 100000000
using namespace std;

unsigned long long fibo[nmax];
int n;

void solve(){
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2;i<=n;i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
}

int main()
{
    cout<<"N=" , cin>>n;
    solve();
    cout<<fibo[n];
    return 0;
}
