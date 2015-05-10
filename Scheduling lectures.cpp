
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
int L, C, n, dp[1010][501];
int a[1010];

int go(int i, int len){
    if(i > n) return 0;
    if(dp[i][len] != -1) return dp[i][len];

    int ret = 0;
    if(len >= a[i]) ret = min(go(i + 1, len - a[i]), 1 + go(i + 1, L - a[i]));
    else ret = 1 + go(i + 1, L - a[i]);

    return dp[i][len] = ret;
}

int main(){
    //read(in);
    //write(out);
    while(scan(n) && n){
        scanf("%d%d", &L, &C);
        int mn = 0;
        a[0] = 0;
        FORAB(i, 1, n + 1){
            scan(a[i]);
        }
        mem(dp, -1);
        mn = go(0, 0);
        dbg(mn);
        FORAB(i, 1, n + 1){
            for(int j = 0; j <= L; j++){
                printf("%2d ", dp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
