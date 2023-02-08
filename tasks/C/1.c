#include <stdio.h>

int len(char arr[]){
    int i ;
    for(i=0;arr[i]!='\0';i++){}
    return i;
}


int main(){
    char pass[20] = "whydoineedpassword";
    char input[20] = "";
    printf("Enter Password: ");
    scanf("%s",input);
    
    int plen = len(pass);
    int ilen = len(input);
    
    int flag = 1;
    if(plen!=ilen){
        flag = 0;
    }
    
    int limit = plen?plen<=ilen:ilen;
    for(int i = 0; i<limit;i++){
        if(pass[i]!=input[i]){
            flag = 0;
        }
    }
    
    if(flag){    
        printf("Correct Password!\n");
    }else{
        printf("Wrong Password!\n");
    }    


}
