#include <iostream>
using namespace std;
int rez = 0;
int ways(int a,int b){
   if(!a || !b) return 1;
   return 1 + ways(a-1,b);
   return 1 + ways(a,b-1);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<ways(a,b);

    return 0;
}
