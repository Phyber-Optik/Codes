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
const ll INF = 200000000000000000;
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

using namespace std;
void R1();
void R2();
void L();
void L1();
void S();
void AN();

int cur = 0;
string str;
void match(char t){
    if(str[cur] == t){
        cur++;
    }
    else if(t == ')'){
        printf("Right parenthesis match not found!");
    }

    else if(t == ','){
        printf("Comma not found!");
    }
}

void Dig(){
    if(str[cur] >= '0' && str[cur] <= '9'){
        cur++;
    }
}

void Let(){
    if(str[cur] >= 'a' && str[cur] <= 'z'){
        cur++;
    }
}

void R1(){
    int tmp = cur;
    Dig();
    cur = tmp;
    Let();
}

void R2(){
    R1();
    AN();
}

void AN(){
    dbg(str[cur]);
    int tmp = cur;
    Dig();
    R2();

    //backtrack, try the other rule
    cur = tmp;
    Let();
    R2();

}

void L1(){
    S();
    match(',');
}

void L(){
    S();
    L1();
}

void S(){
    int tmp = cur;
    if(str[cur] == '('){
        cur++;
        L();
        match(')');
    }
    else if(str[cur] == ')'){
        match(')');
    }
    else{
        cur = tmp;
        AN();
    }
}

int main(){
    read(in);
    //write(out);
	int tc, cs = 1;
    cin>>str;
    S();
    if(str[cur] == '$'){
        printf("String Accepted\n");
    }
    else{
        printf("Not accepted\n");
    }
    return 0;
}
