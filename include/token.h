//
// Created by 杨钧博 on 2023/12/25.
//

#ifndef DATA_STRUCT_TOKEN_H
#define DATA_STRUCT_TOKEN_H

enum _token_type {
    NIL = 0,
    UN_OP = 1,
    BIN_OP = 2,
    TER_OP = 4,
    OP = 7,
    DIGIT = 8,
    ALPHABET = 16,
    // according to the order of sequence 24,32,40,48,...,992
    BAD_TOKEN = 1000
};
typedef enum _token_type token_type_t;

#define OP_LEX_MAXLEN 64
struct _token {
    token_type_t token_type;
    int op_code;
    int op_prior;
    double value;
    char lexeme[OP_LEX_MAXLEN];
};
typedef struct _token token_t;

void init_op_token_tbl();
void set_token(token_t * dst, const char * lex, const int lex_len, const token_type_t token_type,
               const int code, const int prior);
void set_token_value(token_t * dst, double value);
void print_double_token(token_t * dst);
token_t * map_op_token_tbl(char * lex);

#endif //DATA_STRUCT_TOKEN_H
