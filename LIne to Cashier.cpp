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
        int n;
        while(scanf("%d", &n)!=EOF){
            int a[n];
            for(int i=0; i<n; i++){
                scanf("%d", &a[i]);
            }


            int result=10000000;
            for(int i=0; i<n; i++){
                int t=a[i]*15;
                //cout<<t<<endl;
                int temp;
                for(int j=0; j<a[i]; j++){
                    scanf("%d", &temp);
                    t+=temp*5;
                }

                result=min(result, t);
            }

            printf("%d\n", result);
        }
        return 0;
    }
