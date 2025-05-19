#include"train.h"

TR_NODE *check_train_no(int train_no,TR_NODE *thead){
        while(thead){
                if(thead->train_no==train_no){
                        return thead;
                }
                thead=thead->next;
        }
        return NULL;
}

CR_NODE *reserve_ticket(TR_NODE *thead,CR_NODE *chead){

        CR_NODE *newnode=calloc(1,sizeof(CR_NODE));
        TR_NODE *tthead;

        if(newnode==NULL){
                puts(rcolor"Record Not Created"wcolor);
                return chead;
        }

ip:    printf(gcolor"Enter Train No-> "wcolor);
       scanf("%d",&newnode->train_no);

       if((tthead=check_train_no(newnode->train_no,thead))==NULL){
               puts(rcolor bscolor"Not Valid Train No"wcolor becolor);
               goto ip;
       }

       unsigned int n;
       n=0;
ip2:      __fpurge(stdin);
          printf(gcolor"Enter Train Date-> "wcolor);
          scanf("%u",&n);
          newnode->date=n;

          n=0;
          __fpurge(stdin);
          printf(gcolor"Enter Train Month-> "wcolor);
          scanf("%u",&n);
          newnode->month=n;

          n=0;
          __fpurge(stdin);
          printf(gcolor"Enter Train Year-> "wcolor);
          scanf("%u",&n);
          newnode->year=n;

          if((tthead->seat_info[0].date==newnode->date)&&(tthead->seat_info[0].month==newnode->month)&&(tthead->seat_info[0].year==newnode->year)){
                  int i=0;
                  while((i<100)&&(tthead->seat_info[0].seat_status[i]>0)){
                          i++;
                  }
                  if(i<100){
                          tthead->seat_info[0].seat_status[i]=1;
                          tthead->seat_info[0].cur_book_seat+=1;
                          newnode->seat_no=i+1;
                  }
                  else{
                          tthead->seat_info[0].wait_list+=1;
                          newnode->seat_no=0;
                          puts(rcolor"Train Seat Are Not Available"wcolor);
                          free(newnode);
                          return chead;
                  }


          }
          else if((tthead->seat_info[1].date==newnode->date)&&(tthead->seat_info[1].month==newnode->month)&&(tthead->seat_info[1].year==newnode->year)){
                  int i=0;
                  while((i<100)&&(tthead->seat_info[1].seat_status[i]>0)){
                          i++;
                  }
                  if(i<100){
                          tthead->seat_info[1].seat_status[i]=1;
                          tthead->seat_info[1].cur_book_seat+=1;
                          newnode->seat_no=i+1;
                  }
                  else{
                          tthead->seat_info[1].wait_list+=1;
                          newnode->seat_no=0;
                          puts(rcolor"Train Seat Are Not Available"wcolor);
                          free(newnode);
                          return chead;
                  }

          }
          else if((tthead->seat_info[2].date==newnode->date)&&(tthead->seat_info[2].month==newnode->month)&&(tthead->seat_info[2].year==newnode->year)){
                  int i=0;
                  while((i<100)&&(tthead->seat_info[2].seat_status[i]>0)){
                          i++;
                  }
                  if(i<100){
                          tthead->seat_info[2].seat_status[i]=1;
                          tthead->seat_info[2].cur_book_seat+=1;
                          newnode->seat_no=i+1;
                  }
                  else{
                          tthead->seat_info[2].wait_list+=1;
                          newnode->seat_no=0;
                          puts(rcolor"Train Seat Are Not Available"wcolor);
                          free(newnode);
                          return chead;
                  }

          }
          else{
                  puts(rcolor bscolor"This Date Train Not Avaliable"wcolor becolor);
                  goto ip2;
          }



          __fpurge(stdin);
          printf(gcolor"Enter Passenger Name-> "wcolor);
          fgets(newnode->name,20,stdin);
          if(newnode->name[strlen(newnode->name)-1]=='\n'){
                  newnode->name[strlen(newnode->name)-1]='\0';
          }

          printf(gcolor"Enter Passenger Age-> "wcolor);
          scanf("%hd",&newnode->age);

          if(chead==NULL){
                  chead=newnode;
          }
          else{
                  CR_NODE *temp=chead;
                  while(temp->next){
                          temp=temp->next;
                  }
                  temp->next=newnode;
          }

          return chead;

}

void booking_detail(TR_NODE *thead, CR_NODE *chead) {
    TR_NODE *var;

    if (chead == NULL) {
        puts(rcolor bscolor "Passenger Detail Not Found" wcolor becolor);
        return;
    }

    puts("\n---------------------------------------------------------------------------------------------------------------");
    printf(rcolor "%-6s %-15s %-10s %-15s %-12s %-20s %-5s %-8s\n" wcolor,
           "T.No", "Train Name", "Source", "Destination", "Date", "Name", "Age", "Seat No");
    puts("---------------------------------------------------------------------------------------------------------------");

    while (chead) {
        var = check_train_no(chead->train_no, thead);
        if (var == NULL) {
            chead = chead->next;
            continue;
        }

        printf(ccolor "%-6u %-15s %-10s %-15s %02u/%02u/%04u %-20s %-5hd %-8u\n" wcolor,
               var->train_no,
               var->train_name,
               var->src_place,
               var->dest_place,
               chead->date, chead->month, chead->year,
               chead->name,
               chead->age,
               chead->seat_no);

        chead = chead->next;
    }

    puts("---------------------------------------------------------------------------------------------------------------\n");
}

CR_NODE *cancel_ticket(TR_NODE *thead,CR_NODE *chead){

        unsigned int tr_no,date,month,year;
        char name[20];

        if(chead==NULL){
                puts(rcolor bscolor"Any Train Ticket Not Avaliable"wcolor becolor);
                return chead;

        }

        __fpurge(stdin);
        printf(gcolor"Enter Train No-> "wcolor);
        scanf("%d",&tr_no);

        __fpurge(stdin);
        printf(gcolor"Enter The Date-> "wcolor);
        scanf("%d",&date);

        __fpurge(stdin);
        printf(gcolor"Enter The month-> "wcolor);
        scanf("%d",&month);

        __fpurge(stdin);
        printf(gcolor"Enter The year-> "wcolor);
        scanf("%d",&year);

        __fpurge(stdin);
        printf(gcolor"Enter Passenger Name-> "wcolor);
        fgets(name,20,stdin);
        if(name[strlen(name)-1]=='\n'){
                name[strlen(name)-1]='\0';
        }


        TR_NODE *var=NULL;
        CR_NODE *cur_ptr=NULL,*prv_ptr=NULL,*temp=chead;

        while(temp){

                if((tr_no==temp->train_no)&&(strcmp(name,temp->name)==0)&&(temp->date==date)&&(temp->month==month)&&(temp->year==year)){

                        var=check_train_no(chead->train_no,thead);
                        if(var==NULL){
                                return chead;
                        }

                        if(var->seat_info[0].date==date){
                                var->seat_info[0].cur_book_seat-=1;
                                var->seat_info[0].seat_status[temp->seat_no-1]=0;
                                if(var->seat_info[0].wait_list>0){
                                    var->seat_info[0].wait_list-=1;
                                }
                        }
                        else if(var->seat_info[1].date==date){
                                var->seat_info[1].cur_book_seat-=1;
                                var->seat_info[1].seat_status[temp->seat_no-1]=0;
                                if(var->seat_info[1].wait_list>0){
                                    var->seat_info[1].wait_list-=1;
                                }
                        }
                        else if(var->seat_info[2].date==date){
                                var->seat_info[2].cur_book_seat-=1;
                                var->seat_info[2].seat_status[temp->seat_no-1]=0;
                                if(var->seat_info[2].wait_list>0){
                                    var->seat_info[2].wait_list-=1;
                                }
                        }

                        if(prv_ptr==NULL){
                                chead=temp->next;
                        }
                        else{
                                prv_ptr->next=temp->next;
                        }
                        free(temp);
                        return chead;
                }
                prv_ptr=temp;
                temp=temp->next;

        }
        puts(rcolor bscolor"Passenger Detail Not Found"wcolor becolor);
        return chead;


}
/*
CR_NODE *reserve_ticket(TR_NODE *thead, CR_NODE *chead) {
    CR_NODE *newnode = calloc(1, sizeof(CR_NODE));
    TR_NODE *tthead;
    int c;

    if (newnode == NULL) {
        puts(rcolor "Record Not Created" wcolor);
        return chead;
    }

ip_train_no:
    printf(gcolor "Enter Train No-> " wcolor);
    if (scanf("%u", &newnode->train_no) != 1) {
        while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
        puts(rcolor "Invalid input! Enter a valid train number." wcolor);
        goto ip_train_no;
    }

    tthead = check_train_no(newnode->train_no, thead);
    if (tthead == NULL) {
        puts(rcolor bscolor "Not Valid Train No" wcolor becolor);
        goto ip_train_no;
    }

    unsigned int d, m, y;

ip_date:
    while ((c = getchar()) != '\n' && c != EOF); // clear input buffer before input

    printf(gcolor "Enter Train Date (DD MM YYYY)-> " wcolor);
    if (scanf("%u %u %u", &d, &m, &y) != 3) {
        puts(rcolor "Invalid date input!" wcolor);
        goto ip_date;
    }
    newnode->date = d;
    newnode->month = m;
    newnode->year = y;

    // Find matching schedule index
    int schedule_index = -1;
    for (int i = 0; i < 3; i++) {
        if (tthead->seat_info[i].date == d &&
            tthead->seat_info[i].month == m &&
            tthead->seat_info[i].year == y) {
            schedule_index = i;
            break;
        }
    }

    if (schedule_index == -1) {
        puts(rcolor bscolor "This Date Train Not Available" wcolor becolor);
        goto ip_date;
    }

    // Check for seat availability
    int i = 0;
    while (i < 100 && tthead->seat_info[schedule_index].seat_status[i] > 0) {
        i++;
    }

    if (i < 100) {
        // Seat available: assign seat
        tthead->seat_info[schedule_index].seat_status[i] = 1;
        tthead->seat_info[schedule_index].cur_book_seat++;
        newnode->seat_no = i + 1;
    } else {
        // No seat available: add to waiting list
        tthead->seat_info[schedule_index].wait_list++;
        newnode->seat_no = 0; // 0 indicates waiting list
        puts(rcolor "Train Seats Are Not Available, Added to Waiting List" wcolor);
    }

    while ((c = getchar()) != '\n' && c != EOF); // clear input buffer

    printf(gcolor "Enter Passenger Name-> " wcolor);
    fgets(newnode->name, sizeof(newnode->name), stdin);
    if (newnode->name[strlen(newnode->name) - 1] == '\n') {
        newnode->name[strlen(newnode->name) - 1] = '\0';
    }

    printf(gcolor "Enter Passenger Age-> " wcolor);
    if (scanf("%hd", &newnode->age) != 1) {
        puts(rcolor "Invalid age input!" wcolor);
        free(newnode);
        return chead;
    }

    newnode->next = NULL;

    // Add to passenger list
    if (chead == NULL) {
        chead = newnode;
    } else {
        CR_NODE *temp = chead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf(gcolor "Ticket %s reserved. Seat No: %u\n" wcolor,
           newnode->seat_no ? "confirmed" : "in waiting list", newnode->seat_no);

    return chead;
}
*/
/*/ Cancel a ticket by passenger name, train no and date. Returns updated head pointer.
CR_NODE *cancel_ticket(TR_NODE *thead, CR_NODE *chead, unsigned int train_no, unsigned int date, unsigned int month, unsigned int year, const char *passenger_name) {
    if (chead == NULL) {
        puts(rcolor "No bookings found." wcolor);
        return NULL;
    }

    CR_NODE *prev = NULL;
    CR_NODE *curr = chead;
    TR_NODE *tthead = check_train_no(train_no, thead);
    if (!tthead) {
        puts(rcolor "Train not found." wcolor);
        return chead;
    }

    int schedule_index = -1;
    for (int i = 0; i < 3; i++) {
        if (tthead->seat_info[i].date == date &&
            tthead->seat_info[i].month == month &&
            tthead->seat_info[i].year == year) {
            schedule_index = i;
            break;
        }
    }
    if (schedule_index == -1) {
        puts(rcolor "Train not available on this date." wcolor);
        return chead;
    }

    while (curr != NULL) {
        if (curr->train_no == train_no && curr->date == date && curr->month == month && curr->year == year &&
            strcmp(curr->name, passenger_name) == 0) {

            // Free the seat or remove from waiting list
            if (curr->seat_no > 0) {
                // Confirmed seat: free seat and reduce cur_book_seat
                int seat_idx = curr->seat_no - 1;
                tthead->seat_info[schedule_index].seat_status[seat_idx] = 0;
                tthead->seat_info[schedule_index].cur_book_seat--;

                // Promote first waiting list passenger, if any
                if (tthead->seat_info[schedule_index].wait_list > 0) {
                    // Find first waiting list passenger for this train/date
                    CR_NODE *wait_ptr = chead;
                    while (wait_ptr != NULL) {
                        if (wait_ptr->train_no == train_no && wait_ptr->date == date &&
                            wait_ptr->month == month && wait_ptr->year == year &&
                            wait_ptr->seat_no == 0) { // waiting list passenger

                            // Assign freed seat
                            wait_ptr->seat_no = seat_idx + 1;
                            tthead->seat_info[schedule_index].seat_status[seat_idx] = 1;
                            tthead->seat_info[schedule_index].cur_book_seat++;
                            tthead->seat_info[schedule_index].wait_list--;

                            printf(gcolor "Passenger %s promoted from waiting list to seat no %d\n" wcolor, wait_ptr->name, wait_ptr->seat_no);
                            break;
                        }
                        wait_ptr = wait_ptr->next;
                    }
                }

            } else {
                // Passenger was in waiting list, just reduce wait_list count
                if (tthead->seat_info[schedule_index].wait_list > 0) {
                    tthead->seat_info[schedule_index].wait_list--;
                }
            }

            // Remove passenger node from linked list
            if (prev == NULL) {
                chead = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            puts(rcolor "Booking canceled successfully." wcolor);
            return chead;
        }
        prev = curr;
        curr = curr->next;
    }

    puts(rcolor "Passenger booking not found." wcolor);
    return chead;
}
*/
