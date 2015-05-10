/*  Towhidul Islam
    University Of Dhaka
    Problem Name :
    Algorithm Used :
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<vector>
#include<queue>
#include<fstream>
#include<sstream>
#include<set>
#include<climits>
#include<map>
#include<algorithm>
#include<iomanip>
#include<functional>

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
#define FORX(i, x, n)   for(int i = x; i < n; i++)
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define pii             pair<int, int>

using namespace std;

/*
template <class T> inline void debug( T x ){ cout << "x = " << x << endl; }
template <class T1, class T2> inline void
    debug( T1 x, T2 y ){ cout << "x = " << x << ", y = " << y << endl; }
template <class T1, class T2, class T3> inline void
    debug( T1 x, T2 y, T3 z ){
        cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    }
*/
template <class T> inline T GCD( T a, T b ) { if( a < 0 ) return GCD( -a , b );
    if( b < 0 ) return GCD( a, -b ); return ( b == 0 ) ? a : GCD( b, a%b ); }
template <class T> inline T LCM( T a, T b ) { if( a < 0 ) return LCM( -a, b );
    if( b < 0 ) return LCM( a, -b ); return a * ( b / GCD( a, b ) ); }

template <class T> inline T abso( T x ) { return x >= 0 ? x : -x; }
template <class T> inline T mod( T n, T m ) { return ( n%m + m ) % m; }

int Set(int N, int pos) { return N = N | (1 << pos); }
int reSet(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }

int main(){

    return 0;
}
