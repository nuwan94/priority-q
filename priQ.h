#include<stdlib.h>
#include<stdbool.h>

typedef char pqEntry;

typedef struct pqNode {
    pqEntry entry;
    struct pqNode *next;
}pQnode;

typedef struct {
    int count;
    bool full;
    struct pqNode *front;
    struct pqNode *rear;
}priQ;

void createPriQueue(priQ *q){
    q->count = 0;
    q->full = false;
    q->front = q->rear = NULL;
}

bool isPriQueueEmpty(const priQ *q){
    return (q->front == NULL && q->rear ==NULL);
}

bool isPriQueueFull(const priQ *q){
    return (q->full);
}

void insert(pqEntry x, priQ *q){
    pQnode *np;
    np = (pQnode *)malloc(sizeof(pQnode));
        if (np ==NULL){
            printf(" PQ001 : Not enough memory");
            q->full = true;
        }else{
            np->entry = x;
            np->next = NULL;

            if (isPriQueueEmpty(q))
                q->front = q->rear = np;
            else{
                    q->rear->next = np;
                    q->rear =np;
            }
        q->count++;
        }
}

void removeMax(pqEntry *x,priQ *q){
    pQnode *maxN,*current,*prevMaxN;
    if (isPriQueueEmpty(q))
        printf(" PQ002 : Cannot remove from empty queue.\n");
    else{
        if(q->front->next != NULL){
            prevMaxN = NULL;
            current = maxN = q->front;
            while(current->next!=NULL){
                if(current->next->entry > maxN->entry){
                    maxN = current->next;
                    prevMaxN = current;
                }
                current = current->next;
            }
            if(prevMaxN!=NULL){
                prevMaxN->next = maxN->next;
            }else {
                if(maxN->next==NULL)
                    q->rear = prevMaxN;
                q->front = maxN->next;
            }
            *x = maxN->entry;
        }else{
            maxN = q->front;
            *x = maxN->entry;
            q->front = q->rear = NULL;
        }
        q->count--;
        free(maxN);
    }
}

void serve(pqEntry *x, priQ *q){
    pQnode *np;

    if (isPriQueueEmpty(q))
        printf(" PQ002 : Cannot remove from empty queue.\n");
    else{
        q->count--;
        *x = q->front->entry;
        np = q->front;
        q->front = q->front->next;

        if (q->front == NULL)
            q->rear = NULL;
    }
    free(np);
}

int priQSize(const priQ *q){
    return (q->count);
}

void printpriQ(const priQ *q){
    if(!isPriQueueEmpty(q)){
        printf("\n============================================\n ");
        pQnode temp;
        temp = *q->front;
        while(temp.entry){
            printf("%c ",temp.entry);
            if(temp.next!=NULL)
                temp = *temp.next;
            else
                break;
        }
        printf("\t| Size : %d\n",priQSize(q));
    }else{
        printf("\n PQ003 : Cannot display empty queue.\n\n");
    }

}
