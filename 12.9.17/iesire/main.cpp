#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
queue <pair<int,int> > q;
const int di[] = { -1, 0, 1, 0 },
          dj[] = { 0, 1, 0, -1 };
int n,l;
int ap[101][101];
void getMatrix(){
    freopen("iesire.in","r",stdin);
    cin>>n>>l;
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>ap[i][j];

}

bool ok(int i,int j){
    if(i < 1 || i > n || j < 1 || j > n)
        return false;
    return true;
}

void fil(){

        for(int i,j,iv,jv;!q.empty();){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int d = 0;d < 8; d++){
                iv = i + di[d];
                jv = j + dj[d];
                if(ok(iv,jv) && ap[iv][jv] == 0){
                    q.push({iv,jv});
                    ap[iv][jv] = -1;
                    }
            }

        }
}

void getFree(){
     int i,j;
    for(i=1;i<=n;i++){
        if(ap[i][1] == 0){
            q.push({i,1});
            fil();
            }
        if(ap[i][n] == 0){
            q.push({i,n});
            fil();
        }
    }
    for(j=1;j<=n;j++){
        if(ap[1][j] == 0){
            q.push({1,j});
            fil();
        }
        if(ap[n][j] == 0){
            q.push({n,j});
            fil();
        }
    }
}

int main()
{
    freopen("iesire.out","w",stdout);
    getMatrix();
    getFree();
    int i;
    int a,b;
    for(i=1;i<=l;i++,cout<<'\n'){
        cin>>a>>b;
        if(ap[a][b] == -1)
            cout<<"da";
        else cout<<"nu";
    }


    return 0;
}
