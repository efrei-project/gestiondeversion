// functions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

QuoteArray * load_quotes(const char *filename) {
    QuoteArray * qArray = malloc(sizeof(QuoteArray));
    qArray->count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return qArray;
    }
    
    while (fgets(qArray->quotes[qArray->count], MAX_LENGTH, file) != NULL && qArray->count < MAX_QUOTES) {
        size_t len = strlen(qArray->quotes[qArray->count]);
        if (len > 0 && qArray->quotes[qArray->count][len-1] == '\n') {
            qArray->quotes[qArray->count][len-1] = '\0';
        }
        if (strlen(qArray->quotes[qArray->count]) > 0) {
            qArray->count++;
        }
    }
    
    fclose(file);
    return qArray;
}

void print_quote(const char *quote) {
    printf("%s\n", quote);
}

void view_quotes(const QuoteArray *quotes) {
    for (int i = 0; i < quotes->count; i++) {
        print_quote(quotes->quotes[i]);
    }
}

const char* random_quote(const QuoteArray *quotes) {
    if (quotes->count == 0) return "No quotes available";
    int index = rand() % quotes->count;
    return quotes->quotes[index];
}

void display_quotes(const QuoteArray *quotes, int count) {
    if (count >= quotes->count) {
        printf("All Quotes:\n");
        view_quotes(quotes);
    } else {
        printf("First %d Quotes:\n", count);
        for (int i = 0; i < count; i++) {
            print_quote(quotes->quotes[i]);
        }
    }
}