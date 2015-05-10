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
#define print(n)        printf("%lld\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define pii             pair<int, int>

using namespace std;

char a[65];
ll dp[65][65];

ll go(int i, int j){
    if(i >= j) return (i == j);
    if(dp[i][j] != -1) return dp[i][j];

    ll p = 0, q = 0;
    if(a[i] == a[j]) p = 1 + go(i + 1, j) + go(i, j - 1);
    else q = go(i + 1, j) + go(i, j - 1) - go(i + 1, j - 1);

    return dp[i][j] = max(p, q);
}

int main(){
    //read(in);
    //write(out);
    int tc;
    scan(tc);
    while(tc--){
        scanf("%s", a);
        int n = strlen(a);
        FORAB(i, 0, n + 1){
            FORAB(j, 0, n + 1){
                dp[i][j] = -1;
            }
        }

        ll r = go(0, n - 1);
        print(r);
    }
    return 0;
}
