#include <stdlib.h>
#include <stdio.h>

struct item {
    int value;
    struct item *next;
};

struct item *create_list_from_array (const int *arr, int len) {
    struct item *first = NULL, *last = NULL, *tmp;
    int i;
    
    for (i = 0; i < len; i++) {
        tmp = malloc(sizeof(struct item));
        tmp->value = arr[i];
        tmp->next = NULL;

        if (last) {
            last->next = tmp;
            last = tmp;    
        } else {
            first = last = tmp;
        }
    }

    return first;
}

struct item *create_list_from_array_backwards (const int *arr, int len) {
    int i;
    struct item *first = NULL, *tmp;

    for (i = len - 1; i >= 0; i--) {
        tmp = malloc(sizeof(struct item));
        tmp->value = arr[i];
        tmp->next = first;
        first = tmp;
    }

    return first;
}

struct item *create_list_from_array_recursive (const int *arr, int len) {
    if (!len) return NULL;
    struct item *tmp;
    tmp = malloc(sizeof(struct item));
    tmp->value = *arr;
    tmp->next = create_list_from_array_recursive(arr + 1, len -1);
    return tmp;
}

void iterate_items (struct item *first) {
    struct item *current = first;

    while (current != NULL) {
        printf("node value: %i\n", current->value);
        current = current->next;
    }
}

void iterate_items_2 (struct item *first) {
    struct item *tmp;

    for (tmp = first; tmp; tmp = tmp->next) {
        printf("node value: %i\n", tmp->value);
    }
}

void iterate_items_3 (const struct item *first) {
    for (; first; first = first->next) {
        printf("node value: %i\n", first->value);
    }
}

void iterate_items_recursive (const struct item *first) {
    if (!first) return;
    printf("node value: %i\n", first->value);
    iterate_items_recursive(first->next);
}

int calculate_sum_recursive (const struct item *first) {
    if (!first) return 0;
    return first->value + calculate_sum_recursive(first->next);
}

int calculate_sum_recursive_2 (const struct item *first) {
    return first ? first->value + calculate_sum_recursive(first->next) : 0;
}

void free_items (struct item *first) {
    struct item *current = first;
    struct item *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_items_2 (struct item *first) {
    while (first) {
        struct item *tmp = first;
        first = tmp->next;
        free(tmp);
    }
}

void free_items_3 (struct item *first) {
    while (first) {
        struct item *tmp = first->next;
        free(first);
        first = tmp;
    }
}

void free_items_recursive (struct item *first) {
    if (!first) return;
    free_items_recursive(first->next);
    free(first);
}

// void remove_negatives (struct item *current) {
//     struct item *prev = NULL, *next = NULL;

//     for (; current; current = next) {
//         next = current->next;

//         if (current->value < 0) {
//             // move pointers
//             if (prev) {
//                 prev->next = next;
//             }

//             // free current
//             free(current);
//         } else {
//             prev = current;
//         }
//     }
// }

int main () {
    struct item *first_in_list;
    int numbers[] = {5, 32, 545, 2, 6};
    int len = sizeof(numbers) / sizeof(int);
    int sum;

    first_in_list = create_list_from_array_recursive(numbers, len);
    iterate_items_recursive(first_in_list);
    sum = calculate_sum_recursive_2(first_in_list);

    printf("Sum equals %i\n", sum);

    free_items_recursive(first_in_list);

    return 0;
}