#include"train.h"
TD_NODE *sign_up(TD_NODE *head,int *fn){

        TD_NODE *temp,*newnode=NULL;
        int enter_username_cnt=1;
        int enter_password_cnt=1;


ip1:          printf(gcolor"Enter Username-> "wcolor);
              char *us=getstring();

              if(enter_username_cnt==3){
                      puts(rcolor bscolor"You Are Reached Maximum Limit Of Entering Username"wcolor becolor);
                      return head;
              }

              enter_username_cnt++;

             if(check_id_password(head,us,"\0")==1)
             {
                     free(us);
                     us=NULL;
                      puts(rcolor bscolor"Username Already Present"wcolor becolor);
                      goto ip1;
              }

ip2:
              printf(gcolor"Enter Password-> "wcolor);
              char *ps=getstring();


              if(enter_password_cnt==3){
                      puts(rcolor bscolor"You Are Reached Maximum Limit Of Entering Password"wcolor becolor);
                      return head;
              }

              enter_password_cnt++;

              if(check_password(ps)==0){
                      puts(rcolor bscolor"Please Enter Corroct Format Password"wcolor becolor);
                      goto ip2;
              }

              printf("%s\n%s\n",us,ps);

              newnode=calloc(1,sizeof(TD_NODE));
              if(newnode==NULL){
                      puts(rcolor"Node Not Created"wcolor);
                      return head;
              }


              newnode->username=calloc(strlen(us)+1,sizeof(char));
              strcpy(newnode->username,us);

              newnode->password=calloc(strlen(ps)+1,sizeof(char));
              strcpy(newnode->password,ps);


              newnode->filename=calloc(6,sizeof(char));


              (*fn)++;
              char fs[6]="file";
              fs[4]='0' +(*fn);
              fs[5]='\0';


              strcpy(newnode->filename,fs);

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

              return head;
}
