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

    using namespace std;

    int main(){
        int N;
        scanf("%d", &N);

        while(N--){
            string a, b, m, n;
            cin>>a>>b;

            int l=a.size()-1;

            int pos=0;
            while(l>=0){
                m.push_back(a[l]);
                pos++;
                l--;
            }

            l=b.size()-1;

            pos=0;
            while(l>=0){
                n.push_back(b[l]);
                pos++;
                l--;
            }

            if(n.size()>m.size()){
                swap(m, n);
            }

            //cout<<m<<endl;
            //cout<<n<<endl;

            string result;
            int carry=0, k, x;
            for(k=m.size()-1, x=n.size()-1; k>=0; k--, x--){
                int temp=m[k]-'0';
                if(x>=0)
                    temp+=(n[x]-'0');
                temp+=carry;
                carry=temp/10;
                temp=temp%10 + '0';
                result.push_back(temp);
            }

            if(carry)
                result.push_back(carry+'0');

            pos=0;
            while(result[pos]=='0'){
                pos++;
            }

            for(int z=pos; z<result.size(); z++){
                printf("%c", result[z]);
            }

            printf("\n");
            a.clear();
            b.clear();
            m.clear();
            n.clear();
            result.clear();
        }
        return 0;
    }
