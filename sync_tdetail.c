#include"train.h"
TR_NODE *sync_tdetail(){

        TR_NODE var,*temp,*newnode=NULL,*head=NULL;

        int size=sizeof(TR_NODE)-sizeof(TR_NODE *);

        FILE *file=fopen("train.txt","r");

        if(file==NULL){
                puts("File Not Found");
                return head;
        }

        while((fread(&var,size,1,file))>0){
                newnode=calloc(1,sizeof(TR_NODE));

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
