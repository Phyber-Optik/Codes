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
#define pii             pair<int, int>
#define MOD             1000000007
#define MAX             2002
#define lc              (node << 1)
#define rc              (node << 1) | 1

using namespace std;
pii t[MAX<<2];
int a[2002];

int get_mid(int l, int r){
    return (l + r) >> 1;
}

int c = 0;
void init(int node, int l, int r){
    c++;
    if(l == r){
        t[node] = pii(a[l], l);
        return;
    }

    int mid = get_mid(l, r);
    init(lc, l, mid);
    init(rc, mid + 1, r);

    if(t[lc].ff <= t[rc].ff) t[node] = t[lc];
    else t[node] = t[rc];
}

pii query(int node, int l, int r, int st, int ed){
    if(l > r || l > ed || r < st) return pii(-1, -1);
    if(st <= l && r <= ed) return t[node];
    int mid = get_mid(l, r);
    pii left = query(lc, l, mid, st, ed);
    pii right = query(rc, mid + 1, r, st, ed);
    if(left.ff == -1) return right;
    if(right.ff == -1) return left;
    if(left.ff <= right.ff) return left;
    return right;
}

int h[2002][2002], G[2002][2002];

int clc(int l, int r){
    c++;
    if(l > r) return -1;
    pii ret = query(1, 1, MAX, l, r);
    int mx = (r - l + 1) * ret.ff;

    int  left = clc(l, ret.ss - 1);
    int right = clc(ret.ss + 1, r);

    mx = max(mx, left);
    mx = max(mx, right);

    return mx;
}

int getMaxArea(int hist[], int n){
    stack<int> s;
 
    int max_area = 0;
    int tp;
    int area_with_top;
 
    int i = 0;
    while (i < n){
        if (s.empty() || hist[s.top()] <= hist[i]){
            s.push(i++);
        }
 
        else{
            tp = s.top();
            s.pop();
 
            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false){
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}

int process(int m, int n){
    mem(h, 0);
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = m; j >= 1; j--){
            if(G[j][i] == 0) cnt++;
            else cnt = 0;
               h[j][i] = cnt;
        }
    }

    int mx = 0;
    FORAB(i, 1, m + 1){
        FORAB(j, 1, n + 1){
            a[j] = h[i][j];
        }

        mx = max(mx, getMaxArea(a, n));
    }
    return mx;
}

int main(){
    //read(in);
    //write(out);
	int tc, cs = 1, m, n;
	scan(tc);
	while(tc--){
        scanf("%d%d", &m, &n);
        FORAB(i, 1, m + 1){
            FORAB(j, 1, n + 1){
                scanf("%1d", &G[i][j]);
            }
        }
		printf("Case %d: %d\n", cs++, process(m, n));
	}
    return 0;
}
