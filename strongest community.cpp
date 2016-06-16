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
#define lc              (node << 1)
#define rc              (node << 1) | 1

using namespace std;

typedef struct data
{
    int leftval, rightval, lf, rf, tf;
    data(){}
    data(int a, int b,  int c, int d, int e){
        leftval = a;
        rightval = b;
        lf = c;
        rf = d;
        tf = e;
    }
}Node;
Node t[MAX<<2];

int get_mid(int a, int b){
    return (a + b) >> 1;
}

int a[MAX];
Node combine(Node left, Node right){
    Node ret;
    ret.leftval = left.leftval;
    ret.rightval = right.rightval;
    if(left.leftval == right.leftval) ret.lf = left.lf + right.lf;
    else ret.lf = left.lf;
    if(left.rightval == right.rightval) ret.rf = left.rf + right.rf;
    else ret.rf = right.rf;
    ret.tf = max(left.tf, right.tf);
    if(left.rightval == right.leftval) ret.tf = max(ret.tf, left.rf + right.lf);

    return ret;
}

void init(int node, int l, int r){
    if(l == r){
        t[node].leftval = t[node].rightval = a[l];
        t[node].lf = t[node].rf = t[node].tf = 1;
        return;
    }

    int mid = get_mid(l, r);
    init(lc, l, mid);
    init(rc, mid + 1, r);

    t[node] = combine(t[lc], t[rc]);
    //dbg(t[node].tf);
}

Node query(int node, int l, int r, int st, int ed){
    if(l > r || l > ed || r < st) return Node(-1, -1, -1, -1, -1);
    if(st <= l && r <= ed){
        //dbg(l);
        //dbg(r);
        //dbg(t[node].tf);
        return t[node];
    }
    int mid = get_mid(l, r);
    Node left = query(lc, l, mid, st, ed);
    Node right = query(rc, mid + 1, r, st, ed);
    //cout<<node<<" "<<left.tf<<" "<<left.lf<<" "<<left.rf<<" "<<left.leftval<<" "<<left.rightval<<endl;
    //cout<<node<<" "<<right.tf<<" "<<right.lf<<" "<<right.rf<<" "<<right.leftval<<" "<<right.rightval<<endl;
    if(left.tf == -1) return right;
    else if(right.tf == -1) return left;
    else return combine(left, right);
}

int main(){
    //read(in);
    //write(out);
    int tc, l, r, cs = 1, n, c, q;
    scan(tc);
    while(tc--){
        scanf("%d%d%d", &n, &c, &q);
        FORAB(i, 1, n + 1) scan(a[i]);

        init(1, 1, n);
        printf("Case %d:\n", cs++);
        FORAB(i, 0, q){
            scanf("%d%d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r).tf);
        }
    }
    return 0;
}
