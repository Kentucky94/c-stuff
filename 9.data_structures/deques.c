#include <stdlib.h>
#include <stdio.h>

struct deque_item {
    double value;
    struct deque_item *prev, *next;
};

struct deque {
    struct deque_item *first, *last;
};

struct deque *create_deque_from_array ( const double arr[], int size ) {
    int i;
    struct deque *result;
    struct deque_item *tmp, *first = NULL, *last = NULL;

    for (i = 0; i < size; i++) {
        tmp = malloc(sizeof(struct deque_item));
        tmp->value = arr[i];
        tmp->prev = NULL;
        tmp->next = NULL;

        if (!first) {
            first = tmp;
        } else {
            last->next = tmp;
            tmp->prev = last;
        }

        last = tmp;
    }

    result = malloc(sizeof(struct deque));
    result->first = first;
    result->last = last;

    return result;
}

void push_first_to_deque (struct deque *deque, double x) {
    struct deque_item *tmp, *first = deque->first;

    tmp = malloc(sizeof(struct deque_item));
    tmp->value = x;
    tmp->prev = NULL;
    tmp->next = first;

    if (first) {
        first->prev = tmp;
    } else {
        deque->last = tmp;
    }

    deque->first = tmp;
}

void push_last_to_deque (struct deque *deque, double x) {
    struct deque_item *tmp, *last = deque->last;

    tmp = malloc(sizeof(struct deque_item));
    tmp->value = x;
    tmp->prev = last;
    tmp->next = NULL;

    if (last) {
        last->next = tmp;
    } else {
        deque->first = tmp;
    }

    deque->last = tmp;
}

void iterate_deque (const struct deque_item *first) {
    if (!first) return;
    printf("Value: %f\n", first->value);
    iterate_deque(first->next);
}

void iterate_deque_backwards (const struct deque_item *last) {
    if (!last) return;
    printf("Value: %f\n", last->value);
    iterate_deque_backwards(last->prev);
}

void free_deque (struct deque_item *first) {
    if (!first) return;
    free_deque(first->next);
    free(first);
}

int main() {
    struct deque *deque;
    double arr[] = { 12.5, 7.8, 5.3, 11.0, 4.1 };
    int size = sizeof(arr) / sizeof(double);
    
    deque = create_deque_from_array(arr, size);
    push_first_to_deque(deque, 32.34);
    push_last_to_deque(deque, 4.36);

    printf("Iterating forward\n");
    iterate_deque(deque->first);
    printf("Iterating backwards\n");
    iterate_deque_backwards(deque->last);

    free_deque(deque->first);
    free(deque);

    return 0;
}