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
            vector<int> m1, m2;
            int a, b;
            while(n--){
                scanf("%d %d", &a, &b);
                int flag=1;
                for(int i=0; i<m1.size(); i++){
                    if(m1[i]==a){
                        flag=0;
                        break;
                    }
                }

                if(flag){
                    m1.pb(a);
                }

                flag=1;
                for(int i=0; i<m2.size(); i++){
                    if(m2[i]==b){
                        flag=0;
                        break;
                    }
                }

                if(flag){
                    m2.pb(b);
                }
            }

            if(m1.size()<m2.size())
                printf("%d\n", m1.size());
            else{
                printf("%d\n", m2.size());
            }
        }
        return 0;
    }
