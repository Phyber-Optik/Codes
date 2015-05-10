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
        scanf("%d", &N);
        while(N--){
            string s;
            cin>>s;
            vector<int>v;
            int ara[6]={1, 2, 3, 4, 6, 12};
            int flag, g=0;
            for(int i=0; i<6; i++){
                int temp=ara[i];
                flag=0;
                for(int j=0; j<temp; j++){
                    int f=1;
                    g=j;
                    for(int k=0; k<12/temp; k++){
                        if(s[g]=='O'){
                            f=0;
                            break;
                        }
                        g+=temp;
                    }

                    if(f==1){
                        flag=1;
                        break;
                    }
                }

                if(flag==1){
                    v.push_back(temp);
                }
            }

            cout<<v.size();

            for(int i=v.size()-1; i>=0; i--){
                cout<<" "<<12/v[i]<<'x'<<v[i];
            }

            cout<<endl;
            v.clear();
        }

        return 0;
    }
