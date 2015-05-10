
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

int Set(int N, int pos) { return N = N | (1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }

int st[4][41];
int dp[41][41][41][41];

int go(int a, int b, int c, int d, int mask){
    if(__builtin_popcount(mask) == 5) return 0;
    if(dp[a][b][c][d] != -1) return dp[a][b][c][d];

    int ret = 0;

    if(a) ret = max(ret, check(mask, st[0][a]) + go(a - 1, b, c, d, mask ^ (1 << st[0][a])));
    if(b) ret = max(ret, check(mask, st[1][b]) + go(a, b - 1, c, d, mask ^ (1 << st[1][b])));
    if(c) ret = max(ret, check(mask, st[2][c]) + go(a, b, c - 1, d, mask ^ (1 << st[2][c])));
    if(d) ret = max(ret, check(mask, st[3][d]) + go(a, b, c, d - 1, mask ^ (1 << st[3][d])));

    return dp[a][b][c][d] = ret;
}

int main(){
    //read(in);
    //write(out);
    int n;
    while(scan(n) && n){
        for(int i = n; i >= 1; i--){
            for(int j = 0; j < 4; j++){
                scanf("%d", &st[j][i]);
            }
        }

        mem(dp, -1);
        int r = go(n, n, n, n, 0);
        print(r);
    }

    return 0;
}
