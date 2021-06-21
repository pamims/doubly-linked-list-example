# doubly-linked-list-example
Example code for a doubly linked list written in C.

The DATA_TYPE found in the linked_list.h file can safely be redefined as any
numeric type such as char, int, float, double, etc.

The example code in main.c only exists to show off functionality. Feel free to
let me know about any issues with the code.

The biggest flaw that I am aware of is in the list_get_value() function. If you
supply the function with a null pointer or an invalid index, the function will
return 0 instead of producing an error.
