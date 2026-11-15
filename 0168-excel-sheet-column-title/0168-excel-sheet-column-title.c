char* convertToTitle(int columnNumber) {
    char* result = malloc(20 * sizeof(char));
    int i = 0;

    while (columnNumber > 0) {
        columnNumber--;

        int remainder = columnNumber % 26;

        result[i++] = 'A' + remainder;

        columnNumber /= 26;
    }

    result[i] = '\0';

    // Reverse the string
    int left = 0;
    int right = i - 1;

    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;

        left++;
        right--;
    }

    return result;
}