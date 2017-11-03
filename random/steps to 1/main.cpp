#include <iostream>
#define nmax 100000

using namespace std;

int dp[nmax];
int n;

void solve(){
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = 1 + dp[i-1];
        if(i%2==0)
            dp[i] = min(dp[i], 1 + dp[i/2]);
        if(i%3==0)
            dp[i] = min(dp[i], 1 + dp[i/3]);

    }
}

int main()
{
    cout<<"N=" , cin>>n;
    solve();
    cout<<dp[n];
    return 0;
}
