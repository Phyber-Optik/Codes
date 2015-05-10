#include<cstdio>

using namespace std;
int main(){
    int a, b, c;
    int N;

    scanf("%d", &N);
    while(N--){
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", c*(a+a-b)/(a+b));
    }
    return 0;
}
