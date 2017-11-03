#include <iostream>
#include <fstream>
using namespace std;
int fr[1001],a[1001],b[1001],sol[1001],n,dif,l;
int first,second;
void input(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
}

void print(){
   for(int i=1;i<=n;i++)
    cout<<sol[i]<<" ";
}

bool check(){
    int nr1=0,nr2=0;
    for(int i=1;i<=n;i++){
        if(a[i] == sol[i])
            nr1++;
        if(b[i] == sol[i])
            nr2++;
    }
    if(nr2!=nr1)
        return false;
    if(nr1 == (n-1))
        return true;
}

void getDifference(){
    int i,j;
    for(i=1;i<=n;i++)
        if(a[i] == b[i] && !fr[a[i]]){
            fr[a[i]] = 1;
            sol[++l] = a[i];
        }
        else {
                dif++;
                l++;
                if(!first) first = i;
                else second =  i;
        }
}
void solveOne(){
    for(int d=1;d<=n;d++)
        if(!fr[d]){
            sol[first] = d;
            break;
        }
}
int main()
{
    input();
    getDifference();
    if(dif == 1){
        solveOne();
        print();
        return 0;
    }
    if(!fr[a[first]] && !fr[b[second]]){
        sol[first] = a[first];
        sol[second] = b[second];
         if(!check()){
         sol[first] = b[first];
         sol[second] = a[second];
         }
    }
    else {
         if(!check()){
        sol[first] = b[first];
        sol[second] = a[second];
         }
    }


    print();
    return 0;
}
