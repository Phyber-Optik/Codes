
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
#define MAX             10007

using namespace std;

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];       
int d[101];           
 
bool BellmanFord(int src, int NODES, int EDGES){
    int i, j;
 
    for (i = 0; i < NODES; ++i) d[i] = INF;
    d[src] = 0;
 
    for (i = 0; i < NODES - 1; ++i) {
        for (j = 0; j < EDGES; ++j) {
            if (d[edges[j].u] + edges[j].w < d[edges[j].v]) {
                d[edges[j].v] = d[edges[j].u] + edges[j].w;
            }
        }
    }
    
    for (j = 0; j < EDGES; ++j) {
        if (d[edges[j].u] + edges[j].w < d[edges[j].v]) {
            return true;
        }
    }

    return false;
}

int process(int i, int e, int p){
	return e * p - i;
}

int main(){
    //read(in);
    //write(out);
	int tc, cs = 1, I, E, P, N, R, a, b;
	scan(tc);
	while(tc--){
		scanf("%d%d%d", &N, &R, &P);
		FORAB(i, 0, R){
			scanf("%d%d%d%d", &a, &b, &I, &E);
			Edge tmp;
			tmp.u = a;
			tmp.v = b;
			tmp.w = process(I, E, P);
			edges[i] = tmp;	
		}

		//dbg(BellmanFord(0, N, R));
		printf("Case %d: %s\n", cs++, BellmanFord(0, N, R) == true ? "YES" : "NO");
	}
    return 0;
}
