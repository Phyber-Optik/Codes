/*  Towhidul Islam
    University Of Dhaka
    Problem Name : LigtOJ 1207
    Algorithm Used : Segment Tree
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
#define pii             pair<ll, ll>
#define MOD             1000000007
#define MAX             200007
int L(int x) { return x << 1; }
int R(int x) { return (x << 1) + 1; }
#define M(a, b)         int M(int x, int y) { return (a + b) << 1; }

using namespace std;

pii pos[MAX];
bool t[4*MAX], lazy[4*MAX];

void push(int node, int l, int r){
    if(lazy[node] == false){
        t[node] = false;
        if(r != l){
            lazy[L(node)] = false;
            lazy[R(node)] = false;
        }
        lazy[node] = true;
    }
}

void update(int node, int l, int r, int st, int ed){
    push(node, l, r);
    if(l > r || l > ed || r < st) return;
    if(l >= st && r <= ed){
        t[node] = false;
        if(l != r){
            lazy[L(node)] = false;
            lazy[R(node)] = false;
        }
        return;
    }

    int mid = (l + r) >> 1;
    update(L(node), l, mid, st, ed);
    update(R(node), mid + 1, r, st, ed);
    t[node] = t[L(node)] | t[R(node)];
}

bool query(int node, int l, int r, int st, int ed){
    if(l > r || l > ed || r < st) return 0;
    push(node, l, r);
    if(l >= st && r <= ed){
        //dbg(t[node]);
        return t[node];
    }

    int mid = (l + r) >> 1;
    return query(L(node), l, mid, st, ed) | query(R(node), mid + 1, r, st, ed);
}

int main(){
    //read(in);
    //write(out);
    int n, q, a, b, tc, cs = 1;
    scan(tc);
    while(tc--){
        scan(n);
        mem(t, true);
        mem(lazy, true);

        FORAB(i, 0, n){
            scanf("%d%d", &a, &b);
            pos[i] = pii(a, b);
        }

        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            ans += query(1, 1, MAX, pos[i].ff, pos[i].ss);
            //cout<<pos[i].ff<<" "<<pos[i].ss<<endl;
            //dbg(ans);
            update(1, 1, MAX, pos[i].ff, pos[i].ss);
        }

        printf("Case %d: %d\n", cs++, ans);
    }
    return 0;
}
