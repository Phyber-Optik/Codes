
/*  Towhidul Islam
    University Of Dhaka
    Problem Name :
    Algorithm Used :
*/

#include<bits/stdc++.h>

typedef long long ll;

#define SSTR(x)         dynamic_cast< ostringstream & >( \
                        (ostringstream() << dec << x )).str()
#define pb              push_back
#define mem(a, x)       memset(a, x, sizeof a)
#define PI              acos(-1)
#define all(a)          a.begin(), a.end()
#define MAX             100010
#define read(in)        freopen("in.txt", "r", stdin)
#define write(out)      freopen("out.txt", "w", stdout)
#define INF             10000000
#define eps             1e-9
#define arraysz(a)      sizeof (a)/sizeof(a[0])
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define chkwhere        cout<<"LOL\n"
#define pii             pair<int, int>

using namespace std;
int a[1000], n, m, b;
int dp[501][501];
int MOD;

int go(int i, int x, int y){
    if(i > n && y <= b){
        return 1;
    }
    if(dp[i][x] != -1) return dp[i][x];
    int ret = 0;

    for(int j = 0; x + j <= m; j++){
        if(i == n && x + j == m){
            ret = (ret % MOD + go(i + 1, m, y + (j * a[i])) % MOD) % MOD;
        }
        else if(i < n) ret = (ret % MOD + go(i + 1, x + j, y + (j * a[i])) % MOD) % MOD;
    }

    return dp[i][x] = ret;
}


int main(){
    read(in);
    //write(out);
    while(cin>>n>>m>>b>>MOD){
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }

        mem(dp, -1);
        int ans = go(1, 0, 0);
        cout<<ans<<endl;
    }
    return 0;
}
