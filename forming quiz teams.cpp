
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

int Set(int N, int pos) { return N = N | (1 << pos); }
int reSet(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }

using namespace std;

int n, lim;
double dp[1<<16 + 7], d[17][17];

double dis(int x, int y, int a, int b){
    return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}

double go(int mask){
    //dbg(mask);
    if(mask == (lim - 1)) return 0;
    if(dp[mask] != -1) return dp[mask];

    double ret = 10000000.0;

    for(int i = 0; i < n; i++){
        if(check(mask, i) == false){
            mask = Set(mask, i);
            for(int j = 0; j < n; j++){
                if(i != j && check(mask, j) == false){
                    ret = min(ret, d[i][j] + go(Set(mask, j)));
                    //mask = reSet(mask, j);
                }
            }
            mask = reSet(mask, i);
        }
    }

    return dp[mask] = ret;
}

int main(){
    read(in);
    //write(out);
    char name[25];
    int p[17][2], t = 1;

    while(scanf("%d", &n) && n){
        n *= 2;
        lim = 1 << n;
        FORAB(i, 0, n){
            scanf("%s", name);
            scan(p[i][0]);
            scan(p[i][1]);
        }

        FORAB(i, 0, n){
            FORAB(j, i + 1, n){
                d[i][j] = d[j][i] = dis(p[i][0], p[i][1], p[j][0], p[j][1]);
            }
        }

        FORN(i, lim){
            dp[i] = -1;
        }

        //mem(dp, -1.0);
        double r = go(0);
        printf("Case %d: %.2lf\n", t++, r);
    }
    return 0;
}
