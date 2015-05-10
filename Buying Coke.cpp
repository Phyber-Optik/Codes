
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
int a, b, c, dp[152][300][102];

int go(int k, int a, int b){
    if(a < 0 || b < 0){
        return INF;
    }
    if(k == 0){
        return 0;
    }

    if(dp[k][a][b] != -1) return dp[k][a][b];

    int ret = INF;

    ret = min(ret, 4 + go(k - 1, a + 1, b - 1));
    ret = min(ret, 1 + go(k - 1, a, b - 1));
    ret = min(ret, 2 + go(k - 1, a - 2, b));
    ret = min(ret, 4 + go(k - 1, a - 1, b));
    ret = min(ret, 8 + go(k - 1, a, b));

    return dp[k][a][b] = ret;
}

int main(){
    //read(in);
    //write(out);
    int tc, C;
    scan(tc);
    while(tc--){
        scan(C);
        scanf("%d%d%d", &a, &b, &c);

        int ans;

        FORAB(i, 0, C + 1){
            FORAB(j, 0, b + c + 2){
                FORAB(k, 0, c + 1){
                    dp[i][j][k] = -1;
                }
            }
        }

        ans = go(C, b, c);
        print(ans);
    }
    return 0;
}
