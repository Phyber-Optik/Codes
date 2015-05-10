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

int n;
vector< int > G[510];
int C[510][7];
pii dp[510];

pii go(int i){
    if(G[i].size() == 0) return pii(1, );
    if(dp[i].first != -1) return dp[i];

    int ans = 0;
    FORN(k, G[i].size()){
        ans = max(ans, 1 + go(G[i][k]));
    }

    return dp[i].first = ans;
}

int main(){
    //read(in);
    //write(out);
    int t = 1;
    while(scanf("%d", &n) && n){
        FORAB(i, 1, n + 1){
            FORAB(j, 1, 7){
                scan(C[i][j]);
                //dp[i][j] = -1;
            }
        }


        map<int, bool>s;
        FORAB(i, 1, n){
            s.clear();
            FORAB(j, i + 1, n + 1){
                FORAB(k, 1, 7){
                    FORAB(q, 1, 7){
                        if(C[i][k] == C[j][q]){
                            if(s[j] == false){
                                G[i].pb(j);
                                s[j] = true;
                            }
                        }
                    }
                }
            }
        }

        FORAB(i, 1, n + 1){
            cout<<i<<" : ";
            FORAB(j, 0, G[i].size()){
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }
        mem(dp, -1);
        int ans = go(1);
        printf("Case #%d\n%d\n", t++, ans);
    }

    return 0;
}
