#ifndef TD_H
#define TD_H

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#include<unistd.h>

#define rcolor "\033[31m"
#define gcolor "\033[32m"
#define ycolor "\033[33m"
#define bcolor "\033[34m"
#define mcolor "\033[35m"
#define ccolor "\033[36m"
#define wcolor "\033[37m"

#define bscolor "\033[5m"
#define becolor "\033[25m"

//login structure
typedef struct login
{
        char *username;
        char *password;
        char *filename;
        struct login *next;

}TD_NODE;

//train stucture
typedef struct
{
        unsigned int date:5;
        unsigned int month:4;
        unsigned int year;

        unsigned int total_seat;
        unsigned int wait_list;
        unsigned int cur_book_seat;
        unsigned int seat_status[100];

}ST_INFRO;

typedef struct train
{
        char train_name[30];
        unsigned int train_no;
        char src_place[10];
        char dest_place[10];
        ST_INFRO seat_info[3];

        struct train *next;

}TR_NODE;

//custmor detail..
typedef struct customer
{
        char name[20];
        short int age;
        unsigned int date:5;
        unsigned int month:4;
        unsigned int year;
        unsigned int train_no;
        unsigned int seat_no;

        struct customer *next;

}CR_NODE;

//customer function
void menu2();
CR_NODE *sync_cdetail(char *,TD_NODE *);
void save_cdetail(char *,TD_NODE *,CR_NODE *);
TR_NODE *check_train_no(int ,TR_NODE *);
CR_NODE *reserve_ticket(TR_NODE *,CR_NODE *);
void booking_detail(TR_NODE *,CR_NODE *);
CR_NODE *cancel_ticket(TR_NODE *,CR_NODE *);

//train function
void train_menu(TR_NODE *);
void save_tdetail(TR_NODE *);
//TR_NODE *edit_train_detail(TR_NODE *);
TR_NODE *edit_train_detail(TR_NODE *head, unsigned int tnum);
TR_NODE *sync_tdetail();
TR_NODE* delete_train_by_number(TR_NODE *, unsigned int);
TR_NODE* delete_train(TR_NODE *head, unsigned int tnum);
TR_NODE* add_train(TR_NODE *);

//login function
void menu1();
char *getstring();
int check_password(char *);
int check_id_password(TD_NODE *,char *,char *);
TD_NODE *sync_detail(int *);
void save_detail(TD_NODE *);
void sign_in(TD_NODE *);
TD_NODE *sign_up(TD_NODE *,int *);


#endif
