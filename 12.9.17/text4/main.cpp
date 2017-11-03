#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char delim[4] = {'d','!','?','.' };
int n,nr;
int main()
{
    ifstream fin("text4.in");
    ofstream fout("text4.out");
    fin>>n;
    string x;
    getline(fin,x);
    cout<<x;


fin.close();
fout.close();
    return 0;
}
