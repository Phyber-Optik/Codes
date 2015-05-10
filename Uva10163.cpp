
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
int n, m, p[32];
int dp[105][32][32];

int go(int i, int j, int k){
    if(i < 1 || j > m){
        dbg(i);
        dbg(j);
        return 0;
    }
    if(dp[i][j][k] != -1) return dp[i][j][k];

    int ret = 0;
    if(p[j] >= k) {
        ret = max(ret, max(p[j] / k, go(i - 1, j, k + 1)));
    }
    ret = max(ret, go(i, j + 1, 1));
    return dp[i][j][k] = ret;
}

int main(){
    //read(in);
    //write(out);
    while(scanf("%d%d", &n, &m) && (n || m)){
        FORAB(i, 1, m + 1){
            scan(p[i]);
        }
        ///mem(dp, -1);

        dp[0][0][0] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= n; k++){

                }
            }
        }
        dbg(r);
    }
    return 0;
}
