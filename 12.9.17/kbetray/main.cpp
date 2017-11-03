#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("kbetray.in");
ofstream fout("kbetray.out");
typedef unsigned long long ll;
ll n,k;
vector <pair<ll,ll> > p;
void input(){
    fin>>n>>k;
    ll a,b;
    for(ll i=1;i<=n;i++){
        fin>>a>>b;
        int m = min(a,b);
        if(m==a)
            p.push_back({a,b});
        else p.push_back({b,a});
    }
}
bool cmp(const pair<ll,ll> &a,
              const pair<ll,ll> &b){

    return (a.second < b.second);
}

int main()
{
    input();
    sort(p.begin(),p.end());
    vector<pair<ll,ll> > cp(p);
    sort(cp.begin(),cp.end(),cmp);
    ll s=0;
    for(int i=0;i<n;i++)
        s+=p[i].second;
    int i = 0;
    while(k && i < n){
        if(cp[i].second <= p[n-i-1].first){
            k--;
            s-=cp[i].second;
            s+=p[n-i-1].first;
        }
        i++;
    }
    fout<<s;

fin.close();
fout.close();
    return 0;
}
