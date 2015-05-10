
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
ll a[105];
ll sum[105];
ll dp[105][105];

ll go(int i, int j){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    ll ret = -10000000000000, x, y;
    FORAB(k, 1, j - i + 2){
        x = sum[i + k - 1] - sum[i-1];
        y = sum[j] - sum[j-k];
        ret = max(ret, max(x - go(i + k, j), y - go(i, j - k)));
    }

    return dp[i][j] = ret;
}

int main(){
    //read(in);
    //write(out);
    int n;
    while(scanf("%d", &n) && n){
        sum[0] = 0;
        FORAB(i, 1, n + 1){
            scanf("%lld", &a[i]);
            sum[i] = sum[i-1] + a[i];
            //dbg(sum[i]);
        }

        mem(dp, -1);
        ll r = go(1, n);
        printf("%lld\n", r);
    }
    return 0;
}
