// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#include <windows.h>

void menu() {
    printf("\n==== Programming Quotes ====\n");
    printf("1. Random quote\n");
    printf("2. All quotes\n");
    printf("3. Add quote\n");
    printf("4. Exit\n");
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(NULL));
    int choice;
    
    while (1) {
        QuoteArray * quotes = load_quotes("quotes.txt");
        menu();
        
        printf("Choose an action (1-3): ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer
        
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

