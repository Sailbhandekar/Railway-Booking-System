#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "train.h"

TR_NODE* delete_train(TR_NODE *head, unsigned int tnum) {
    TR_NODE *curr = head;
    TR_NODE *prev = NULL;

    while (curr) {
        if (curr->train_no == tnum) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr); // Free the train node
            printf(gcolor"Train %u deleted successfully.\n"wcolor, tnum);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    printf(rcolor"Train number %u not found.\n"wcolor, tnum);
    sleep(2);
    return head;
}

