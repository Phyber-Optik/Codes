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
#define MAX             5006

using namespace std;
vector<pii> G[MAX];
pii d[MAX];

void dijkstra(int src, int n){
    int u, v, w, sz;
    priority_queue< pii, vector<pii>, greater<pii> > Q;
    FORAB(i, 0, n + 1) d[i].ff = d[i].ss = INF;
    d[src].ff = 0;
    Q.push(pii(0, src));

    while(!Q.empty()){
        u = Q.top().second;
        Q.pop();

        sz = G[u].size();
        FORAB(i, 0, sz){
            v = G[u][i].ff;
            w = G[u][i].ss;

            if(d[v].ff > d[u].ff + w){
                d[v].ff = d[u].ff + w;
                Q.push(pii(d[v].ff, v));
            }

            if(d[v].ss > d[u].ff + w && d[v].ff != d[u].ff + w){
                d[v].ss = d[u].ff + w;
                Q.push(pii(d[v].ss, v));
            }

            if(d[v].ss > d[u].ss + w){
                d[v].ss = d[u].ss + w;
                Q.push(pii(d[v].ss, v));
            }
        }
    }
}

void clear(int n){
    FORAB(i, 0, n + 1) G[i].clear();
}

int main(){
    //read(in);
    //write(out);
	int tc, cs = 1, n, m, a, b, c;
	scan(tc);
	while(tc--){
        scanf("%d%d", &n, &m);
        FORAB(i, 0, m){
            scanf("%d%d%d", &a, &b, &c);
            G[a].pb(pii(b, c));
            G[b].pb(pii(a, c));
        }
        dijkstra(1, n);
		printf("Case %d: %d\n", cs++, d[n].ss);

        clear(n);
	}
    return 0;
}
