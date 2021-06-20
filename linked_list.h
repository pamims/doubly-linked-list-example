// This program is written to demonstrate the basic construction of a
// doubly-linked list data structure.
#include <stdbool.h>
#include <stdlib.h>


/* - TYPEDEFS - */

// This line allows you to specify what kind of data you want the linked list
// to contain. THIS CODE IS ONLY DESIGNED FOR NUMERIC TYPES - int, char, float,
// double, etc.
typedef int DATA_TYPE;

// Nodes are a container for the list data that includes pointers to the next
// and previous nodes in the list.
typedef struct node Node;
// List is an accessor for the nodes in the list. It contains a pointer for the
// first node in the list, the last node in the list, and a size_t that holds
// the size of the list.
typedef struct list List;


/* - FUNCTIONS - */

// Generate a pointer to the list accessor
List *make_list();
// Append a new item to the end of the list
bool list_add(List *list, DATA_TYPE value);
// Insert a new item at a particular location in the list. Index starts at 0
bool list_insert(List *list, DATA_TYPE value, size_t index);
// Remove an item from the list at a particular index location
bool list_remove(List *list, size_t index);
// Return the size of the list. Returns -1 if list doesn't exist.
int list_size(List *list);
// Retrieve the data from the particular index location of the list
DATA_TYPE list_get_value(List *list, size_t index);
// Free all allocated memory in the list. The List * needs to be set to NULL
bool destroy_list(List *list);
