#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "priQ.h"

void main()
{
    bool choice = true;
    printf("============================================\n         Priority Queue Program\n============================================\n\n");

    priQ q;
    createPriQueue(&q);

    while(choice){
        char option=NULL,item=NULL;
        printf("   1 : Insert new item.\n   2 : Remove max.\n   3 : Display Queue. \n   0 : Exit.\n\n Select Option : ");
        scanf(" %c",&option);

        if(option <'0' || option > '4'){
            printf("\n Invalid option selected.\n");
            printf("============================================\n\n");
            continue;
        }

        switch(option){
            case '1':
                printf("\n Enter the item : ");
                scanf(" %c",&item);
                if(item >= 'A' && item <= 'z'){
                    insert(item,&q);
                    printf(" \n-> Item added. Size of the Queue : %d\n\n",priQSize(&q));
                }else{
                    printf(" \n-> Invalid data-type for the priority queue.\n");
                    break;
                }
                break;

            case '2':
                removeMax(&item,&q);
                if(item!=NULL)
                    printf(" \n-> Item removed. Max = %c | New Size : %d\n\n",item,priQSize(&q));
                break;

            case '3':
                printpriQ(&q);
                break;

            case '0':
                choice = false;
        }

        printf("============================================\n\n");
    }

}
