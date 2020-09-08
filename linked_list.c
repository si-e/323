#include "linked_list.h"

node *linked_list_init(){
    node *head = (node*)malloc(sizeof(node));
    head->count = 0;
    head->next = NULL;
    return head;
}

void linked_list_free(node *head){
    node *cur = head;
    node *last;
    while(cur != NULL){
        last = cur;
        cur = cur->next;
        free(last);
    }
}

char linked_list_string[0x10000];

char *linked_list_tostring(node *head){
    node *cur = head->next;
    char *position;
    int length = 0;
    while(cur != NULL){
        position = linked_list_string + length;
        length += sprintf(position, "%d", cur->value);
        cur = cur->next;
        if(cur != NULL){
            position = linked_list_string + length;
            length += sprintf(position, "->");
        }
    }
    position = linked_list_string + length;
    length += sprintf(position, "%c", '\0');
    return linked_list_string;
}

int linked_list_size(node *head){
    return head->count;
}

void linked_list_append(node *head, int val){
    node *cur = head;
    node *new_node;
    while(cur->next != NULL){
        cur = cur->next;
    }
    new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    cur->next = new_node;
    head->count++;
}

/* your implementation goes here */

/*
 * You should implement functions according to the follow function
 * declarations. One thing to note that, the parameter *index*
 * refers to the position of value node, i.e., index 0 corresponds
 * to the next node of the header node.
 *
 * In case of out-of-bound index, your code should do nothing in all
 * functions. As for remove, if the value doesn't exist, do nothing.
 *
 * For get, if index out of bound, return INT_MIN.
 * For search, if value not exists. return -1.
 * For search_all, if value not exists, return empty list.
 */

/* insert val at position index */
void linked_list_insert(node *head, int val, int index){
    node *cur = head;
    node *new_node;
    while(index-- > 0){
        if (cur->next == NULL){
            return;
        }
        cur = cur->next;
    }
    new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = cur->next;
    cur->next = new_node;
    head->count++;
}

/* delete node at position index */
void linked_list_delete(node *head, int index){
    node *cur = head;
    node *del_node;
    while(index-- > 0){
        if (cur->next == NULL){
            return;
        }
        cur = cur->next;
    }
    del_node = cur->next;
    cur->next = cur->next->next;
    free(cur->next);
    head->count--;
}

/* remove the first occurrence node of val */
void linked_list_remove(node *head, int val){
    node *cur = head;
    node *rem_node;
    while(val != cur->value){
        if (cur->next == NULL){
            return;
        }
        cur = cur->next;
    }
    rem_node = cur->next;
    cur->next = cur->next->next;
    free(cur->next);
    head->count--;
}

/* remove all occurrences of val */
void linked_list_remove_all(node *head, int val){
    int old_count;
    do{
        old_count = head->count;
        linked_list_remove(head, val);
    } while (old_count != head->count);
}

/* get value at position index */
int linked_list_get(node *head, int index){
    node *cur = head;
    while(index-- > 0){
        if (cur->next == NULL){
            return 0x80000000;
        }
        cur = cur->next;
    }
    return cur->value;
}

/* search the first index of val */
int linked_list_search(node *head, int val){
    node *cur = head;
    int index = 0;
    while(val != cur->value){
        if (cur->next == NULL){
            return -1;
        }
        cur = cur->next;
        index++;
    }
    return index;
}

/* search all indexes of val */
node *linked_list_search_all(node *head, int val){
    node *res = linked_list_init();
    node *cur = head;
    int index = 0;
    while(cur->next != NULL){
        cur = cur->next;
        if (cur->value == val){
            linked_list_append(res, index);
        }
        index++;
    }
    if (res->count == 0){
        return NULL;
    } else{   
    return res;
    }
}
