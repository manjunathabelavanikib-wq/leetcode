char* countAndSay(int n) {
    char* current = malloc(5000);
    char* next = malloc(5000);

    strcpy(current, "1");

    for (int i = 1; i < n; i++) {
        int j = 0;
        int k = 0;

        while (current[j] != '\0') {
            int count = 1;

            // Count consecutive identical digits
            while (current[j] == current[j + 1]) {
                count++;
                j++;
            }

            // Add count
            k += sprintf(next + k, "%d", count);

            // Add digit
            next[k++] = current[j];

            j++;
        }

        next[k] = '\0';

        strcpy(current, next);
    }

    free(next);

    return current;
}