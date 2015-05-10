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
        string s1, s2;
        cin>>s1>>s2;
        int a[256], b[256];
        mem(a, 0);
        mem(b, 0);
        for(int i=0; i<s1.size(); i++){
            a[s1[i]]++;
        }

        for(int j=0; j<s2.size(); j++){
            b[s2[j]]++;
        }

        int s=0;
        for(char ch='a'; ch<='z'; ch++){
            if(b[ch]!=0 && a[ch]==0){
                printf("-1\n");
                return 0;
            }

            s+=min(b[ch], a[ch]);
        }

        cout<<s<<endl;
        return 0;
    }
