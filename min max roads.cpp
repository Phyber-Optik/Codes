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
#define ff              first
#define ss              second
#define read(in)        freopen("in.txt", "r", stdin)
#define write(out)      freopen("out.txt", "w", stdout)
#define INF             1<<30
#define eps             1e-9
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define chkwhere        cout<<"LOL\n"
#define pii             pair<int, int>
#define MOD             1000000007
#define MAX             100007

using namespace std;

int L[MAX];             // level table
int P[MAX][17];         // sparse table
int T[MAX];             // parent table
int mx[MAX][17];
int mn[MAX][17];
vector< pii > G[MAX];     // graph

void dfs(int from, int u, int depth){
    T[u] = from;
    L[u] = depth;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i].ff;
        if(v == from) continue;
        mx[v][0] = mn[v][0] = G[u][i].ss;
        dfs(u, v, depth + 1);
    }
}

pii query(int N, int p, int q){
    int log, mxans = 0, mnans = INF;
    if(L[p] < L[q]){
        swap(p, q);
    }

    log = 1;
    while(true){
        int next = log + 1;
        if((1 << next) > L[p]) break;
        log++;
    }

    // bringing p, q to same level
    for(int i = log; i >= 0; i--){
        if(L[p] - (1 << i) >= L[q]){
            mxans = max(mxans, mx[p][i]);
            mnans = min(mnans, mn[p][i]);
            p = P[p][i];
        }
    }

    if(p == q){
        return pii(mnans, mxans);
    }
    for(int i = log; i >= 0; i--){
        if(P[p][i] !=- 1 && P[p][i] != P[q][i]){
            mxans = max(mxans, max(mx[p][i], mx[q][i]));
            mnans = min(mnans, min(mn[p][i], mn[q][i]));
            p = P[p][i], q = P[q][i];
        }
    }
    mxans = max(mxans, max(mx[p][0], mx[q][0]));
    mnans = min(mnans, min(mn[p][0], mn[q][0]));

    return pii(mnans, mxans);
}

void init(int N){
    mem(mx, 0);
    mem(mn, INF);
    mem(P, -1);
    dfs(1, 1, 0);
    
    for(int i = 0; i < N; i++){
        P[i][0] = T[i];
    }

    for(int j = 1; (1 << j) < N; j++){
        for(int i = 0; i < N; i++){
            if(P[i][j-1] != -1){
                P[i][j] = P[P[i][j-1]][j-1];
                mx[i][j] = max(mx[i][j-1], mx[P[i][j-1]][j-1]);
                mn[i][j] = min(mn[i][j-1], mn[P[i][j-1]][j-1]);
            }
        }
    }
}

int main(){
    //read(in);
    //write(out);
    int tc, cs = 1, n, q, u, v, w;
    scan(tc);
    while(tc--){
        scanf("%d", &n);
        FORAB(i, 1, n){
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w));
        }
        init(n + 1);
        printf("Case %d:\n", cs++);
        scan(q);
        FORAB(i, 0, q){
            scanf("%d%d", &u, &v);
            pii ret = query(n + 1, u, v);
            printf("%d %d\n", ret.ff, ret.ss);
        }    

        FORAB(i, 1, n + 1) G[i].clear();
    }
    return 0;
}
