/*  C FILE FOR TODO APPLICATION
 *  ===========================
 *  functions to handle files
 */

#include <stdio.h>

#include "define.h"

/*  Saves todos into FILE_NAME file
 *  If no error occurs, return 0. If the file can't be opened return -1.
 */
 int save_tasks(t_todo todos[], int num_of_todos)
{
    FILE *fp = fopen(FILE_NAME, "wb");

    if (fp == NULL) {
        return -1;
    } else {
		for (int i = 0; i < num_of_todos; i++)
		{
			fwrite(&(todos[i]), sizeof(t_todo), 1, fp);
		}
    }

    fclose(fp);
    return 0;
}

int open_tasks(t_todo todos[], int *num_of_todos)
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        return -1;
    } else {
        *num_of_todos = 0;
		while (fread(&(todos[*num_of_todos]), sizeof(t_todo), 1, fp) == 1) {
            (*num_of_todos)++;
		}
    }

    fclose(fp);
    return 0;
}
