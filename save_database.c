#include "inverted_Search.h"
/*Function definition save database function
 * Functions iterates array of head structure writes in file stream
 * Return type  - int
 * Parameter - head -> Array of pointers to Wlist structures used as the database.
 */

int save_database(Wlist *head[])
{
    char savedata_filename[FNAME_SIZE];
    printf(COLOR_YELLOW "---------------------------------------------------------------------"COLOR_RESET"\n");
    printf("Enter file name for saving data: ");
    scanf("%s", savedata_filename);
    printf(COLOR_YELLOW "---------------------------------------------------------------------"COLOR_RESET"\n");
    if(strchr(savedata_filename,'.') == NULL)
    {
        printf(COLOR_RED "Error!" COLOR_RESET COLOR_YELLOW" File name must contain extention"COLOR_RESET"\n");
        return FAILURE;
    }
   
    FILE *fptr = fopen(savedata_filename, "w");
    fprintf(fptr, "---------------------------------------------------------------------\n");
    fprintf(fptr, "%-10s %-9s %-10s %15s %15s\n", "Index", "Word", "File count", "File name", "Word Count");

    int count;
    for (int i = 0; i < 27; i++)
    {
        while (head[i] != NULL)
        {
            int index = tolower(head[i]->word[0]) % 97;
            if (!(index >= 0 && index <= 25))
                index = 26;
            fprintf(fptr, "--------------------------------------------------------------------- \n");
            fprintf(fptr, "%-10d %-15s %-10d ", index, head[i]->word, head[i]->file_count);
            Ltable *Thead = head[i]->Tlink;
            count = 0;
            while (Thead != NULL)
            {

                if (count >= 1)
                {
                    fprintf(fptr, "\n%47s %10d", Thead->file_name, Thead->word_count);
                    count = 0;
                }
                else if (count == 0)
                    fprintf(fptr, "%-18s %-5d", Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
                count++;
            }
            fprintf(fptr, "\n");
            head[i] = head[i]->link;
        }
    }
     fprintf(fptr, "--------------------------------------------------------------------- \n");
    printf(COLOR_GREEN "# INFO: Database saved to " COLOR_RESET COLOR_BLUE "[  %s  ]" COLOR_RESET "\n", savedata_filename);
    fclose(fptr);
}