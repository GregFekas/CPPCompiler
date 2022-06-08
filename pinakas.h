#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct mylist {
    char *name;
    int key;
    struct mylist *next;
};

typedef struct mylist symbol_list;
symbol_list *head;

void le_init(void) {
    head = (symbol_list *) calloc(1,sizeof (symbol_list));
    head->key = 0;
    head->next = head;
    
}

int le_add(char* given_id, int key)
{
    symbol_list *id,*tmp;    
    
    id = (symbol_list*) calloc(1, sizeof (symbol_list));
    id->name = (char *) calloc(1,sizeof (char));

    strcpy(id->name, given_id);
    id->key = key;

    if(head->next != head)
    {
      tmp = head->next;
        id->next = tmp;
        head->next = id;
    }
     else
    {
        head->next = id;
        id->next = head;
    }

    
	
	
	
    return (id->key);

}

void le_remove(int emveleia) {

    symbol_list *run, *prev;
    prev = head;
    for (run = head->next; (run != head); run = run->next) {
        if (run->key == emveleia) {
            prev->next = run->next;
            free(run);
        }
        else
            prev = run;
    }
}

void le_wild_list_appeares(void) {

    symbol_list *temp;
    temp = head->next;
    
    while (temp != head) {
        printf("\n\nscope: %d of ID:%s ", temp->key, temp->name);
        temp = temp->next;
    }
}
