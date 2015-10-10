//
//  list_head.c
//  list_head
//
//  Created by hank on 13/10/8.
//
//

//#include <stdio.h>
#include <stdbool.h>

#include "list_head.h"


void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

bool list_empty(struct list_head *head)
{
    return (head->next == head) && (head->prev == head);
}

void list_add(struct list_head *new, struct list_head *head)
{
    struct list_head *tmp = head->next;
    
    head->next  = new;
    
    new->prev   = head;
    new->next   = tmp;
    
    tmp->prev   = new;
}

void list_add_tail(struct list_head *new, struct list_head *head)
{
    head->prev->next = new;
    
    new->prev = head->prev;
    new->next = head;
    
    head->prev = new;
}

void list_del(struct list_head *list)
{
    list->prev->next = list->next;
    list->next->prev = list->prev;
    
    list->prev = list;
    list->next = list;
}
