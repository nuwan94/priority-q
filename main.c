#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "priQ.h"

/* Main function of the program */

void main()
{
    bool choice = true; // looping state boolean
    printf("============================================\n         Priority Queue Program\n============================================\n\n");

    priQ q; // declare priority queue
    createPriQueue(&q); // create queue

    while(choice)
    {
        char option = NULL, item = NULL;

        printf("   1 : Insert new item.\n   2 : Remove max.\n   3 : Show front item. \n   4 : Show rear item. \n   5 : Display Queue. \n   0 : Exit.\n\n Select Option : ");

        scanf(" %c",&option); // get instruction from user

        if(option < '0' || option > '5')
        {
            printf("\n Invalid option selected.\n\n");
            printf("============================================\n\n");
            continue;
        }

        switch(option)
        {
        case '1': // insert item to the queue
            printf("\n Enter the item : ");
            scanf(" %c",&item);
            if(item >= 'A' && item <= 'z')
            {
                insert(item,&q);
                printf(" \n-> Item added. Size of the Queue : %d\n\n", priQSize(&q));
            }
            else
            {
                printf(" \n-> Invalid data-type for the priority queue.\n\n");
            }
            break;

        case '2': // remove max item from queue
            removeMax(&item,&q);
            if(item!= NULL)
                printf(" \n-> Max item removed. Max item = %c | New Size : %d\n\n",item,priQSize(&q));
            break;

        case '3': // show the front item of queue
            if(q.front != NULL)
                printf(" \n-> Front item = %c \n\n",q.front->entry);
            else
                priQError(1);
            break;

        case '4': // show the rear item of queue
            if(q.rear != NULL)
                printf(" \n-> Rear item = %c \n\n", q.rear->entry);
            else
                priQError(1);
            break;

        case '5': // print the items in queue
            printpriQ(&q);
            break;

        case '0':
            choice = false; // exit the program.
        }
        printf("============================================\n\n");
    }
}
