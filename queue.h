//
//  queue.h
//  list_head
//
//  Created by hank on 2013/11/28.
//
//

#ifndef list_head_queue_h
#define list_head_queue_h

typedef struct queue_tag
{
    struct list_head list;
} queue_t;

extern void queue_init(queue_t *q);

extern void enqueue(queue_t *q, elem_t *e);

extern elem_t *dequeue(queue_t *q);

#endif
