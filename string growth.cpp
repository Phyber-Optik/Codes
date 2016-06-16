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
#define MAX             3

using namespace std;

class Matrix{
public:
    int R, C;
    ll M[MAX][MAX];
    Matrix(int R, int C){
        this->R = R;
        this->C = C;
    }

    Matrix operator*(Matrix tmp){
        Matrix res(R, tmp.C);
        FORAB(i, 0, res.R){
            FORAB(j, 0, res.C){
                res.M[i][j] = 0;
                FORAB(k, 0, tmp.R){
                    res.M[i][j] = (res.M[i][j] + (M[i][k] % MOD * tmp.M[k][j] % MOD) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    Matrix unit(){
        FORAB(i, 0, R){
            FORAB(j, 0, C){
                if(i == j) M[i][j] = 1;
                else M[i][j] = 0;
            }
        }
    }

    void set_elem(int i, int j, int Val){
        M[i][j] = Val;
    }

    int get_elem(int i, int j){
        return M[i][j];
    }

    void printMat(){
        puts("printing matrix: ");
        FORAB(i, 0, R){
            FORAB(j, 0, C){
                cout<<M[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"dimension: "<<R<<" x "<<C<<endl;
    }


    Matrix exponent(int e){
        Matrix base = *this;
        Matrix res(base.R, base.C);
        res.unit();

        while(e){
            if(e&1){
                res = res * base;
            }
            e >>= 1;
            base = base * base;
        }
        return res;
    }
};

bool same_sign(ll x, ll y){
    if(x >= 0 && y < 0) return false;
    if(x < 0 && y >= 0) return false;
    return true;
}

pii solve_eqn(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2){
    long long c  = x1, d  = y1;
    long long cp = x2, dp = y2;
    long long x = z1, y = z2;

    if ((c * dp - d * cp) == 0) {
        return pii(-1, -1);
    }

    long long a0 = (x * dp - y * d) / (c * dp - d * cp);
    long long b0 = (c * y - x * cp) / (c * dp - d * cp);
    if (((x * dp - y * d) % (c * dp - d * cp)) || ((c * y - x * cp) % (c * dp - d * cp))
        || a0 < 0 || b0 < 0) {
        return pii(-1, -1);
    }

    return pii(a0, b0);
}

void go(int n, int x, int m, int y, int k){
    Matrix A(2, 2);
    A.set_elem(0, 0, 1);
    A.set_elem(0, 1, 1);
    A.set_elem(1, 0, 1);
    A.set_elem(1, 1, 0);

    ll x1, y1, x2, y2;

    A = A.exponent(n);
    x1 = A.M[0][0];
    y1 = A.M[0][1];

    A.set_elem(0, 0, 1);
    A.set_elem(0, 1, 1);
    A.set_elem(1, 0, 1);
    A.set_elem(1, 1, 0);

    A = A.exponent(m);
    x2 = A.M[0][0];
    y2 = A.M[0][1];

    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    pii ret = solve_eqn(x1, y1, (ll)x, x2, y2, (ll)y);

    if(ret.ff == -1){
        puts("Impossible");
        return;
    }

    A.set_elem(0, 0, 1);
    A.set_elem(0, 1, 1);
    A.set_elem(1, 0, 1);
    A.set_elem(1, 1, 0);
    A = A.exponent(k);

    ll ans = ((A.M[0][0] % MOD * ret.ff % MOD) % MOD + (A.M[0][1] % MOD * ret.ss % MOD) % MOD) % MOD;
    printf("%lld\n", ans);
}


int main(){
    //read(in);
    //write(out);

	int tc, cs = 1, n, m, x, y, k;
	scan(tc);
	while(tc--){
        scanf("%d%d%d%d%d", &n, &x, &m, &y, &k);
        if(n > m){
            swap(n, m);
            swap(x, y);
        }
        printf("Case %d: ", cs++);
        if(m >= 46) {
			printf("Impossible\n");
			continue;
		}
        go(n, x, m, y, k);
	}

    return 0;
}
