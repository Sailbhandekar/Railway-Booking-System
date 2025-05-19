#include"train.h"
int check_password(char *password){
     if(strlen(password)<8){
       return 0;
     }
     int sp_flag=0,low_flag=0,upp_flag=0,num_flag=0;
     while(*password){
        if(*password>='A' && *password<='Z'){
           upp_flag=1;
        }
        else if(*password>='a' && *password<='z'){
           low_flag=1;
        }
        else if(*password>='0' && *password<='9'){
           num_flag=1;
        }
        else{
           sp_flag=1;
        }
        password++;
     }
     if(sp_flag && low_flag && upp_flag && num_flag){
       return 1;
     }
     return 0;
}
