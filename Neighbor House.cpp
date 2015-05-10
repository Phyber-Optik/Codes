
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
#define pii             pair<int, int>

int Set(int N, int pos) { return N = N | (1 << pos); }
int reSet(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }

using namespace std;

int n, dp[21][3], H[21][21];

int go(int i, int pre){
    if(i > n) return 0;
    if(dp[i][pre] != -1) return dp[i][pre];

    int &ret = dp[i][pre];
    ret = INF;

    int nextpre1, nextpre2;
    if(pre & 1) nextpre1 = 0, nextpre2 = 2;
    else if(!pre) nextpre1 = pre xor 2, nextpre2 = pre xor 1;
    else nextpre1 = 0, nextpre2 = 1;

    ret = min(go(i + 1, nextpre1) + H[i][nextpre1], go(i + 1, nextpre2) + H[i][nextpre2]);
    return ret;
}

int main(){
    //read(in);
    //write(out);
    int tc, t = 1;
    scan(tc);
    while(tc--){
        scan(n);
        FORAB(i, 1, n + 1){
            FORAB(j, 0, 3){
                scan(H[i][j]);
            }
        }

        mem(dp, -1);
        int ans = INF;
        for(int i = 0; i < 3; i++){
            ans = min(ans, H[1][i] + go(2, i));
        }
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}
