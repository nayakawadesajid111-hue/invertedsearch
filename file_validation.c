#include "inverted_Search.h"

/*
 * Function: file_validation
 *
 * Description:
 *   Validates a file before inserting it into the file linked list.
 *
 *   The function performs the following checks:
 *   1. Verifies that the file exists and is readable.
 *        - If the file cannot be opened, the function displays an error
 *           message and returns without further processing.
 *   2. Checks whether the file is already present in the file list.
 *         - If the file is a duplicate, it is not inserted into the list.
 *   3. Verifies that the file is not empty.
 *
 *   If all validation checks pass, the file is added to the file linked list.
 *
 * Parameters:
 *   head  - Pointer to the head of the file linked list
 *   argv  - Command-line argument vector containing file names
 *
 * Return : void
 */

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1, empty;
    while (argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if (empty == FILE_NOTAVAILABLE)
        {
            printf(COLOR_BOLD COLOR_RED "# Error!" COLOR_RESET COLOR_GREEN " File :" COLOR_RESET COLOR_BOLD COLOR_BLUE " [ %s ] " COLOR_RESET COLOR_GREEN "is not available" COLOR_RESET "\n", argv[i]);
            printf(COLOR_GREEN "# INFO: File not added" COLOR_RESET "\n");
            i++;
            continue;
        }
        else if (empty == FILE_EMPTY)
        {
            printf(COLOR_YELLOW "File :" COLOR_RESET COLOR_BOLD COLOR_BLUE " [ %s ]" COLOR_RESET COLOR_YELLOW " is empty" COLOR_RESET "\n", argv[i]);
            printf(COLOR_GREEN "# INFO: File not added" COLOR_RESET "\n");
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head, argv[i]);

            if (ret_val == SUCCESS)
            {
                printf(COLOR_GREEN "Successfully inserted the file" COLOR_RESET COLOR_BOLD COLOR_BLUE " [ %s ] " COLOR_RESET COLOR_GREEN "into file linked list..." COLOR_RESET "\n", argv[i]);
            }
            else if (ret_val == REPEATATION)
            {
                printf(COLOR_YELLOW "file " COLOR_RESET COLOR_BOLD COLOR_BLUE " [ %s ] " COLOR_RESET COLOR_YELLOW "is repeated."
                                    "\n" COLOR_RESET COLOR_BOLD COLOR_RED "Failed to add file to File Linked list..." COLOR_RESET "\n",
                       argv[i]);
            }
            else
            {
                printf(COLOR_BOLD COLOR_RED "Failure" COLOR_RESET "\n");
            }
            i++;
            continue;
        }
    }
}

// fun is to check file availability and for file contents

int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        if (errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }
    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
}
// function to check duplictes
int check_duplicate(Flist *f_head, char *name)
{
    while (f_head != NULL)
    {
        if (strcmp(f_head->file_name, name) == 0)
        {
            return REPEATATION;
        }
        f_head = f_head->link;
    }
    return SUCCESS;
}

// fun() is to create file linked list (insert_last())

int to_create_list_of_files(Flist **f_head, char *name)
{
    // checking for duplicate
    if ((*f_head != NULL) && (check_duplicate(*f_head, name) == REPEATATION))
        return REPEATATION;

    Flist *new = malloc(sizeof(Flist));

    if (new == NULL)
    {
        return FAILURE;
    }

    /*Creation Node*/
    strcpy(new->file_name, name);
    new->link = NULL;

    /*empty list*/
    if (*f_head == NULL)
    {
        *f_head = new;
        return SUCCESS;
    }

    /*List non empty*/

    Flist *temp = *f_head;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new;

    return SUCCESS;
}
