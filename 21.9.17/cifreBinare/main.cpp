#include <iostream>

using namespace std;

int main()
{
   int a,b;
   cin>>a>>b;
   int ra=0,rb=0;
    for(int i=1;i<(1<<a);i++)
        for(int j=0;j<a;j++)
            if(i & (1<<j))
                ra++;
    cout<<ra;
   /*if(ra==rb) cout<<min(a,b);
   else if(ra>rb) cout<<a;
        else cout<<b;
    */
    return 0;
}
