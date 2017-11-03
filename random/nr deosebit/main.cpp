#include <iostream>

using namespace std;

struct elem {
    int info;
    elem *pred,*urm;
}*sant1,*ult;


/// adaugare element z dupa ult
void push(int z) {
    elem *p;
    p = new elem;
    p -> info = z;
    ult -> urm = p;
    p -> pred = ult;
    p -> urm = NULL;
    ult = p;
}

/// '\n' = endl
void print(){
    elem *p;
    p = sant1 -> urm;
    while(p){
        cout<<p -> info<<" ";
        p = p -> urm;
    }
    cout<<'\n';
}

/// suma cifrelor

inline int sum(int n){
    int s = 0;
    while(n){
        s += n%10;
        n /= 10;
    }
return s;
}

/// parcurg toate elementele mai mici decat n-1
/// si verific daca e deoseibit
/// daca e deosebit nu are rost sa continui
/// daca nu am gasit nici un caz adevarat, nu e deosebit

bool deosebit(int n){
    for( int m = 1; m < n ;m++){
        if((m + sum(m)) == n)
            return true;
    }
    return false;
}

/// initializez ldi
/// nu ai nevoie de a doua santinela pentru ca nu modifici
/// niciodata lista ca sa ai nevoie de ultimul element
void create() {
    sant1 = new elem;
    sant1 -> urm = NULL;
    sant1 -> pred = NULL;
    ult = sant1;
}

int main()
{
    int a,b,i;
    cout<<"Introduceti cele doua numere ";
    cin>>a>>b;
    create();
    for(i=a;i<=b;i++)     /// parcurg toate elementele din interval
        if(deosebit(i))   /// daca exista nu trebuie == 1
            push(i);
    print();

    return 0;
}
