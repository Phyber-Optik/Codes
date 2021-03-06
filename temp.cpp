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
const ll INF = 200000000000000000;
#define eps             1e-9
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define chkwhere        cout<<"LOL\n"
#define pii             pair<ll, ll>
#define MOD             1000000007
#define MAX             100007

using namespace std;
typedef vector<pii> List;
typedef struct data{
    List L;
    data(List tmp){
        L = tmp;
    }
}CC;

vector<CC> Cat;
ll dp[26][1002];
int T, C;
ll L;
ll F(int pre, int pre_pos, int cur, int cur_pos){
    ll tot = Cat[cur].L[cur_pos].ss;
    tot += abs(Cat[cur].L[cur_pos].ff - Cat[pre].L[pre_pos].ff);
    return tot;
}

ll go(int id, int pre){
    if(id >= C) return (L - Cat[id-1].L[pre].ff);
    if(dp[id][pre] != -1) return dp[id][pre];

    ll ret = INF;
    //dbg(ret);
    FORAB(i, 0, T){
        //dbg(ret);
        ret = min(ret, F(id - 1, pre, id, i) + go(id + 1, i));
    }

    return dp[id][pre] = ret;
}



int main(){
    //read(in);
    //write(out);
	int tc, cs = 1;
	ll a, b;
	scan(tc);
	while(tc--){
        scanf("%d%d", &C, &T);
        cin>>L;
        FORAB(i, 0, C){
            List tmp;
            FORAB(j, 0, T){
                cin>>a>>b;
                tmp.pb(pii(a, b));
            }
            Cat.pb(data(tmp));
        }

        mem(dp, -1);
        ll ans = INF;
        FORAB(i, 0, T){
            ans = min(ans, Cat[0].L[i].ff + Cat[0].L[i].ss + go(1, i));
        }

        cout<<ans<<endl;
        Cat.clear();
	}

    return 0;
}
