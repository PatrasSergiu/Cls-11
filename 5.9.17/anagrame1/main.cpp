#include <fstream>
#include <string.h>
using namespace std;
char s[11],sol[11];
int n;
ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");
void srt(){
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(s[i] > s[j]){
                swap(s[i],s[j]);
            }
}
int ok(char x,int l){
        for(int i=0;i<l;i++)
            if(x == sol[i]) return 0;
    return 1;
}
void print(){
    for(int i=0;i<n;i++)
        fout<<sol[i];
    fout<<'\n';
}
void bk(int l){
    if(l == n){
            print();
            return;
    }
    for(int i=0;i<n;i++){
        if(ok(s[i],l)){
            sol[l] = s[i];
            bk(l+1);
        }
    }
}
int main()
{
    fin.getline(s,10);
    n = strlen(s);
    srt();
    bk(0);
    return 0;
}
