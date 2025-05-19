#include"train.h"

CR_NODE *sync_cdetail(char *user,TD_NODE *thead){

        char filename[10];

        while(thead){
            if(strcmp(thead->username,user)==0){
                strcpy(filename,thead->filename);
                break;
            }
            thead=thead->next;
        }
        if(thead==NULL){
            return NULL;
        }

        CR_NODE var,*temp,*newnode=NULL,*head=NULL;

        int size=sizeof(CR_NODE)-sizeof(CR_NODE *);

        FILE *file=fopen(filename,"r");

        if(file==NULL){
                puts("File Not Found");
                return head;
        }

        while((fread(&var,size,1,file))>0){
                newnode=calloc(1,sizeof(CR_NODE));

                if(newnode==NULL){
                        puts("Record Not Created");
                        return head;
                }
                *newnode=var;
                newnode->next=NULL;

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
        fclose(file);
        return head;


}
