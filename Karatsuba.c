#include <stdio.h>
#include <math.h>

int length(int num){
    int length=0;
    while(num!=0){
        num/=10;
        length++;
    }
    return length;
}

long long karatsuba(long long x,long long y){
    if(x<10 || y<10){
        return x*y;
    }
    int n = fmax(length(x),length(y));
    int half=n/2;

    long long a = x / pow(10,half);
    long long b = x % (long long)pow(10,half);
    long long c = y / pow(10,half);
    long long d = y % (long long)pow(10,half);

    long long ac = karatsuba(a,c);
    long long bd = karatsuba(b,d);

    long long ad_plus_bc = karatsuba(a+b,c+d) - ac - bd;

    return ac*pow(10,2*half) + ad_plus_bc*pow(10,2*half) + bd;
}

int main(){
    long long s,t;
    scanf("%lld %lld",&s,&t);
    printf("multiplication of the numbers is %lld",karatsuba(s,t));
}