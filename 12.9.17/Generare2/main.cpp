#include <iostream>
#include <algorithm>
using namespace std;
int n,a,x,y,fr[10001];
const int MAX = 10000;
void ok(int b,int d);
void getElements(int b)
{
    ok(b,x);
    ok(b,y);
}

void ok(int b,int d){
    if((b+d) <= n)
        if(!fr[b+d]){
            fr[b+d]++;
            getElements(b+d);
        }
}

void print()
{
    for(int i=0; i<=MAX; i++)
        if(fr[i])
            cout<<i<<" ";
}

int main()
{
    cin>>n>>a>>x>>y;
    if(a <= n){
        fr[a]++;
        getElements(a);
    }
    print();
    return 0;
}
