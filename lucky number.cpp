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
#define MAX             1429450
#define L 				node << 1
#define R 				(node << 1) | 1

using namespace std;

int t[MAX*4];

void init(int node, int l, int r){
	if(l > r) return;
	if(l == r){
		t[node] = l & 1;
		return;
	}

	int mid = (l + r) >> 1;
	init(L, l, mid);
	init(R, mid + 1, r);
    t[node] = t[L] + t[R];
}

void update(int node, int l, int r, int cnt){
	if(l == r){
		t[node] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if(t[L] >= cnt) update(L, l, mid, cnt);
	else update(R, mid + 1, r, cnt - t[L]);

	t[node] = t[L] + t[R];
}

int query(int node, int l, int r, int x){
	if(l == r){
		return l;
	}

	int mid = (l + r) >> 1;
	if(t[L] >= x) return query(L, l, mid, x);
	else return query(R, mid + 1, r, x - t[L]);
}

int a[100001];
void process(){
	a[1] = 1;
	init(1, 1, MAX);
	for(int i = 2; i < 100001; i++){
		int id = query(1, 1, MAX, i);
		a[i] = id;
		int last_fact = (MAX / id) * id;
		for(int k = last_fact; k >= 1; k -= id){
			update(1, 1, MAX, k);
		}
	}
}

int main(){
    //read(in);
    //write(out);
    //chkwhere;
    process();
	int tc, cs = 1, n;
	scanf("%d", &tc);
	while(tc--){
		scan(n);
		printf("Case %d: %d\n", cs++, a[n]);
	}
	return 0;
}
