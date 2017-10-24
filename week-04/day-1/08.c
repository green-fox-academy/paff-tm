
int main() {
    int high_number = 2;
    int low_number = 6655;

    int* high_number_pointer = &high_number;
    int* low_number_pointer = &low_number;
    //TODO:
    // Please fix the problem and swap the value of the variables,
    // without using the "high_number" and the "low_number" variables.

    // the same as 07.c

    int *p_temp = high_number_pointer;
    high_number_pointer = low_number_pointer;
    low_number_pointer = p_temp;

    printf("low number: %d, high_number: %d", *low_number_pointer, *high_number_pointer);

    return 0;
}