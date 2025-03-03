#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function reads the operations.log file line by line
// and counts the frequency of each operation.
void count_operations(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Counters for each operation
    int sa_count = 0, sb_count = 0, ss_count = 0;
    int pa_count = 0, pb_count = 0;
    int ra_count = 0, rb_count = 0, rr_count = 0;
    int rra_count = 0, rrb_count = 0, rrr_count = 0;
    int total = 0;

    char line[32];

    // Read each line (each operation)
    while (fgets(line, sizeof(line), fp)) {
        // Remove trailing newline, if any.
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "sa") == 0)
            sa_count++;
        else if (strcmp(line, "sb") == 0)
            sb_count++;
        else if (strcmp(line, "ss") == 0)
            ss_count++;
        else if (strcmp(line, "pa") == 0)
            pa_count++;
        else if (strcmp(line, "pb") == 0)
            pb_count++;
        else if (strcmp(line, "ra") == 0)
            ra_count++;
        else if (strcmp(line, "rb") == 0)
            rb_count++;
        else if (strcmp(line, "rr") == 0)
            rr_count++;
        else if (strcmp(line, "rra") == 0)
            rra_count++;
        else if (strcmp(line, "rrb") == 0)
            rrb_count++;
        else if (strcmp(line, "rrr") == 0)
            rrr_count++;

        total++;
    }

    fclose(fp);

    // Print the results:
    printf("Total operations: %d\n", total);
    printf("sa: %d\n", sa_count);
    printf("sb: %d\n", sb_count);
    printf("ss: %d\n", ss_count);
    printf("pa: %d\n", pa_count);
    printf("pb: %d\n", pb_count);
    printf("ra: %d\n", ra_count);
    printf("rb: %d\n", rb_count);
    printf("rr: %d\n", rr_count);
    printf("rra: %d\n", rra_count);
    printf("rrb: %d\n", rrb_count);
    printf("rrr: %d\n", rrr_count);
}

int main(void) {
    // Call the function with the log filename.
    count_operations("operations.log");
    return 0;
}
