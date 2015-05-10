
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
#define eps             1E-9
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

using namespace std;
double p[110], P;
int m[110], n;
double dp[101][10010];

double go(int i, int mil){
    //dbg(i);
    //dbg(prob);
    if(i > n){
        if(mil == 0) return 0;
        return INF;
    }
    if(dp[i][mil] != -1) return dp[i][mil];

    double ret1 = INF, ret2 = INF;
    double cur_prob = prob + (1 - prob) * p[i];

    ret1 = min(ret2, cur_prob + go(i + 1, mil - m[i]));
    ret2 = min(ret2, go(i + 1, mil));

    return dp[i][mil] = max(ret1, ret2);
}

int main(){
    //read(in);
    //write(out);
    int tc, t = 1, sum;
    scan(tc);
    while(tc--){
        mem(dp, -1);
        scanf("%lf %d", &P, &n);
        sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d %lf", &m[i], &p[i]);
            sum += m[i];
        }

        bool f = false, ans;
        for(int i = sum; i >= 0; i--){
            if(go(1, i, 0) == 1){
                f = true;
                ans = i;
                break;
            }
        }

        if(f == true) printf("Case %d: %d\n", t++, ans);
        else printf("Case %d: 0\n", t++);
    }
    return 0;
}
