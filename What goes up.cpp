
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

vector<int>seq;
vector<int>res;

int find_lis(vector<int> &a, vector<int> &b){
	vector<int> p(a.size());
	int u, v;

	if (a.empty()) return 0;

	b.push_back(0);
	for (size_t i = 1; i < a.size(); i++) {
        // If next element a[i] is greater than last element of
        // current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i]){
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

        // Binary search to find the smallest element referenced by b which is just bigger than a[i]
        // Note : Binary search is performed on b (and not a).
        // Size of b is always <=k and hence contributes O(log k) to complexity.
		for (u = 0, v = b.size()-1; u < v; ){
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1;
			else v = c;
		}

        // Update b if new value is smaller then previously referenced value
		if (a[i] < a[b[u]]){
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}

	for (u = b.size(), v = b.back(); u--; v = p[v]){
        b[u] = v;
	}
    return b.size();
}


int main(){
    read(in);
    //write(out);
    int temp;
    while(cin>>temp){
        seq.pb(temp);
    }

    int r = find_lis(seq, res);
    printf("%d\n-\n", r);
    for(size_t i = 0; i < res.size(); i++){
        //dbg(res[i]);
        printf("%d\n", seq[res[i]]);
    }

    res.clear();
    seq.clear();
    return 0;
}
