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

int a[255];
int sum[255];
int dp[255][255];

int go(int i, int j){
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ret = INF;
    FORAB(k, i, j + 1){
        ret = min(ret, go(i, k - 1) + go(k + 1, j) + sum[j] - sum[i - 1] - a[k]);
    }

    return dp[i][j] = ret;
}

int main(){
    //read(in);
    //write(out);
    int n;
    while(scanf("%d", &n) != EOF){
        sum[0] = 0;
        FORAB(i, 1, n + 1){
            scan(a[i]);
            sum[i] = a[i] + sum[i-1];
        }

        FORAB(i, 1, n + 1){
            FORAB(j, 1, n + 1){
                dp[i][j] = -1;
            }
        }
        int r = go(1, n);
        printf("%d\n", r);
    }
    return 0;
}
