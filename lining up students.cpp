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
#define lc				(node << 1)
#define rc				(node << 1) | 1

using namespace std;

int t[MAX<<2];
int get_mid(int l, int r){
	return (l + r) >> 1;
}

void init(int node, int l, int r){
	if(l == r){
		t[node] = 1;
		return;
	}

	int mid = get_mid(l, r);
	init(lc, l, mid);
	init(rc, mid + 1, r);
	t[node] = t[lc] + t[rc];
}

void update(int node, int l, int r, int pos){
	if(l == r){
		t[node] = 0;
		return;
	}
	int mid = get_mid(l, r);
	if(pos <= mid) update(lc, l, mid, pos);
	else update(rc, mid + 1, r, pos);

	t[node] = t[lc] + t[rc];
}

int query(int node, int l, int r, int k){
	if(l == r) return l;
	int mid = get_mid(l, r);
	if(t[lc] >= k) query(lc, l, mid, k);
	else query(rc, mid + 1, r, k - t[lc]);
}

int a[MAX];
int main(){
    //read(in);
    //write(out);
	int tc, cs = 1, n;
	scan(tc);
	while(tc--){
		scan(n);
		FORAB(i, 0, n){
			scan(a[i]);
		}

		init(1, 1, n);
		FORD(i, 1, n){
			int pos =  i + 1 - a[i];
			int tmp = query(1, 1, n, pos);
			update(1, 1, n, tmp);
		}

		printf("Case %d: %d\n", cs++, query(1, 1, n, 1));
	}
    return 0;
}
