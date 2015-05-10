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
        int N;
        int n;
        while(scanf("%d", &n)!=EOF){
            string s[301];
            for(int i=0; i<n; i++)
                cin>>s[i];

            char dia=s[0][0];
            int flag=1;
            int j=0;
            for(int i=0; i<n; i++){
                if(s[i][j]!=dia){
                    flag=0;
                    break;
                }
                j++;
            }

            j=n-1;
            for(int i=0; i<n; i++){
                if(s[i][j]!=dia){
                    flag=0;
                    break;
                }
                j--;
            }

            char nond;
            if(s[1][0]==s[0][1])
                nond=s[1][0];
            else{
                flag=0;
            }

            if(dia==nond){
                flag=0;
            }

            j=0;
            for(int i=0; i<n; i++){
                s[i][j]=nond;
                j++;
            }

            j=n-1;
            for(int i=0; i<n; i++){
                s[i][j]=nond;
                j--;
            }

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(s[i][j]!=nond){
                        flag=0;
                        break;
                    }
                }
            }

            //for(int i=0; i<n; i++){
                //cout<<s[i]<<endl;
            //}

            if(flag==0){
                cout<<"NO\n";
            }

            else{
                cout<<"YES\n";
            }

        }
        return 0;
    }
