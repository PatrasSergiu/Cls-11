#include <iostream>
#include<fstream>
using namespace std;
ifstream f("fisier.txt");
ofstream g("raspuns.txt");
ofstream g("raspuns.txt");
int main()
{ int n,c,c1,inv,rez1,rez2;
f>>n;
c=n;
int ok = 0;
while(ok==0)
   { c--;
    c1=c;
    inv=0;
   while(c1>0)
   {inv=inv*10+c1%10;
   c1=c1/10;
   }
   if(c==inv)
    ok=1;
   }
rez1=c;
ok=0;
c=n;
while(ok==0)
   { c++;
    c1=c;
    inv=0;
   while(c1>0)
   {inv=inv*10+c1%10;
   c1=c1/10;
   }
   if(c==inv)
    ok=1;
   }
rez2 = c;
if((n-rez1)<(rez2-n))
    g<<rez1;
else
    g<<rez2;
f.close();
g.close();
    return 0;
}
