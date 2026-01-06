// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#include <windows.h>

void menu() {
    printf("\n==== Programming Quotes ====\n");
    printf("random  : Random quote\n");
    printf("display : Display quotes\n");
    printf("add     : Add a new quote\n");
    printf("exit    : Exit the program\n");
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(NULL));
    char choice[20];
    
    while (1) {
        QuoteArray *quotes = load_quotes("quotes.txt");
        menu();
        
        printf(">> ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';
        
        if (strcmp(choice, "random") == 0) {
            print_quote(random_quote(quotes));
        } else if (strcmp(choice, "display") == 0) {
            char count_str[10];
            printf("Enter the number of quotes to display: ");
            fgets(count_str, sizeof(count_str), stdin);
            int count = atoi(count_str);
            display_quotes(quotes, count);
        } else if (strcmp(choice, "add") == 0) {
            add_quote("quotes.txt", quotes);
        } else if (strcmp(choice, "exit") == 0) {
            printf("Good bye...\n");
            free(quotes);
            break;
        } else {
            printf("Invalid input\n");
        switch (choice) {
            case 1:
                print_quote(random_quote(quotes));
                break;
            case 2:
                view_quotes(quotes);
                break;
            case 3:
                add_quote("quotes.txt", quotes);
                return 0;
            case 4:
                printf("Good bye...\n");
                free(quotes);
            default:
                printf("Invalid choice\n");
        }
        free(quotes);
    }
    
    return 0;
}