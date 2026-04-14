
#include "inverted_Search.h"

int main(int argc, char *argv[])
{
    system("clear");

    // validate CLA
    if (argc <= 1)
    {
        printf(COLOR_BOLD COLOR_RED "Enter valid argument." COLOR_RESET "\n");
        printf(COLOR_YELLOW "Usage: " COLOR_RESET);
        printf(COLOR_BLUE "./invsearch.exe file1.txt file2.txt" COLOR_RESET "\n");
        return 0;
    }

    Wlist *head[27] = {NULL};
   
    Flist *f_head = NULL;
    // file validation
    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf(COLOR_RED "No files added to file linked list" COLOR_RESET "\n");
        printf(COLOR_GREEN "Program terminated" COLOR_RESET "\n");
        return 1;
    }

    int choice = 0;

    int temp = 0;
    /*Switch case with loop */
    do
    {
        printf(COLOR_YELLOW "---------------------------------------------------------------------" COLOR_RESET "\n");
        printf(COLOR_BOLD COLOR_GREEN " %37s " COLOR_RESET "\n", "[ Main Menu ]");
        printf(COLOR_YELLOW "---------------------------------------------------------------------" COLOR_RESET "\n");

        printf(COLOR_BOLD COLOR_CYAN "1. Create Database.\n2. Display Database.\n3. Update Database.\n4. Search.\n5. Save Database.\n6. Exit." COLOR_RESET "\n");
        printf(COLOR_YELLOW "---------------------------------------------------------------------" COLOR_RESET "\n");
        printf(COLOR_YELLOW "Enter choice: " COLOR_RESET);
        scanf("%d", &choice);
        if (choice == 0)
        {
            printf(COLOR_BOLD COLOR_RED "ERROR!" COLOR_RESET COLOR_YELLOW " Enter non Intger value for choice" COLOR_RESET "\n");
            printf(COLOR_GREEN "Program terminated" COLOR_RESET "\n");
            return 0;
        }
        switch (choice)
        {
        case 1:
            /*Creating Database*/
            if (!temp)
            {
                create_database(f_head, head);
                printf(COLOR_GREEN "# INFO: Database created successfully. " COLOR_RESET "\n");

                temp = 1;
            }
            else
                printf(COLOR_BOLD COLOR_RED "# Warning " COLOR_RESET COLOR_YELLOW "Database is aready created." COLOR_RESET "\n");
            break;
        case 2:
            /*Display*/
            if (temp == 0)
            {
                printf(COLOR_BOLD COLOR_RED "Warning!" COLOR_RESET COLOR_GREEN " Database not created" COLOR_RESET "\n");
                printf(COLOR_YELLOW "Select choice '1' to create database" COLOR_RESET "\n");
            }
            else
            {
                printf(COLOR_GREEN "INFO: Displaying Database " COLOR_RESET "\n");
                printf(COLOR_YELLOW "--------------------------" COLOR_RESET COLOR_BOLD COLOR_GREEN "[ Display ]" COLOR_RESET COLOR_YELLOW "--------------------------------" COLOR_RESET "\n");
                display_database(head);
            }
            break;
        case 3:
            /*Update Database*/
            printf(COLOR_GREEN "INFO: Updating  Database " COLOR_RESET "\n");
            if (update_database(head, &f_head) == SUCCESS)
                printf(COLOR_GREEN "#INFO: Database Updated successfully " COLOR_RESET "\n");
            else
                printf(COLOR_GREEN "#INFO: Failed to update database " COLOR_RESET "\n");

            break;
        case 4:
            /*Search operation*/
            printf(COLOR_YELLOW "--------------------------" COLOR_RESET COLOR_BOLD COLOR_GREEN "[ Search ]" COLOR_RESET COLOR_YELLOW "--------------------------------" COLOR_RESET "\n");
            char search_word[WORD_SIZE];

            /*Msg to user to  enter  a word */
            printf(COLOR_BOLD COLOR_YELLOW "Enter a word: " COLOR_RESET);
            scanf("%s", search_word);
            int index = tolower(search_word[0]) % 97;
            if (!(index >= 0 && index <= 25))
                index = 26;

            printf(COLOR_YELLOW "---------------------------------------------------------------------" COLOR_RESET "\n");
            if(search(head[index], search_word) == SUCCESS)
            {
                printf(COLOR_GREEN "INFO: Search operation successful."COLOR_RESET"\n");
            }
            printf(COLOR_YELLOW "---------------------------------------------------------------------" COLOR_RESET "\n");
            break;
        case 5:
            /*Save database*/
            printf(COLOR_GREEN "INFO: Saving Database" COLOR_RESET "\n");
            save_database(head);
            break;
        case 6:
            /*Exit*/
            printf(COLOR_GREEN "Exit..." COLOR_RESET "\n");
            return 0;
            break;
        default:
            printf(COLOR_BOLD COLOR_RED "Enter Valid choice" COLOR_RESET "\n");
            break;
        }
    } while (choice != 6);
}
