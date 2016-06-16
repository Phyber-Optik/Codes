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
#define pii             pair<ll, ll>
#define MOD             1000000007
#define MAX             100007

using namespace std;

int L(int node){
    return node << 1;
}
int R(int node){
    return (node << 1) + 1;
}
int get_mid(int a, int b){
    return (a + b) >> 1;
}

map<int, bool>mp;
map<int, int>id;
pii point[MAX];
int qlist[MAX];
int a[2*MAX];

int t[6*MAX], lazy[6*MAX];

void push(int node, int l, int r){
    if(lazy[node] != 0){
        t[node] += (r - l + 1) * lazy[node];
        if(r != l){
            lazy[L(node)] += lazy[node];
            lazy[R(node)] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int st, int ed, int x){
    push(node, l, r);
    if(l > r || l > ed || r < st) return;
    if(l >= st && r <= ed){
        t[node] += (r - l + 1) * x;
        if(l != r){
            lazy[L(node)] += x;
            lazy[R(node)] += x;
        }
        return;
    }

    int mid = (l + r) >> 1;
    update(L(node), l, mid, st, ed, x);
    update(R(node), mid + 1, r, st, ed, x);
    t[node] = t[L(node)] + t[R(node)];
}

int query(int node, int l, int r, int st, int ed){
    if(l > r || l > ed || r < st) return 0;
    push(node, l, r);
    if(l >= st && r <= ed){
        return t[node];
    }

    int mid = (l + r) >> 1;
    return query(L(node), l, mid, st, ed) + query(R(node), mid + 1, r, st, ed);
}

int main(){
    //read(in);
    //write(out);
    int tc, cs = 1, cnt, n, q, x, y;
    scan(tc);
    while(tc--){
        scan(n);
        scan(q);
        cnt = 0;
        FORAB(i, 0, n){
            scanf("%d%d", &x, &y);
            point[i] = pii(x, y);
            if(mp.find(x) == mp.end()){
                mp[x] = true;
                a[cnt++] = x;
            }
            if(mp.find(y) == mp.end()){
                mp[y] = true;
                a[cnt++] = y;
            }
        }

        FORAB(i, 0, q){
            scanf("%d", &x);
            qlist[i] = x;
            if(mp.find(x) == mp.end()){
                mp[x] = true;
                a[cnt++] = x;
            }
        }

        sort(a, a + cnt);
        FORAB(i, 0, cnt){
            id[a[i]] = i + 1;
        }

        mem(t, 0);
        mem(lazy, 0);
        for(int i = 0; i < n; i++){
            x = point[i].ff;
            y = point[i].ss;

            x = id[x];
            y = id[y];

            update(1, 1, cnt - 1, x, y, 1);
        }

        printf("Case %d:\n", cs++);
        FORAB(i, 0, q){
            x = id[qlist[i]];
            printf("%d\n", query(1, 1, cnt -1, x, x));
        }

        mp.clear();
        id.clear();
    }
    return 0;
}
