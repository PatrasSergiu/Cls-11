#include <iostream>
using namespace std;
int n;
void rez(int n){
    if(n==1) {
        cout<<n<<" ";
        return;
    }
    rez(n-1);
    cout<<n<<" ";
    rez(n-1);
}
int main()
{
    int i;
    cin>>n;
    rez(n);
    return 0;
}
