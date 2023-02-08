//Without using string.h


#include <stdio.h>

int len(char arr[]){
    int i ;
    for(i=0;arr[i]!='\0';i++){}
    return i;
}


int main(){
    printf("Enter a string:");
    char input[100] = "";
    
    scanf("%s",input);
    
    printf("Integers: ");
    for(int i = 0;input[i]!='\0';i++){
        int x = input[i];
        if(x>=48 && x<=57){
            if(input[i+1]=='\0'){    
                printf("%c",input[i]);
            } else{
                printf("%c, ",input[i]);
            }    
        }
    }
    return 0;
}
