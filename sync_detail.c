#include"train.h"

TD_NODE *sync_detail(int *fn){
      TD_NODE *temp,*newnode=NULL,*head=NULL,var;

      FILE *fptr=fopen("passenger.txt","r");

      if(fptr==NULL){
          puts("File Not Found");
          return head;
      }
      char us[20],ps[20],fs[10];

      while(fscanf(fptr,"%s %s %s",us,ps,fs)>0){
              newnode=calloc(1,sizeof(TD_NODE));
              if(newnode==NULL){
                 puts("Node Not Created");
                 return head;
              }
              printf("%s - %s - %s \n",us,ps,fs);

              newnode->username=calloc(strlen(us)+1,sizeof(char));
              strcpy(newnode->username,us);

              newnode->password=calloc(strlen(ps)+1,sizeof(char));
              strcpy(newnode->password,ps);

              newnode->filename=calloc(strlen(fs)+1,sizeof(char));
              strcpy(newnode->filename,fs);
              *fn=fs[4]-'0';

              if(head==NULL){
                  head=newnode;
              }
              else{
                  temp=head;
                  while(temp->next){
                    temp=temp->next;
                  }
                  temp->next=newnode;
              }
              newnode=NULL;
      }
      fclose(fptr);

      return head;

}
