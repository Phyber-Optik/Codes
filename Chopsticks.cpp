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
int K, n;
int a[5010];
ll dp[1010][5010];

ll sqr(int x){
    return x * x;
}

ll go(int t, int i){
    if((t == K + 8)){
        return 0;
    }
    if(i > n) return INF;

    if(dp[t][i] != -1) return dp[t][i];

    ll p, q;
    if((n - i + 1) >= 3 * (K + 8 - t)) p = sqr(a[i + 1] - a[i]) + go(t + 1, i + 2);
    q = go(t, i + 1);

    return dp[t][i] = min(p, q);
}

int main(){
    //read(in);
    //write(out);
    int tc;
    scan(tc);
    while(tc--){
        scan(K);
        scan(n);
        FORAB(i, 1, n + 1){
            scan(a[i]);
        }

        FORAB(i, 0, K + 9){
            FORAB(j, 0, n + 1){
                dp[i][j] = -1;
            }
        }
        ll r = go(0, 1);
        printf("%lld\n", r);
    }
    return 0;
}
