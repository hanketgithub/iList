//
//  list_head.h
//  list_head
//
//  Created by hank on 13/10/8.
//
//

#ifndef ___I_LIST_H___
#define ___I_LIST_H___


#define list_entry(ptr, type, member)   \
    ({const typeof(((type *) 0)->member) *__mptr = (ptr);   \
    (type *)((char *) __mptr - offsetof(type, member));     })


#define list_for_each(pos, head)        \
    for (pos = (head)->next; pos != (head); pos = pos->next)


#define list_for_each_prev(pos, head)   \
    for (pos = (head)->prev; pos != (head); pos = pos->prev)


struct list_head
{
    struct list_head *next, *prev;
};

typedef struct
{
    struct list_head list;
    int data;
} elem_t;


void INIT_LIST_HEAD(struct list_head *list);

bool list_empty(struct list_head *head);

void list_add(struct list_head *new, struct list_head *head);

void list_add_tail(struct list_head *new, struct list_head *head);

void list_del(struct list_head *list);

#endif
