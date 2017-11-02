/*
 * Use the union type we've defined below to write out the integer array nums
 * as if it was an array of characters;
 * Use pointer arithmethircs to iterate over the array with the ptr.
 */
#include <stdio.h>

typedef union {
    int* asInt;
    char* asChar;
} ptr;


int main(){
    int nums[] = { 1952540759, 544171040, 1685221239, 1869573152, 1768693867, 1847616875, 1700949365, 4158322};
    ptr p_nums;


    printf("asInt\n");
    for (p_nums.asInt = nums; (p_nums.asInt - nums) < sizeof(nums) / sizeof(nums[0]); p_nums.asInt++) {
        printf("%d \n", *p_nums.asInt);
    }

    printf("asChar\n");
    for (p_nums.asChar = nums; (p_nums.asChar - (char*)nums) < sizeof(nums); p_nums.asChar++) {
        printf("%c", *p_nums.asChar);
    }

    return 0;
}
