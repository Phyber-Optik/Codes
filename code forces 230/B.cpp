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
        int N, ara[10001];
        while(scanf("%d", &N)!=EOF){
            mem(ara, 0);
            int i=0, j, n=N;

            struct{
                bool st;
                int n1;
                int n2;
                int c1, c2;
            }s[100001];

            mem(s, 0);

            for(i=0; i<N; i++){
                scanf("%d", &s[i].n1);
            }

            int sum=0;
            s[0].c1=0;
            s[0].c2=0;
            for(i=0; i<N; i++){
                scanf("%d", &s[i].n2);
                for(int z=1; z<=s[i].n1; z++){
                    for(int x=z+1; x<=s[i].n1; x++){
                        int temp=z+x;
                        if(temp==s[i].n2){
                            if(s[i].c1*s[i].c2<z*x){
                                s[i].c1=z;
                                s[i].c2=z;
                                s[i].st=true;
                            }
                        }
                    }
                }
                if(s[i].st==true)
                    sum+=(s[i].c1*s[i].c2);

                else
                    sum--;
            }

            printf("%d\n", sum);
        }
        return 0;
    }
