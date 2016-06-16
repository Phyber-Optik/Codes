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
#define pii             pair< int, int >
#define piii            pair< int, pii >
#define MOD             1000000007
#define MAX             201

using namespace std;

struct data{
    int u, v, w;
    data(int a,int b, int c){
        u = a;
        v = b;
        w = c;
    }

    bool operator < (const data & p) const{
        return w > p.w;
    }
};

class Union_Find{
  public:
    int id[MAX], sz[MAX];
    Union_Find(int n){
        for (int i = 1; i <= n; ++i){
            id[i] = i;
            sz[i] = 1;
        }
    }

    int root(int i){
        while(i != id[i]){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    int find(int p, int q){
        return root(p) == root(q);
    }
    void unite(int p, int q){
        int i = root(p);
        int j = root(q);

        if(sz[i] < sz[j]){
            id[i] = j;
            sz[j] += sz[i];
        }
        else{
            id[j] = i;
            sz[i] += sz[j];
        }
    }
};



void clr(priority_queue<data>&pq){
    while(!pq.empty()){
        pq.pop();
    }
}

int main(){
    //read(in);
    //write(out);
	int tc, cs = 1, n, W, u, v, w;
	scan(tc);
	while(tc--){
        scanf("%d%d", &n, &W);
		printf("Case %d:\n", cs++);

        int cur = 0, cnt = 0;
        
        priority_queue < data > pq, tmp;
        FORAB(i, 0, W){
            scanf("%d%d%d", &u, &v, &w);
            pq.push(data(u, v, w));
            Union_Find UF(n);
            cur = 0, cnt = 0;
            while(!pq.empty() && cnt  < n - 1){
                u = pq.top().u;
                v = pq.top().v;
                w = pq.top().w; 
                if(UF.find(u, v) == false){
                    UF.unite(u, v);
                    tmp.push(pq.top());
                    cnt++;
                    cur += w;
                }
                pq.pop();
            }
            
            clr(pq);
            while(!tmp.empty()){
                pq.push(tmp.top());
                tmp.pop();
            }

            if(cnt == n - 1)
                printf("%d\n", cur);
            else printf("-1\n");
        }
    }
    return 0;
}
