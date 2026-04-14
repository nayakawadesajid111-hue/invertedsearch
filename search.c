#include "inverted_Search.h"
/*Function definition for search
  
  * Function iterates with array of heads compare with each word and displays 
    file name of word present and word count.
  
    *Parameter
          1]  head -> Array of pointers to Wlist structures used as the database.
          2]  Word from user
    *Return type
           Macro -> SUCCESS or FAILURE */
int search( Wlist *head, char *word)
{

    while(head != NULL)
    {
        if(!strcmp(head->word, word))
        {
            printf("Word "COLOR_BOLD COLOR_CYAN "[ %s ] " COLOR_RESET "is present in" COLOR_BOLD COLOR_BLUE " %d " COLOR_RESET "file\\files.\n",word,head->file_count);
            Ltable*Thead = head->Tlink;
            printf(COLOR_BOLD COLOR_YELLOW "%-15s %-10s"COLOR_RESET "\n","File name","Word count");
            while(Thead != NULL)
            {
                printf("%-10s%10d\n",Thead->file_name,Thead->word_count);
                Thead = Thead->table_link;
            }
            return SUCCESS;
        }
         head = head->link;
    }
    printf("\t\t"COLOR_RED "Word not found" COLOR_RESET "\n");

}

