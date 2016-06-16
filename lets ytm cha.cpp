
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
#define INF             1000000000
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
#define pii             pair<int, int>
#define lim             32000
using namespace std;
int dp[101][1001][22];
bool taken[101][1001][22];
int f[101], p[101];

int go(int i, int P, int k){
    if(i < 0) return 0;
    if(taken[i][P][k] == true) return dp[i][P][k];
    taken[i][P][k] = true;
    int ret1 = 0, ret2 = 0, ret = 0;
    if(p[i] <= P && k) ret1 = f[i] + go(i - 1, P - p[i], k - 1);
    if(2 * p[i] <= P && k > 1) ret2 = 2 * f[i] + go(i - 1, P - 2 * p[i], k - 2);
    ret = max(go(i - 1, P, k), max(ret1, ret2));

    return dp[i][P][k] = ret;
}

int main(){
    //read(in);
    //write(out);
    int n, x, t, k, tmp;
    while(scanf("%d%d%d%d", &n, &x, &t, &k) && (n || x || t || k)){
        n++;
        mem(f, 0);
        FORAB(i, 0, k){
            scan(p[i]);
            FORAB(j, 0, n){
                scan(tmp);
                f[i] += tmp;
            }
        }

        mem(taken, false);
        int P = (10 * x * n - 11 * t * n) / 11;
        int ret = go(k - 1, P, 2*n);
        printf("%.2f\n", (double)ret / (1.0 * n));
    }
    return 0;
}
