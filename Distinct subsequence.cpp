/*  Towhidul Islam
    University Of Dhaka
    Problem Name :
    Algorithm Used :
*/

#include<bits/stdc++.h>

typedef long long ll;

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
#define fori(i, x, n)   for(int i = x; i < n; i++)
#define ford(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define pii             pair<int, int>

using namespace std;

string dp[10010][101];

string add(string s, string t){
    int m = s.size();
    int n = t.size();
    int k = max(m, n);
    string res;
    res.resize(k);

    int carry = 0, tmp;
    for(int i = 0; i < k; i++){
        tmp = 0;
        if(m - i > 0) tmp = s[m - i - 1] - '0';
        if(n - i > 0) tmp += t[n - i - 1] - '0';
        tmp += carry;

        carry = tmp / 10;
        tmp %= 10;
        res[i] = tmp + '0';
    }
    if(carry) res.pb(carry + '0');
    reverse(all(res));

    return res;
}

int main(){
    //read(in);
    //write(out);
    //cout<<add("99", "1");

    int tc;
    char s[10010], p[110];
    scan(tc);
    while(tc--){
        scanf("%s%s", s, p);
        int n = strlen(s);
        int q = strlen(p);

        //mem(dp, 0);
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = "1";
        }

        fori(i, 1, n + 1){
            fori(j, 1, q + 1){
                if(s[i-1] == p[j-1]){
                    dp[i][j] = add(dp[i-1][j], dp[i-1][j-1]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        cout<<dp[n][q]<<endl;
    }
    return 0;
}
