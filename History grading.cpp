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

    int x[21];
    int y[21];
    //int L[21][21];

    int lcs(int m ,int n){
        int L[m+1][n+1];
        int i, j;

        for(i=0; i<=m; i++){
            for(j=0; j<=n; j++){
                if(i==0 || j==0){
                    L[i][j]=0;
                }

                else if(x[i]==y[j]){
                    L[i][j]= 1+ L[i-1][j-1];
                }

                else{
                    L[i][j]=max(L[i-1][j], L[i][j-1]);
                }
            }
        }

        return L[m][n];
    }


    int main(){
        mem(x, 0);
        mem(y, 0);

        int i, tmp, m, n;
        scanf("%d", &m);
        n=m;

        for(i=1; i<=m; i++){
            scanf("%d", &tmp);
            x[tmp]=i;
        }

        while(1){
            //mem(y, 0);
            for(i=1; i<=m; i++){
                if(scanf("%d", &tmp)==EOF)
                    return 0;
                y[tmp]=i;
            }

            printf("%d\n", lcs(m, n));
        }
        return 0;
    }

