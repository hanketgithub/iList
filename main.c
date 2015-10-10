//
//  main.c
//  list_head
//
//  Created by hank on 13/10/8.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include "list_head.h"
#include "queue.h"

int main(int argc, const char * argv[])
{
    struct list_head head;

    INIT_LIST_HEAD(&head);

    printf("List %s\n", list_empty(&head) ? "Empty" : "Not empty");
    
    elem_t e1 = { .data = 1 };
    elem_t e2 = { .data = 2 };
    elem_t e3 = { .data = 3 };
    elem_t e4 = { .data = 4 };
    
    INIT_LIST_HEAD(&e1.list);
    INIT_LIST_HEAD(&e2.list);
    INIT_LIST_HEAD(&e3.list);
    
    printf("Add e1\n");
    list_add_tail(&e1.list, &head);
    printf("Add e2\n");
    list_add_tail(&e2.list, &head);
    printf("Add e3\n");
    list_add_tail(&e3.list, &head);
    printf("Add e4\n");
    list_add_tail(&e4.list, &head);
    
    printf("Del e2\n");
    list_del(&e2.list);
    
    struct list_head *cur;
    
    list_for_each(cur, &head)
    {
        elem_t *p_elem = list_entry(cur, elem_t, list);
        printf("%d->", p_elem->data);
    }
    printf("nil\n");
    
    while (!list_empty(&head))
    {
        elem_t *p_elem = list_entry(head.next, elem_t, list);
        
        printf("%d poped!\n", p_elem->data);
        
        list_del( &p_elem->list );
    }
    
    printf("List %s\n", list_empty(&head) ? "Empty" : "Not empty");

    return 0;
}

