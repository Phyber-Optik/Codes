
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
#define pii             pair<ll, ll>

using namespace std;

template <class T> inline T GCD( T a, T b ) { if( a < 0 ) return GCD( -a , b );
    if( b < 0 ) return GCD( a, -b ); return ( b == 0 ) ? a : GCD( b, a%b ); }

pii dp[26][200];
int n, k;

pii go(int i, int sum) {
    if(i > n) {
       return make_pair((sum >= k), 1);
    }

    if(dp[i][sum].first != -1) return dp[i][sum];

    pii ret;
    ret.first = 0;
    ret.second = 0;

    for(int j = 1; j <= 6; j++) {
        ret.first += go(i + 1, sum + j).first;
        ret.second += go(i + 1, sum + j).second;
    }

    return dp[i][sum] = ret;
}
int main() {
    int tc, t = 1;
    scanf("%d", &tc);

    while (tc--) {
        scanf("%d%d", &n, &k);
        memset(dp, -1, sizeof dp);
        pii ans = go(1, 0);
        ll G = GCD(ans.first, ans.second);
        ans.first /= G;
        ans.second /= G;

        printf("Case %d: ", t++);
        if(ans.second == 1) printf("%lld\n", ans.first);
        else printf("%lld/%lld\n", ans.first, ans.second);
    }
	return 0;
}
