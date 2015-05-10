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

    typedef long long ll;

    #define pb push_back
    #define mem(a, x) memset(a, x, sizeof a)
    #define PI acos(-1)
    #define MAX 10000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;

    int main(){
        int n, c[105];
        while(scanf("%d", &n)!=EOF){
            int a[n];
            mem(c, 0);
            for(int i=0; i<n; i++){
                scanf("%d", &a[i]);
                c[a[i]]++;
            }

            int m=0;
            for(int i=0; i<101; i++){
                //cout<<c[i]<<endl;
                if(m<c[i])
                    m=c[i];
            }

            printf("%d\n", m);
        }
        return 0;
    }
