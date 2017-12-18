// Queue ADT header file ... COMP9024 17s2
#include <stdbool.h>

typedef struct QueueRep *queue;


queue newQueue(void);               // set up empty queue
void  dropQueue(queue);         // remove unwanted queue
int   QueueIsEmpty(queue);      // check whether queue is empty
void  QueueEnqueue(queue, int); // insert an int at end of queue
int   QueueDequeue(queue);      // remove int from front of queue
