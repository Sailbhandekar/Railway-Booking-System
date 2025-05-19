#include"train.h"

void save_tdetail(TR_NODE *head){

        long size=sizeof(TR_NODE)-sizeof(TR_NODE *);

        FILE *file=fopen("train.txt","w");

        if(file==NULL){
          puts("File Not Found");
          return;
        }

        TR_NODE *temp=head;

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
