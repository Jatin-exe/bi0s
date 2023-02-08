//Print series of first n fibo numbers
#include <stdio.h>
int fib(int n)
{
    if (n<=0){
        return 0;
    }else if (n==1){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
 
int main()
{
    int no;
    scanf("%d",&no);
    
    for(int i = 0;i<=no;i++){
    
        printf("%d ", fib(i));
    }
   
    return 0;
}
