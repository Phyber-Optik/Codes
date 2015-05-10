/*  Towhidul Islam
    University Of Dhaka
    Problem Name :
    Algorithm Used :
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<queue>
#include<fstream>
#include<sstream>
#include<set>
#include<climits>
#include<map>
#include<algorithm>
#include<iomanip>
#include<functional>

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
#define FORAB(i, x, n)   for(int i = x; i < n; i++)
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define dbg2(x, y)      cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define pii             pair<int, int>

using namespace std;
int K, n, dig;
string s;
int dp[11][83][83][2];

int go(int index, int moded, int smoded, bool pre){
    if(index == n) return (moded == 0) && (smoded == 0);
    if(dp[index][moded][smoded][pre] != -1) return dp[index][moded][smoded][pre];
    int &ret = dp[index][moded][smoded][pre];

    ret = 0;
    int pos = s[index] - '0';
    if(pre == true) pos = 9;
    for(int i = 0; i <= pos; i++){
        ret += go(index + 1, (moded * 10 + i) % K, (smoded + i) % K, pre || i < pos);
    }

    return ret;
}

int sol(int a){
    s = SSTR(a);
    n = s.size();

    mem(dp, -1);
    int r = go(0, 0, 0, false);
    return r;
}

int main(){
    int tc, a, b;
    scan(tc);
    FORN(t, tc){
        scanf("%d%d", &a, &b);;
        scan(K);

        if(K > 82) printf("Case %d: 0\n", t + 1);
        else printf("Case %d: %d\n", t + 1, sol(b) - sol(a - 1));
    }

    return 0;
}
