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

    typedef long long ll;

    #define pb push_back
    #define mem(a, x) memset(a, x, sizeof a)
    #define PI acos(-1)
    #define MAX 10000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;

    int main(){
        //read(in);
        int N, tc=0;
        scanf("%d", &N);
        while(N--){
            int i;
            string a, b, m, n;
            getchar();
            scanf("%d", &i);
            while(i--){
                int n1, n2;
                scanf("%d %d", &n1, &n2);
                n1=n1+'0';
                n2=n2+'0';
                a.push_back(n1);
                b.push_back(n2);
            }

            //cout<<a<<" "<<b<<endl;

            string result;
            int carry=0, j, k;
            for(j=a.size()-1; j>=0; j--){
                int temp=(a[j]-'0')+(b[j]-'0');
                temp+=carry;
                carry=temp/10;
                temp=temp%10+'0';
                result.push_back(temp);
            }

            if(carry){
                result.push_back(carry+'0');
            }

            if(tc)
                printf("\n");

            for(k=result.size()-1; k>=0; k--){
                printf("%c", result[k]);
            }
            printf("\n");


            tc++;
            a.clear();
            b.clear();
            result.clear();
        }
        return 0;
    }
