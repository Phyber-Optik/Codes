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
#define pii             pair<int, int>

using namespace std;
int m, n;
ll dp[11][11];
int d[11];
map<ll, bool>s;

ll go(int i, int j){
    if(j == n - 1){
        return 1;
    }

    else if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    for(int k = 0; k < m; k++){
        if(abs(d[k] - d[i]) < 3){
            ans += go(k, j + 1);
        }
    }

    return dp[i][j] = ans;
}

int main(){
    //read(in);
    //write(out);
    int tc, tmp;
    scan(tc);
    FORAB(t, 1, tc + 1){
        scanf("%d%d", &m, &n);
        FORN(i, m){
            scan(d[i]);
        }

        mem(dp, -1);
        ll r = 0;
        FORN(i, m){
            r += go(i, 0);
        }
        printf("Case %d: %lld\n", t, r);
        s.clear();
    }

    return 0;
}
