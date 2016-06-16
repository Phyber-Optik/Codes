
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
#define lim             32000

int Set(int N, int pos) { return N = N | (1 << pos); }
int reSet(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }

using namespace std;
map<int, int>mp;
int G[51][51], C[13];
int dp[13][1<<13], N;
bool taken[13][1<<13];
void floyd_warshall(int n){
    FORAB(k, 0, n){
        FORAB(i, 0, n){
            FORAB(j, 0, n){
                if(G[i][k] + G[k][j] < G[i][j]){
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
}

int go(int pos, int mask){
    if(mask == (1 << N) - 1){
        return G[mp[pos]][0];
    }
    if(taken[pos][mask] == true) return dp[pos][mask];

    taken[pos][mask] = true;
    int ret = INF;
    for(int i = 0; i < N; i++){
        if(i == pos) continue;
        if(check(mask, i) == false) ret = min(ret, min(G[mp[i]][mp[pos]] + go(i, Set(mask, i)), C[mp[i]] + go(pos, Set(mask, i))));
    }

    return dp[pos][mask] = ret;
}

int main(){
    //read(in);
    //write(out);
    int tc, n, m, a, b, t;
    double c;
    scan(tc);
    FORAB(i, 0, tc){
        scanf("%d%d", &n, &m);
        FORAB(i, 0, n + 1){
            FORAB(j, 0, n  +1){
                if(i == j) G[i][j] = 0;
                else G[i][j] = INF;
            }
        }
        FORAB(i, 0, m){
            scanf("%d%d%lf", &a, &b, &c);
            t = (int)(c * 100.0 + eps);
            G[a][b] = G[b][a] = min(G[a][b], t);
        }
        floyd_warshall(n + 1);

        scan(n);
        N = n + 1;
        int ans = 0;
        mp[0] = 0;
        FORAB(i, 1, n + 1){
            scanf("%d%lf", &a, &c);
            t = (int)(c * 100.0 + eps);
            ans += t;
            mp[i] = a;
            C[mp[i]] = t;
        }
        mem(taken, false);
        int ret = go(0, 1);
        //dbg(ret);
        //dbg(ans);
        ans = ans - ret;
        if(ans > 0) printf("Daniel can save $%.2f\n", (double)ans / 100.0);
        else printf("Don't leave the house\n");
        mp.clear();
    }
    return 0;
}
