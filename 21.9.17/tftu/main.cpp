#include <iostream>
#include <fstream>
using namespace std;
ifstream peste("numere.txt");
int main()
{
    int n,a,b,c;
    cout<<"n=" , cin>>n;
    a=1;
    b=1;
    n=n-2; cout<<1<<" "<<1;
    c=0;
    while(n!=0)
    {c=a+b;
    n--;
    a=b;
    b=c; cout<<c<<" ";
    }


    return 0;
}
