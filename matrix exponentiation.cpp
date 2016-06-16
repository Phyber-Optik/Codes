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
#define MAX             3

using namespace std;

class Matrix{
public:
    int R, C, M[MAX][MAX];
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
                    res.M[i][j] += (M[i][k] % MOD * tmp.M[k][j] % MOD) % MOD;
                    res.M[i][j] %= MOD;
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


int main(){
    //read(in);
    //write(out);

	int tc, cs = 1;
	scan(tc);
	while(tc--){

        printf("Case %d: ", cs++);
	}

    return 0;
}
