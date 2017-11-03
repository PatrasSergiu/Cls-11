#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(abs(a-b) >= 2)
        cout<<"NO";
    else cout<<"YES";
    return 0;
}
