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

    using namespace std;

    int main(){
        int N, a[1001];
        while(scanf("%d", &N) &&N ){
            //mem(a, 0);
            int cz=0, cn=0;
            for(int z=0; z<N; z++){
                scanf("%d", &a[z]);
                if(a[z])
                    cn++;
                else
                    cz++;
            }

            if(cz==N)
                printf("0\n");

            else if(cn>1){
                int f=0;
                for(int z=0; z<N; z++){
                    if(a[z]){
                        if(f)
                            printf(" ");
                        f=1;
                        printf("%d", a[z]);
                    }
                }

                printf("\n");
            }

            else{
                int maxSum=a[0];
                int z;
                for(z=1; z<N; z++){
                    if(a[z]>maxSum){
                        maxSum=a[z];
                    }
                }

                printf("%d\n", maxSum);
            }
        }
        return 0;
    }

