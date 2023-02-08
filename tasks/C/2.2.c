#Using the csting library

#include <stdio.h>
#include <cstring>



int main(){
    printf("Enter a string:");
    char input[200] = "";
    
    scanf("%s",input);
    
    printf("Integers: ");
    for(int i = 0;i<strlen(input);i++){
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
