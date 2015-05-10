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

using namespace std;
double dp[100050];
int fact[100050];

double go(int n){
    if(n == 1) return 0.0;
    if(dp[n] != -1) return dp[n];

    double ret = 1.0, mul = 1.0 /(double) (fact[n] - 1);

    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            ret += (go(i) + 1.0);
            if(i > 1 && i * i != n){
                ret += (go(n/i) + 1.0);
            }
        }
    }
    ret *= mul;

    return dp[n] = ret;
}

int main(){
    //read(in);
    //write(out);
    FORAB(i, 1, 100001){
        fact[i] = 0;
        dp[i] = -1;
        FORAB(j, 1, sqrt(i)){
            fact[i] += 2 * (i % j == 0);
        }
        fact[i] += (sqrt(i) * sqrt(i) == i);
    }

    int tc, t = 1, n;
    scan(tc);
    while(tc--){
        scan(n);
        double ans = go(n);
        printf("Case %d: %.10lf\n", t++, ans);
    }
    return 0;
}
