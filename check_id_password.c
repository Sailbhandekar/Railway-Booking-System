#include"train.h"
int check_id_password(TD_NODE *head,char *username,char *password){

        while(head){

           if((strcmp(head->username,username)==0)&&(strcmp(head->password,password)==0)){
                           return 2;
           }
           else if(strcmp(head->username,username)==0){
                           return 1;
           }
           head=head->next;
        }
        return 0;

}
