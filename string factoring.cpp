
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
#define INF             1000000000
#define eps             1e-9
#define arraysz(a)      sizeof (a)/sizeof(a[0])
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define chkwhere        cout<<"LOL\n"
#define pii             pair<int, int>
#define lim             32000
using namespace std;

int dp[81], n;
bool t[81];
string s;
int go(int pos){
    if(pos >= n) return 0;
    if(t[pos] == true) return dp[pos];
    t[pos] = true;

    int ret1 = INF, ret2 = INF;
    for(int i = pos; i < n; i++){
        int len = i - pos + 1;
        string tmp = s.substr(pos, len);

        for(int j = i + 1; j < n; j += len){
            if(tmp == s.substr(j, len) && j + len < n){
                ret1 = len + go(j + len);
            }
            else{
                ret2 = len + go(j);
                break;
            }
        }
    }

    return dp[pos] = min(ret1, ret2);
}

int main(){
    //read(in);
    //write(out);
    while(cin>>s){
        if(s == "*") break;
        n = s.size();
        mem(t, false);
        printf("%d\n", go(0));
    }
    return 0;
}
