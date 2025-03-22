#include<stdio.h>
#include<math.h>

int main() {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", llabs(a - b));
}
