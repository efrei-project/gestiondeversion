// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_QUOTES 100
#define MAX_LENGTH 256

typedef struct {
    char quotes[MAX_QUOTES][MAX_LENGTH];
    int count;
} QuoteArray;

QuoteArray* load_quotes(const char *filename);
void print_quote(const char *quote);
void view_quotes(const QuoteArray *quotes);
const char* random_quote(const QuoteArray *quotes);
void add_quote(const char *filename, QuoteArray *quotes);


#endif

