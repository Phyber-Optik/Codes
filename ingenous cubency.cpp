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

int cube( int x ){
    return x * x * x;
}
int n, C[22];
ll dp[22][10010];

ll go(int i, int n){
    if(n <= 0) return (n == 0);
    if(i > 21) return 0;
    if(dp[i][n] != -1) return dp[i][n];

    ll p = 0, q = 0;
    if(n >= C[i]) p += go(i, n - C[i]);
    q += go(i + 1, n);
    return dp[i][n] = p + q;
}

int main(){
    //read(in);
    //write(out);
    FORAB(i, 1, 22){
        C[i] = cube(i);
        //cout<<i<<" "<<C[i]<<endl;
    }

    while(scanf("%d", &n) != EOF){
        mem(dp, -1);
        printf("%lld\n", go(1, n));
    }

    return 0;
}
