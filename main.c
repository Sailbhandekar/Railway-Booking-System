#include"train.h"


void menu1(){
  puts("\n-------------------------");
  puts(rcolor"   TRAIN LOGIN SYSTEM      "wcolor);
    puts("-------------------------");
  puts(ycolor"1.Sign-In");
  puts("2.Sign-Up");
  puts("3.Quit"wcolor);
  puts("-------------------------\n");
}

int main(){

        int fn=0;
        TD_NODE *head=sync_detail(&fn);
        char choice;


        while(1)
        {
                system("clear");
                menu1();
                __fpurge(stdin);
                puts(gcolor"Enter The Choice- "wcolor);
                scanf("%c",&choice);
                switch(choice){
                   case '1':sign_in(head);
                          break;
                   case '2':head=sign_up(head,&fn);
                          break;
                    default:
                          save_detail(head);
                          puts(rcolor bscolor"-------------THANK YOU--------------"wcolor becolor);
                          exit(0);

                }

                __fpurge(stdin);
                scanf("%c",&choice);



        }
  return 0;
}
