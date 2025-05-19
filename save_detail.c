#include"train.h"
void save_detail(TD_NODE *head){
      FILE *fptr=fopen("passenger.txt","w");

      if(fptr==NULL){
          puts("File Not Found");
          return;
      }

      while(head){

             fprintf(fptr,"%s %s %s\n",head->username,head->password,head->filename);
            // printf("%s %s %s\n",head->username,head->password,head->filename);
             head=head->next;
      }
      fclose(fptr);
      puts(mcolor"Data Save In File Successfully...."wcolor);

}
