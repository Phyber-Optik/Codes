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
int P[MAX][22];         // sparse table
int T[MAX];             // parent table

vector<int> G[MAX];     // graph

void dfs(int from, int u, int depth){
    T[u] = from;
    L[u] = depth;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(v == from) continue;
        dfs(u, v, depth + 1);
    }
}

int query(int N, int p, int q){
    int log;
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
            p = P[p][i];
        }
    }

    if(p == q) return p;

    for(int i = log; i >= 0; i--){
        if(P[p][i] !=- 1 && P[p][i] != P[q][i]){
            p = P[p][i], q = P[q][i];
        }
    }

    return T[p];
}

void init(int N){
    mem(P, -1);
    for(int i = 0; i < N; i++){
        P[i][0] = T[i];
    }

    for(int j = 1; (1 << j) < N; j++){
        for(int i = 0; i < N; i++){
            if(P[i][j-1] != -1){
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int main(){
    //read(in);
    //write(out);
    G[0].pb(1);
    G[0].pb(2);
    G[2].pb(3);
    G[2].pb(4);
    dfs(0, 0, 0);
    init(5);
    printf( "%d\n", query(5,3,4) );
    int tc, cs = 1;
    /*scan(tc);
    while(tc--){

        printf("Case %d: \n", cs++);
    }*/
    return 0;
}
