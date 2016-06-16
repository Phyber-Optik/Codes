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
#define M(a, b)         int M(int x, int y) { return (a + b) << 1; }

using namespace std;

int c, block_size;

int get_block(int pos){
    return (pos / block_size);
}

struct query{
    int L, R, block, id, ans;
    query(){;}
    query(int l, int r, int i){
        L = l;
        R = r;
        block = get_block(l);
        id = i;
    }

    bool operator<(const query &a) const{
        if(block == a.block) return R < a.R;
        return block < a.block;
    }
};
query qList[MAX];

int a[MAX], cnt[MAX], f[MAX], mx, ans[MAX];
void inline add(int pos){
    f[cnt[a[pos]]]--;
    cnt[a[pos]]++;
    f[cnt[a[pos]]]++;
    if(cnt[a[pos]] > mx){
        mx = cnt[a[pos]];
    }
}

void inline remove(int pos){
    if(f[cnt[a[pos]]] == 1){
        mx = cnt[a[pos]] - 1;
    }
    f[cnt[a[pos]]]--;
    cnt[a[pos]]--;
    f[cnt[a[pos]]]++;
}

void process(int n){
    sort(qList, qList + n);

    int currentL = qList[0].L;
    int currentR = qList[0].R;
    for(int i = currentL; i <= currentR; i++){
        add(i);
    }

    ans[qList[0].id] = mx;
    for(int i = 1; i < n; i++){
        int x = qList[i].L;
        int y = qList[i].R;

        while(currentL < x) {
            remove(currentL);
            currentL++;
        }


        while(currentL > x) {
            add(currentL);
            currentL--;
        }

        while(currentR < y) {
            add(currentR);
            currentR++;
        }

        while(currentR > y) {
            remove(currentR);
            currentR--;
        }
        ans[qList[i].id] = mx;
    }

    //chkwhere;
}


int main(){
    //read(in);
    //write(out);
    int n, q, tc, cs = 1, l, r;
    scan(tc);
    while(tc--){
        mx = 0;
        mem(f, 0);
        mem(cnt, 0);
        scanf("%d%d%d", &n, &c, &q);
        block_size = sqrt(c);
        FORAB(i, 1, n + 1){
            scan(a[i]);
        }

        FORAB(i, 0, q){
            scanf("%d%d", &l, &r);
            qList[i] = query(l, r, i);
        }

        process(q);
        printf("Case %d:\n", cs++);
        FORAB(i, 0, q){
            print(ans[i]);
        }
    }
    return 0;
}
