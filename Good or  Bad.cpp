
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
#define chkwhere        cout<<"LOL\n"
#define pii             pair<int, int>

using namespace std;
char a[55];
int dp[55][6][6][2][2];

bool isVowel(char ch){
    if(ch == 'A' || ch == 'E'|| ch == 'I' || ch == 'O' || ch == 'U'){
        return true;
    }
    return false;
}

int go(int i, int x, int y, int isC, int isV, int isN){
    if(x > 2 || y > 4 && isN == 0){
        return 2;
    }
    if(x > 2 || y > 4 && isN == 1){
        return 1;
    }
    if(a[i] == '\0'){
        return 0;
    }

    if(dp[i][x][y][isC][isV][isN] != -1) return dp[i][x][y][isC][isV][isN];

    int ret = 0;
    if(a[i] == '?'){
        if(isV == false) x = 0;
        if(isC == false) y = 0;

        int ret1 = go(i + 1, x + 1, y, 0, 1, 1);
        int ret2 = go(i + 1, x, y + 1, 1, 0, 1);

        ret = max(ret, max(ret1, ret2));

    }

    else if(isVowel(a[i]) == true){
        if(isV == false){
            x = 0;
        }
        ret = max(ret, go(i + 1, x + 1, y, 0, 1, 0));
    }
    else{
        if(isC == false) y = 0;
        ret = max(ret, go(i + 1, x, y + 1, 1, 0, 0));
    }

    return dp[i][x][y][isC][isV][isN] = ret;
}

int main(){
    //read(in);
    //write(out);
    int tc, t = 1;
    scan(tc);
    char ans[3][6] = {"GOOD", "MIXED", "BAD"};

    while(tc--){
        scanf("%s", a);
        mem(dp, -1);
        char *res = ans[go(0, 0, 0, 0, 0, 0)];
        printf("Case %d: %s\n", t++, res);
    }
    return 0;
}
