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
struct coin{
    int a, b;
}C[50];

int dp[42][301][301], n, S;


int go(int i, int x, int y){
    if(i == n){
        //dbg(x), dbg(y);
        if(x * x + y * y == S * S){
            //cout<<x<<" ";dbg(y);
            return 0;
        }
        return INF;
    }
    if(dp[i][x][y] != -1) return dp[i][x][y];

    int p = INF, q = INF;

    if(C[i].a + x <= S && C[i].b + y <= S){
        p = min(p, 1 + go(i, C[i].a + x, C[i].b + y));
    }
    q = min(q, go(i + 1, x, y));

    return dp[i][x][y] = min(p, q);
}

int main(){
    //read(in);
    //write(out);
    int tc;
    scan(tc);
    while(tc--){
        scan(n);
        scan(S);

        FORAB(i, 0, n){
            scan(C[i].a);
            scan(C[i].b);
        }

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= S; j++){
                for(int k = 0; k <= S; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        int r = go(0, 0, 0);
        if(r == INF){
            printf("not possible\n");
        }
        else printf("%d\n", r);
    }

    return 0;
}
