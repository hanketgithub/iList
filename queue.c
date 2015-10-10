//
//  queue.c
//  list_head
//
//  Created by hank on 2013/11/28.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "list_head.h"
#include "queue.h"


void queue_init(queue_t *q)
{
    INIT_LIST_HEAD(&q->list);
}


void enqueue(queue_t *q, elem_t *e)
{
    list_add_tail(&e->list, &q->list);
}


elem_t *dequeue(queue_t *q)
{
    elem_t *p_elem = NULL;
    
    if (!list_empty(&q->list))
    {
        // fetch first element
        p_elem = list_entry(q->list.next, elem_t, list);
    
        // remove first element
        list_del(q->list.next);
    }

    return p_elem;
}
