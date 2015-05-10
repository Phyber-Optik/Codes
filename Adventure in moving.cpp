
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
#define pii             pair<int, int>
#define ff              first
#define ss              second

using namespace std;

vector<pii>st;
ll dp[210][110];
int des;

ll go(int fuel, int cur){
    if(st[cur].ff == des && fuel >= 100){
        return 0;
    }

    if(cur >= (st.size() - 1) || fuel < 0){
        return INF;
    }

    if(dp[fuel][cur] != -1) return dp[fuel][cur];

    ll ret = INF;

    int freq = abs(st[cur].ff - st[cur + 1].ff);
    for(int k = 0; (k <= (200 - fuel)); k++){
        ret = min(ret, k * st[cur].ss + go(k + fuel - freq, cur + 1));
    }

    return dp[fuel][cur] = ret;
}

int main(){
    //read(in);
    //write(out);
    int tc, a, b;
    string in;
    cin>>tc;
    bool f = false;
    getchar();
    while(tc--){
        st.clear();
        st.pb(pii(0, 0));
        cin>>des;
        getchar();
        bool flag = false;
        while(getline(cin, in)){
            if(in.size() == 0) break;
            stringstream ss;
            ss << in;
            ss >> a >> b;

            if(a < des) st.pb(pii(a, b));
        }

        st.pb(pii(des, 20000));
        mem(dp, -1);
        if(f == true){
            puts("");
        }
        f = true;

        ll r = go(100 - st[1].ff, 1);
        if(r == INF){
            puts("Impossible");
        }
        else printf("%lld\n", r);
    }
    return 0;
}
