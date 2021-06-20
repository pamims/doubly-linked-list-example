#include <stdio.h>
#include "linked_list.h"


void print_list(List *);


int main(int argc, char *argv[]) {
    List *list = make_list();
    if (!list) {
        printf("could not allocate memory for the list.\n");
        return 0;
    }

    printf("List created.\nAdding values to list.\n");

    printf("Adding 5:  %s\n", list_add(list, 5) ? "success" : "failure");
    printf("Adding 16: %s\n", list_add(list, 16) ? "success" : "failure");
    printf("Adding 21: %s\n", list_add(list, 21) ? "success" : "failure");

    printf("Inserting 8 at index 1: %s\n",
        list_insert(list, 8, 1) ? "success" : "failure");
    printf("Inserting 43 at index 4: %s\n",
        list_insert(list, 43, 4) ? "success" : "failure");
    // insert at known bad location
    printf("Inserting 19 at index 6: %s\n",
        list_insert(list, 19, 6) ? "success" : "failure");

    print_list(list);

    printf("Destroyed list? : %s\n", destroy_list(list) ? "true" : "false");
    // list memory was freed. set to NULL.
    list = NULL;

    return 0;
}


void print_list(List *list) {
    for (int i = 0; i < list_size(list); i++) {
        printf("%d ", list_get_value(list, i));
    }
    printf("\n");
}
