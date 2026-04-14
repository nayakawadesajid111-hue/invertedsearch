#include "inverted_Search.h"
/*Function definition for update_database
 *Function reads newfile name from user  insert it into existing list
 * Also confirms whether file have content or not,repetation file
 * Calls create database function*/
int update_database(Wlist *head[], Flist **f_head)
{
    char filename[FNAME_SIZE];
    printf(COLOR_YELLOW "---------------------------------------------------------------------"COLOR_RESET"\n");
    printf("Enter File name : ");
    scanf("%s", filename);
    printf(COLOR_YELLOW "---------------------------------------------------------------------"COLOR_RESET"\n");
    int empty;

    empty = isFileEmpty(filename);
    if (empty == FILE_NOTAVAILABLE)
    {
        printf(COLOR_BOLD COLOR_RED "# Error!" COLOR_RESET COLOR_GREEN " File :" COLOR_RESET COLOR_BOLD COLOR_BLUE " [ %s ] " COLOR_RESET COLOR_GREEN "is not available" COLOR_RESET "\n", filename);
        printf(COLOR_GREEN "#INFO: File not added" COLOR_RESET "\n");
        return FAILURE;
    }
    else if (empty == FILE_EMPTY)
    {
        printf(COLOR_GREEN "File :" COLOR_RESET COLOR_BOLD COLOR_BLUE " [ %s ] " COLOR_RESET COLOR_GREEN "is empty" COLOR_RESET "\n", filename);
        printf(COLOR_GREEN "# INFO: File not added" COLOR_RESET "\n");
        return FAILURE;
    }
    else
    {
        int ret_val = to_create_list_of_files(f_head, filename);

        if (ret_val == SUCCESS)
        {
            printf(COLOR_GREEN "Successfully inserted the file" COLOR_RESET COLOR_BOLD COLOR_BLUE " [ %s ] " COLOR_RESET COLOR_GREEN "into file linked list..." COLOR_RESET "\n", filename);
        }
        else if (ret_val == REPEATATION)
        {
            printf(COLOR_YELLOW "file " COLOR_RESET COLOR_BOLD COLOR_BLUE " [ %s ] " COLOR_RESET COLOR_YELLOW "is repeated." "\n\t\t" COLOR_RESET COLOR_BOLD COLOR_RED "Failed to add file to File Linked list..." COLOR_RESET "\n",
                   filename);
            return FAILURE;
        }
        else
        {
            printf(COLOR_BOLD COLOR_RED "Failure" COLOR_RESET "\n");
            return FAILURE;
        }
    }
    Flist *temp = *f_head;

    while (temp)
    {
        if (!(strcmp((temp)->file_name, filename)))
        {
            create_database(temp, head);
            break;
        }
        temp = temp->link;
    }
}