#include"train.h"

void menu2(){
      puts("\n-----------------------------");
        puts(rcolor" TRAIN SYSTEM FACILITIES"wcolor);
        puts("-----------------------------");
        puts(ycolor"R/r: To Reserve Ticket");
        puts("C/c: To Cancel Ticket");
        puts("B/b: Booking Detail");
        puts("Q/q: Quit"wcolor);
        puts("-----------------------------\n");
}

void train_menu(TR_NODE *thead) {
    while (thead) {
        fflush(stdout);
        puts("\n---------------------------------------------------------------------------------------------");
        puts(rcolor "T.No   Train Name       Source     Destination" wcolor);
        printf(ccolor "%-6u %-17s %-10s %-15s\n" wcolor,
               thead->train_no,
               thead->train_name,
               thead->src_place,
               thead->dest_place);
        puts("---------------------------------------------------------------------------------------------");
        puts(rcolor "Date        Total Seat   Waiting List   Current Booked" wcolor);

        for (int i = 0; i < 3; i++) {
            printf(ccolor "%02u/%02u/%04u   %-11u   %-13u   %-14u\n" wcolor,
                   thead->seat_info[i].date,
                   thead->seat_info[i].month,
                   thead->seat_info[i].year,
                   thead->seat_info[i].total_seat,
                   thead->seat_info[i].wait_list,
                   thead->seat_info[i].cur_book_seat);
        }

        puts("---------------------------------------------------------------------------------------------\n");
        thead = thead->next;
    }
}

void sign_in(TD_NODE *head){

        TD_NODE *temp;
        int enter_username_cnt=1;

ip1:          printf(gcolor"Enter Username- "wcolor);
              char *us=getstring();

              printf(gcolor"Enter Password- "wcolor);
              char *ps=getstring();

              if(enter_username_cnt==3){
                      puts(rcolor bscolor"You Are Reached Maximum Limit Of Entering Username"wcolor becolor);
                      return;
              }

              enter_username_cnt++;

              if(check_id_password(head,us,ps)!=2){
                      puts(rcolor bscolor"Incorrect Username Password"wcolor becolor);
                      goto ip1;
              }

              TR_NODE *thead=sync_tdetail();

	      if((strcmp(us,"admin")==0)&&(strcmp(ps,"Admin@123")==0)){
 		   char admin_choice;
   		    while (1) {
       	 		system("clear");
        		train_menu(thead);

        		puts(rcolor"\nADMIN OPTIONS"wcolor);
        		puts(ycolor"A/a: Add Train");
        		puts(ycolor"E/e: Edit Train Details");
        		puts("D/d: Delete Train");
        		puts("Q/q: Quit Admin Menu\n"wcolor);

        		printf(gcolor"Enter Choice: "wcolor);
        		__fpurge(stdin);
        		scanf("%c", &admin_choice);

        		switch (admin_choice) {
    				case 'A':case 'a':thead = add_train(thead);
        				save_tdetail(thead);
        				break;
    				case 'E':case 'e': {
    					unsigned int tnum;
        				printf("Enter Train Number to Edit: ");
        				scanf("%u", &tnum);
        				thead = edit_train_detail(thead, tnum);
				        save_tdetail(thead);
				        break;
    					}
			    	case 'D':case 'd': {
       	 				unsigned int tnum;
        				printf("Enter Train Number to Delete: ");
        				scanf("%u", &tnum);
        				thead = delete_train(thead, tnum);
        				save_tdetail(thead);
        				break;
    					}
    				case 'Q':case 'q':save_tdetail(thead);
        				return;
   				 default:puts(rcolor"Invalid Choice"wcolor);
			}
		    }
	      }


              char choice;

              CR_NODE *chead=sync_cdetail(us,head);

              while(1){
                system("clear");
                      train_menu(thead);
                      menu2();

                      __fpurge(stdin);
                      puts(gcolor"Enter The Choice- "wcolor);
                      scanf("%c",&choice);

                      switch(choice){
                              case 'R':
                              case 'r':chead=reserve_ticket(thead,chead);
                                      break;
                              case 'C':
                              case 'c':chead=cancel_ticket(thead,chead);
                                      break;
                              case 'B':
                              case 'b':booking_detail(thead,chead);
                                      break;
                              default:
                                      save_tdetail(thead);
                                      save_cdetail(us,head,chead);
                                      puts(mcolor"THANK YOU"wcolor);
                                      return;

                      }
                      __fpurge(stdin);
                      scanf("%c",&choice);

              }

              return;

}
