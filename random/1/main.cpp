#include <iostream>
using namespace std;
int n,k;
int np0,npk,cnpk,cnp0;
int main()
{
    cin>>n>>k;
    npk = k-1;
    np0 = 0;
    for(int i=2;i<=n;i++){
     cnp0 = np0;
     cnpk = npk;
     np0 = npk;
     npk = cnp0*(k-1) + cnpk*(k-1);
 }
     cout<<npk+np0;
    return 0;
}
