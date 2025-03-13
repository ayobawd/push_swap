#include "push_swap.h"
#include <stdlib.h>

/* Copies all values from the stack into an array */
int *copy_stack_values(t_node *stack, int size) {
    int *arr;
    int i;
    arr = malloc(sizeof(int) * size);
    if (!arr)
        exit(EXIT_FAILURE);
    i = 0;
    while (stack) {
        arr[i] = stack->value;
        i++;
        stack = stack->next;
    }
    return arr;
}

/* Bubble sort the array using only while loops */
void bubble_sort(int *arr, int size) {
    int i = 0, j;
    while (i < size - 1) {
        j = i + 1;
        while (j < size) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

/* Walks the stack and assigns each node an index based on the sorted array */
void assign_index_to_nodes(t_node *stack, int *arr, int size) {
    while (stack) {
        int i = 0;
        while (i < size) {
            if (stack->value == arr[i]) { 
                stack->index = i; 
                break; 
            }
            i++;
        }
        stack = stack->next;
    }
}

/* Normalizes the stack by assigning indexes according to sorted order */
void assign_indexes(t_node **stack_a) {
    int size = get_size(*stack_a);
    int *arr = copy_stack_values(*stack_a, size);
    bubble_sort(arr, size);
    assign_index_to_nodes(*stack_a, arr, size);
    free(arr);
}

/* Pushes one eligible element from stack_a to stack_b using the current chunk */
void push_to_b(t_node **stack_a, t_node **stack_b, int chunk_limit, int chunk_size) {
    if ((*stack_a)->index < chunk_limit) {
        pb(stack_a, stack_b);
        if (*stack_b && (*stack_b)->index < chunk_limit - (chunk_size / 2))
            rb(stack_b);
    } else {
        ra(stack_a);
    }
}

/* Finds the maximum-index node in stack_b, rotates it to the top, and pushes it to stack_a */
void push_max_to_a(t_node **stack_a, t_node **stack_b) {
    int max_index = 0, pos = 0, max_pos = 0;
    t_node *tmp = *stack_b;
    while (tmp) {
        if (tmp->index > max_index) { 
            max_index = tmp->index; 
            max_pos = pos; 
        }
        pos++;
        tmp = tmp->next;
    }
    int size = get_size(*stack_b);
    if (max_pos <= size / 2) {
        int i = 0;
        while (i < max_pos) { rb(stack_b); i++; }
    } else {
        int i = 0, count = size - max_pos;
        while (i < count) { rrb(stack_b); i++; }
    }
    pa(stack_a, stack_b);
}

/* 
 * sort_large: sorts large sets by first normalizing the stack, then moving elements 
 * chunk by chunk from stack_a to stack_b, and finally reintegrating them in order.
 */
void sort_large(t_node **stack_a, t_node **stack_b) {
    int size = get_size(*stack_a);
    int chunk_count = (size <= 100) ? 5 : 11;
    int chunk_size = size / chunk_count;
    if (size % chunk_count)
        chunk_size++;
    int current_chunk = chunk_size;
    assign_indexes(stack_a);
    while (*stack_a) {
        push_to_b(stack_a, stack_b, current_chunk, chunk_size);
        if (get_size(*stack_b) >= current_chunk)
            current_chunk += chunk_size;
    }
    while (*stack_b)
        push_max_to_a(stack_a, stack_b);
}
