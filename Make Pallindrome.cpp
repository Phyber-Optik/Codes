
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
string a;
int dp[1010][1010];
int go(int i, int j){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ret;
    if(a[i] != a[j]) ret = min(1 + go(i + 1, j), 1 + go(i, j - 1));
    else ret = go(i + 1, j - 1);

    return dp[i][j] = ret;
}
int main(){
    //read(in);
    //write(out);
    while(cin>>a){
        int n = a.size();
        FORAB(i, 0, n + 1){
            FORAB(j, 0, n + 1){
                dp[i][j] = -1;
            }
        }
        int ret = go(0, n - 1);

        string res;
        res.resize(n + ret);

        printf("%d ", ret);
        int i = 0, j = n - 1, r = n + ret - 1, l = 0;
        while(dp[i][j]){
            if(dp[i][j-1] + 1 == dp[i][j]){
                res[r] = a[j];
                res[l] = a[j];
                r--, l++;
                j--;
            }
            else if(dp[i+1][j] + 1 == dp[i][j]){
                res[l] = a[i];
                res[r] = a[i];
                l++, r--;
                i++;
            }
            else{
                res[r] = a[i];
                res[l] = a[i];
                r--, l++;
                i++, j--;
            }
        }
        for(int k = i; k <= j; k++){
            res[l++] = a[k];
        }
        cout<<res;
        puts("");
    }
    return 0;
}
