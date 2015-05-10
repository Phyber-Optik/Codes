
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
int ara[25010];
map<string, int>M;
vector<string> in;
vector<int> G[25010];
int dp[25010];

int bsearch(int down, int up, int X) {
	int med;
	do {
		med = (down+up)/2;
		if (X > ara[med])
			down = med + 1;
		else
			up = med - 1;
	} while (ara[med] != X && down <= up);

	if (ara[med] == X)
		return med;
	else
		return -1;
}

int go(int u){
    if(G[u].size() == 0) return 1;
    if(dp[u] != -1) return dp[u];

    int ret = 0;
    FORAB(i, 0, G[u].size()){
        ret = max(ret, 1 + go(G[u][i]));
    }

    return dp[u] = ret;
}

int main(){
    //read(in);
    //write(out);

    in.pb("");
    string s;
    int tot = 0, pos = 1;
    while(cin>>s){
        if(M[s] == false){
            M[s] = ++tot;
        }

        ara[pos++] = M[s];
        in.pb(s);
    }

    FORAB(i, 1, pos){
        //dbg(in[i]);
        int z = in[i].size();
        FORAB(j, 0, z){
            for(char c = 'a'; c <= 'z'; c++){
                s = in[i];
                s[j] = c;

                //dbg(s);
                if(s > in[i]){
                    break;
                }

                //cout<<s<<" "<<M[s]<<endl;
                if(M[s]){
                    int key = M[s];
                    //cout<<in[i]<<" "<<s<<" "<<key<<endl;
                    int r = bsearch(1, i - 1, key);
                    //cout<<r<<endl;
                    if(r != -1){
                        G[r].pb(i);
                    }
                }
            }

            s = in[i];
            s.erase(s.begin() + j);
            if(M[s]){
                int key = M[s];
                //cout<<in[i]<<" "<<s<<" "<<key<<endl;
                int r = bsearch(1, i - 1, key);
                if(r != -1){
                    G[r].pb(i);
                }
            }
        }

        FORAB(j, 0, z + 1){
            for(char c = 'a'; c <= 'z'; c++){
                s = in[i];
                s.insert(s.begin(), j, c);

                if(s > in[i]){
                    break;
                }

                if(M[s]){
                    int key = M[s];
                    //cout<<in[i]<<" "<<s<<" "<<key<<endl;
                    int r = bsearch(1, i - 1, key);
                    if(r != -1){
                        G[r].pb(i);
                    }
                }
            }
        }
    }

    /*FORAB(i, 1, pos){
        cout<<"i : "<<i<<" ";
        FORAB(j, 0, G[i].size()){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }*/

    FORAB(i, 0, pos + 1){
        dp[i] = -1;
    }

    int ans = 0;
    FORAB(i, 1, pos){
        ans = max(ans, go(i));
    }

    print(ans);

    return 0;
}
