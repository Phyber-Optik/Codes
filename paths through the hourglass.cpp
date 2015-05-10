
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
int p[50][25], n, s;
int dp[50][25][504];

int go(int i, int j, int sum){
    if(sum == 0 && i == 2 * n){
        dbg(i);
        return 1;
    }

    if(sum < 0 || i > 2 * n || p[i][j] == -1){
        return 0;
    }

    if(dp[i][j][sum] !=- 1) return dp[i][j][sum];

    int ret1 = 0, ret2 = 0;
    ret1 += go(i + 1, j, sum - p[i][j]);
    if(i <= n) ret2 += go(i + 1, j - 1, sum - p[i][j]);
    else ret2 += go(i + 1, j + 1, sum - p[i][j]);

    return dp[i][j][sum] = ret1 + ret2;
}

int main(){
    //read(in);
    //write(out);
    while(scanf("%d%d", &n, &s) && (n || s)){
        mem(p, -1);
        FORAB(i, 1, n + 1){
            FORAB(j, 1, (n - i + 1) + 1){
                scan(p[i][j]);
            }
        }

        FORAB(i, 1, n){
            FORAB(j, 1, i + 2){
                scan(p[n+i][j]);
            }
        }

        for(int i = 0; i <= 2 * n; i++){
            for(int j = 0; j <=n + 1; j++){
                printf("%3d ", p[i][j]);
            }
            printf("\n");
        }

        mem(dp, -1);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            mem(dp, -1);
            ans += go(1, i, s);
            dbg(ans);
        }
        print(ans);
    }
    return 0;
}
