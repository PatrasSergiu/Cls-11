#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector <string> s,p,c;
int n;
ofstream fout("s_p_c.out");
void input(){
    ifstream fin("s_p_c.in");
    string act;
    while(fin>>act){
        if( act[act.size()-1] == 'S')
            s.push_back(act);
        else if(act[act.size()-1] == 'P')
            p.push_back(act);
            else c.push_back(act);
    }
fin.close();
    sort(s.begin(),s.end());
    sort(p.begin(),p.end());
    sort(c.begin(),c.end());
}
void eraser(){
    int i;
    for(i=0;i<s.size();i++)
        s[i].erase(s[i].end()-2,s[i].end());
    for(i=0;i<p.size();i++)
        p[i].erase(p[i].end()-2,p[i].end());
    for(i=0;i<c.size();i++)
        c[i].erase(c[i].end()-2,c[i].end());
}
int main()
{
    input();
    int i,j,k;
    eraser();
    for(i = 0; i<s.size();i++)
        for(j = 0; j<p.size();j++)
            for(k = 0; k<c.size();k++)
                fout<<s[i]<<" "<<p[j]<<" "<<c[k]<<'\n';
    return 0;
}
