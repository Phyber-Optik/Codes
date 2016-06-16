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
#define MAX             507

using namespace std;

vector < int > G[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    int len = G[u].size(), i, v;
    for(i = 0; i < len; i++) {
        v = G[u][i];
        if(Right[v] == -1) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i = 0; i < len; i++) {
        v = G[u][i];
        if(dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int match(int n) {
    mem(Left, -1);
    mem(Right, -1);
    int i, ret = 0;
    bool done;
    
    do {
        done = true;
        mem(visited, false);
        for(i = 0; i < n; i++) {
            if(Left[i] == -1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i = 0; i < n; i++) ret += (Left[i] != -1);
    return ret;
}

int get_num(char str[]){
    int tot = 0;
    int len = strlen(str);
    FORAB(i, 1, len){
        tot *= 10;
        tot += str[i] - '0';
    }

    return tot;
}


vector<pii> M, F;
int main(){
    //read(in);
    //write(out);
	int m, f, v, a, b, tc, cs = 1;
	char str1[3], str2[3];
    scan(tc);
	while(tc--){
        scan(m);
        scan(f);
        scan(v);
        FORAB(i, 0, v){
            scanf("%s%s", str1, str2);
            a = get_num(str1);
            b = get_num(str2);
            if(str1[0] == 'M'){
                M.pb(pii(a, b));
            }
            else{
                F.pb(pii(a, b));
            }

        }

        int msz = M.size(), fsz = F.size();
        FORAB(i, 0, msz){
            FORAB(j, 0, fsz){
                if(M[i].ff == F[j].ss || M[i].ss == F[j].ff){
                    G[i].pb(j);
                }
            }
        }

		printf("Case %d: %d\n", cs++, v - match(msz));
        FORAB(i, 0, msz){
            G[i].clear();
        }
        M.clear();
        F.clear();
	}
    return 0;
}
