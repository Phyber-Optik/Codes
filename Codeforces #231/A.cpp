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
        string s;
        while(cin>>s){
            int l=s.size();
            int a=0, b=0, c=0;
            int i=0;
            while(s[i]!='+'){
                a++;
                i++;
            }

            i++;
            while(s[i]!='='){
                b++;
                i++;
            }

            i++;
            while(s[i]){
                c++;
                i++;
            }

            //cout<<a<<b<<c<<endl;
            if(a+b==c){
                cout<<s<<endl;
            }

            else if((a+1)+b==c-1){
                a++;
                while(a--){
                    cout<<"|";
                }

                cout<<'+';

                while(b--){
                    cout<<"|";
                }

                c--;
                cout<<"=";
                while(c--){
                    cout<<"|";
                }

                cout<<endl;
            }

            else if(a+b-1==c+1){
                if(a>1)
                    a--;
                else
                    b--;
                while(a--){
                    cout<<"|";
                }

                cout<<'+';

                while(b--){
                    cout<<"|";
                }

                c++;
                cout<<"=";
                while(c--){
                    cout<<"|";
                }

                cout<<endl;
            }

            else
                cout<<"Impossible\n";
        }
        return 0;
    }
