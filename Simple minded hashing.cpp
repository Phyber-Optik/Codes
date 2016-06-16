
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
#define lim             32000
using namespace std;
char a[10010];
int dp[27][27][10001];
bool taken[27][27][10001];
int n;
int go(int cur, int pre, int s){
    if(cur >= n) return (s == 0);
    if(taken[cur][pre][s] == true) return dp[cur][pre][s];

    taken[cur][pre][s] = true;
    int ret = 0;
    for(int i = pre + 1; i <= 26; i++){
        ret += go(cur + 1, i, s - i);
    }

    return dp[cur][pre][s] = ret;
}

int main(){
    //read(in);
    //write(out);
    int sum, t = 1;
    while(scanf("%d%d", &n, &sum) && (sum || n)){
        mem(taken, false);
        n = min(n, 26);
        printf("Case %d: %d\n", t++, go(0, 0, sum));
    }
    return 0;
}
