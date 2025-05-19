#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "train.h"

TR_NODE* add_train(TR_NODE *head) {
    unsigned int tnum;
    char tname[50], src[30], dest[30];

    printf("Enter Train Number: ");
    scanf("%u", &tnum);

    // Check if already exists
    TR_NODE *temp = head;
    while (temp) {
        if (temp->train_no == tnum) {
            printf(rcolor"Train already present with number %u\n"wcolor, tnum);
            return head;
        }
        temp = temp->next;
    }

    TR_NODE *new_train = (TR_NODE *)malloc(sizeof(TR_NODE));
    new_train->train_no = tnum;

    printf("Enter Train Name: ");
    scanf(" %[^\n]", new_train->train_name);

    printf("Enter Source: ");
    scanf(" %[^\n]", new_train->src_place);

    printf("Enter Destination: ");
    scanf(" %[^\n]", new_train->dest_place);

    for (int i = 0; i < 3; i++) {
        printf("Enter Date (DD MM YYYY) for Schedule %d: ", i + 1);

unsigned int date, month, year;
scanf("%u %u %u", &date, &month, &year);

new_train->seat_info[i].date = date;
new_train->seat_info[i].month = month;
new_train->seat_info[i].year = year;

	printf("Enter Total Seats for this schedule: ");
        scanf("%u", &new_train->seat_info[i].total_seat);

        new_train->seat_info[i].wait_list = 0;
        new_train->seat_info[i].cur_book_seat = 0;
    }

    new_train->next = head;
    head = new_train;

    printf(gcolor"Train %u added successfully.\n"wcolor, tnum);
    return head;
}

