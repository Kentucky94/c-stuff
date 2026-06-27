#include <stdio.h>
#include <stdlib.h>

// In C, when you pass a pointer to a function, 
// it behaves exactly like passing an integer: 
// it is passed by value.The function does not get your original 
// pointer variable. It gets a brand-new, independent copy of 
// that pointer.Here is exactly how that works in memory and 
// why it affects what you can change.1. What Happens in 
// Memory (Pass by Value)Imagine main has a pointer variable 
// named first sitting at memory address 0x7FFF. 
// It holds the address 0x1000 (where your first node -5 lives).
// When you call remove_negatives_1(first), the computer creates 
// a new, temporary variable inside the function's stack frame, 
// also named first (or current).text
//
// STACK (main)                      STACK (function)
// +-------------------------+       +-------------------------+

// | Variable: first         |       | Variable: first (copy)  |
// | Address:  0x7FFF        |       | Address:  0x8FFF        |
// | Value:    0x1000  ------------> | Value:    0x1000        |
// +-------------------------+       +-------------------------+
//                \                     /
//                 \                   /
//                  v                 v
//                HEAP: [ Node: Value=-5, Next=0x1050 ] (Address: 0x1000)
// Use code with caution.Both variables point to the same heap memory (0x1000).2. What You CAN ChangeBecause both pointers point to the same heap address, you can use the copy to modify the struct's internals.If you write first->value = 99; or prev->next = next;, you are modifying the data inside the heap. main will see these changes because the heap structure itself has been altered.3. What You CANNOT Change (The Bug)When your function decides to delete the first node, you write:cfirst = next;
// Use code with caution.This only changes the value inside the function's temporary copy at 0x8FFF. It changes its value from 0x1000 to 0x1050.textSTACK (main)                      STACK (function)
// +-------------------------+       +-------------------------+

// | Variable: first         |       | Variable: first (copy)  |
// | Address:  0x7FFF        |       | Address:  0x8FFF        |
// | Value:    0x1000  (UNTOUCHED)   | Value:    0x1050  (CHANGED) |
// +-------------------------+       +-------------------------+
// Use code with caution.The pointer inside main (at 0x7FFF) never changes. It still holds 0x1000.Right after this, your code calls free(current), which destroys the node at 0x1000. When the function finishes, its temporary stack memory is erased. main is left holding 0x1000, which now points to completely corrupted, freed memory.4. How a Double Pointer (**) Fixes ThisTo allow a function to change a variable in main, you must pass the address of that variable.When you pass &first, you are passing 0x7FFF (the address of the pointer itself).cvoid remove_negatives(struct item **first_ptr) {
//     // *first_ptr means: "Go to the address stored in first_ptr and modify it"
//     *first_ptr = next; 
// }
// Use code with caution.By dereferencing the double pointer (*first_ptr), the function reaches directly back into main's stack frame and changes main's first variable to 0x1050.

struct item {
    int value;
    struct item *next;
};

struct item *create_list_from_array_recursive (const int *arr, int len) {
    if (!len) return NULL;
    struct item *tmp;
    tmp = malloc(sizeof(struct item));
    tmp->value = *arr;
    tmp->next = create_list_from_array_recursive(arr + 1, len -1);
    return tmp;
}

void iterate_items_recursive (const struct item *first) {
    if (!first) return;
    printf("node value: %i\n", first->value);
    iterate_items_recursive(first->next);
}

void free_items_recursive (struct item *first) {
    if (!first) return;
    free_items_recursive(first->next);
    free(first);
}

struct item *remove_negatives_1 (struct item *first) { // this is a copy of a pointer
    struct item *prev = NULL, *current = NULL, *next = NULL;

    current = first;

    while (current) {
        next = current->next;

        if (current->value < 0) {
            if (prev) {
                prev->next = next;
            } else { // if is first element
                // Update local copy
                first = next;
            }

            free(current);
        } else {
            prev = current;
        }

        // Return the new head
        current = next;
    }

    return first;
}

void remove_negatives_2 (struct item **first_ptr) {
    struct item *prev = NULL, *current = NULL, *next = NULL;

    // Dereference to get the actual head
    current = *first_ptr;

    while (current) {
        next = current->next;

        if (current->value < 0) {
            if (prev) {
                prev->next = next;
            } else { // if is first element
                // Update the real head pointer in main
                *first_ptr = next;
            }

            free(current);
        } else {
            prev = current;
        }

        current = next;
    }
}

void remove_negatives_3 (struct item **current_ptr) {
    while (*current_ptr) {
        if ((*current_ptr)->value < 0) {
            struct item *tmp = *current_ptr;
            // This is the magic line. 
            // Since current_ptr points to main's first, 
            // this directly updates main's first pointer 
            // to point to the next node (e.g. -32).
            *current_ptr = (*current_ptr)->next;
            free(tmp);
        } else {
            current_ptr = &(*current_ptr)->next;
        }
    }
}

int main () {
    struct item *first = NULL;
    int numbers[] = {-5, -32, 545, 2, -6};
    int len = sizeof(numbers) / sizeof(int);

    // created list and assigned values
    first = create_list_from_array_recursive(numbers, len);
    //first = remove_negatives_1(first);
    //remove_negatives_2(&first);
    remove_negatives_3(&first);

    // looking at the result
    iterate_items_recursive(first);
    free_items_recursive(first);

    return 0;
}