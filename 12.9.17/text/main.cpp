#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n;
int poz=0,g=0;
string v;
char del[4] = {'d','.','!','?'};
int in(char x){
    for(int i=1;i<4;i++)
        if(x == del[i])
            return 0;
return 1;
}
void advnce(int i){
   int nr = 0;
    while(isalpha(v[i])){
        i++;
        nr++;
    }
    i++;
    if(in(v[i]))
        g=1;
    return nr;
}

int main()
{
    ifstream fin("text4.in");
    ofstream fout("text4.out");
    fin>>n;
    fin.get();
    int i,nr;
    while(getline(fin,v)){
         i = poz;
         nr = 0;
        while(i<v.length()){
            int s = advnce(i);
            if((nr+s)==n){
                i = i + nr;
                for(int j=linie;j<=)
            }
        }








    }
    return 0;
}
