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
vector<int>G[MAX], GT[MAX], DAG[MAX];
bool vis[MAX];
stack<int>st;
int comp[MAX], scc_cnt;

void dfs(int u){
    vis[u] = true;
    int sz = G[u].size(), v;
    FORAB(i, 0, sz){
        v = G[u][i];
        if(vis[v] == false){
            vis[v] = true;
            dfs(v);
        }
    }

    st.push(u);
}

void dfs_transpose(int u, int component){
    vis[u] = true;
    comp[u] = component;
    int sz = GT[u].size(), v;
    FORAB(i, 0, sz){
        v = GT[u][i];
        if(vis[v] == false){
            dfs_transpose(v,  component);
        }
    }
}

void top_sort(int n){
    mem(vis, false);
    FORAB(i, 0, n){
        if(vis[i] == false){
            dfs(i);
        }
    }
}

void SCC(int n){
    mem(vis, false);
    scc_cnt  = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(vis[u] == false){
            dfs_transpose(u, scc_cnt++);
        }
    }
}

void build_DAG(int n){
    FORAB(i, 0, n){
        int sz = G[i].size(), u, v;
        FORAB(j, 0, sz){
            u = comp[i];
            v = comp[G[i][j]];
            if(u != v){
                DAG[u].push_back(v);
            }
        }
    }
}

void clear(int n){
    FORAB(i, 0, n + 1){
        G[i].clear();
        GT[i].clear();
    }

    FORAB(i, 0, scc_cnt + 1){
        DAG[i].clear();
    }
}

int main(){
    //read(in);
    //write(out);
	int tc, cs = 1;
	scan(tc);
	while(tc--){

		printf("Case %d: \n", cs++);
	}
    return 0;
}
