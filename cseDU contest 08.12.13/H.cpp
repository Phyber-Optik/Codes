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

    int pile[10000000];

    using namespace std;

    int main(){
        int N, weight[25], s=0;
        mem(pile, 0);

        int i, j;

        scanf("%d", &N);
        for(i=0; i<N; i++){
            scanf("%d", &weight[i]);
            s+=weight[i];
        }

        sort(weight, weight+N);

        for(i=0; i<N; i++){
            for(j=s/2; j>=weight[i]; j--){
                pile[j]=max(pile[j], pile[j-weight[i]]+weight[i]);
            }
        }

        printf("%d\n", s-2*pile[s/2]);
        return 0;
    }
