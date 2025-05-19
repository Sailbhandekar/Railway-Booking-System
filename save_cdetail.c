#include"train.h"

void save_cdetail(char *user,TD_NODE *thead,CR_NODE *head){

        char filename[10];

        while(thead){
            if(strcmp(thead->username,user)==0){
                strcpy(filename,thead->filename);
                break;
            }
            thead=thead->next;
        }

        if(thead==NULL){
           puts("File Name Not Found");
            return;
        }

        int size=sizeof(CR_NODE)-sizeof(CR_NODE *);

        FILE *file=fopen(filename,"w");

        if(file==NULL){
          puts("File Not Found");
          return;
        }
        CR_NODE *temp=head;

        if(temp==NULL)
        {
          fclose(file);
          return;
        }

        while(temp){
                fwrite(temp,size,1,file);
                temp=temp->next;

        }

        fclose(file);
      //  puts("Data Save In File Successfully....");
      puts(bcolor bscolor"Data Save In File Successfully...."bcolor becolor);
        return;

}
