
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
int n, k;
pii a[10][10], t[12];

int go(int i, int j){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    for(int k = i; k <= j; k++){

    }
}

int main(){
    //read(in);
    //write(out);
    int tc, p, q;
    scan(tc);
    while(tc--){
        scan(n);
        FORN(i, n){
            FORN(j, n){
                scanf("%d%d", &p, &q);
                a[i][j] = pii(p, q);
            }
        }
        scan(k);
        FORN(i, k){
            scan(t[i]);
        }
    }

    return 0;
}
