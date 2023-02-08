//Print series of non fibo numbers upto n
#include <stdio.h>

int fib(int n){
    if (n<=0){
        return 0;
    }else if (n==1){
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
 
 
int is_fib(int n, int  fibs[], int no){

    if(n<=3) // code fails for n = 2, 3 so this prevents it 
        no = no+2;
    
    for(int a = 0;a<=no;a++){
        if(n==fibs[a])
            return 1;
        
    }
    return 0;
    
}
int main()
{
    int no;
    printf("Enter the limit: ");
    scanf("%d",&no);
    
    int fibs[no] ;
    
    
    int new_no  = no+2; // code fails for n = 2, 3 so this prevents it 
    for(int i = 0;i<=new_no;i++){
        int x = fib(i);
        if(x>no)
            break;
       fibs[i] = fib(i);
       
       
    }
    printf("Non Fibonacci numbers: ");
    for(int i = 0;i<=no;i++){
        if(!is_fib(i, fibs, no))
            printf("%d ",i);
        }
    
   
    return 0;
}
