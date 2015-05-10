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
            vector<int>a;
            for(int i=0; i<n; i++){
                int temp;
                cin>>temp;
                a.push_back(temp);
            }

            sort(a.begin(), a.end());
            for(int i=0; i<n; i++){
                printf("%d ", a[i]);
            }

            cout<<endl;
        }
        return 0;
    }
