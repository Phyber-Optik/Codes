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
    #define INF 0x3f3f3f3f

    using namespace std;

    #define ROW 80
    #define COL 80

    int kadane(int* arr, int* start, int* finish, int n){
        int sum=0, maxSum=INT_MIN, i;
        *finish=-1;
        int local_start=0;

        for(i=0; i<n; i++){
            sum+=arr[i];
            if(sum<0){
                sum=0;
                local_start=i+1;
            }

            else if(sum>maxSum){
                maxSum=sum;
                *start=local_start;
                *finish=i;
            }
        }

        maxSum=max(0, maxSum);
        if(*finish!=-1)
            return maxSum;

        maxSum=arr[0];
        *start=*finish=0;
        for(i=1; i<n; i++){
            if(arr[i]>maxSum){
                maxSum=arr[i];
                *start=*finish=i;
            }
        }

        maxSum=max(0, maxSum);
        return maxSum;
    }


    void findMaxSum(int a[][COL], int row, int col){
        int maxSum=INT_MIN;

        int left, right, i;
        int temp[row], sum, start, finish;

        for(left=0; left<col; ++left){
            mem(temp, 0);
            for(right=left; right<col; ++right){
                for(i=0; i<row; ++i){
                    temp[i]+=a[i][right];
                }

                sum=kadane(temp, &start, &finish, row);

                if (sum > maxSum){
                    maxSum = sum;
                }
            }
        }

        maxSum=max(0, maxSum);
        printf("%d\n", maxSum);
    }


    int main(){
        read(in);
        int a[80][80];
        int N, i, j, m, n;
        scanf("%d", &N);
        while(N--){
            mem(a, 0);
            int s;

            scanf("%d", &s);

            for(int z=0; z<s; z++){
                for(int x=0; x<s; x++){
                    scanf("%d", &a[z][x]);
                }
            }
            findMaxSum(a, s, s);
        }
        return 0;
    }
