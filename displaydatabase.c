#include "inverted_Search.h"
/*Function defintion for display database
  Function prints all database 
  Parameter: Head ->head -> Array of pointers to Wlist structures used as the database.
  Return type : Void
 */
void display_database(Wlist *head[])
{
  int index = 0;
  printf(COLOR_YELLOW "---------------------------------------------------------------------" COLOR_RESET "\n");
  printf(COLOR_BOLD COLOR_YELLOW "%-10s %-9s %-10s %15s %15s" COLOR_RESET "\n", "Index", "Word", "File count", "File name", "Word Count");
  for (int i = 0; i < 27; i++)
  {
    if (head[i] != NULL)
    {
      //prints all details index by index
       print_word_count(head[i]);
    }
  }
  printf(COLOR_YELLOW "---------------------------------------------------------------------" COLOR_RESET "\n");
}

/*Function definition for print_word_count
 *Functions iterates list and prints the Deatails*/
int print_word_count(Wlist *head)
{
  int count;
  while (head != NULL)
  {
    int index = tolower(head->word[0]) % 97;
    if (!(index >= 0 && index <= 25))
      index = 26;
    printf(COLOR_YELLOW "---------------------------------------------------------------------" COLOR_RESET "\n");
    printf("%-10d %-15s %-10d ", index, head->word, head->file_count);
    Ltable *Thead = head->Tlink;
    count = 0;
    while (Thead != NULL)
    {

      if (count >= 1)
      {
        printf("\n%47s %10d", Thead->file_name, Thead->word_count);
        count = 0;
      }
      else if (count == 0)
        printf("%-18s %-5d", Thead->file_name, Thead->word_count);
      Thead = Thead->table_link;
      count++;
    }
    printf("\n");
    head = head->link;
  }
}