//
// Created by 杨钧博 on 2023/12/25.
//
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_token(token_t * dst, const char * lex, const int lex_len, const token_type_t token_type,
               const int code, const int prior) {
    memset(dst, 0, sizeof(token_t));
    strncpy(dst->lexeme, lex, lex_len);
    dst->lexeme[lex_len] = '\0';
    dst->op_code = code;
    dst->op_prior = prior;
    dst->token_type = token_type;
    if (token_type == DIGIT) {
        dst->value = strtod(dst->lexeme, NULL);
    }
}

void set_token_value(token_t * dst, double value) {
    memset(dst, 0, sizeof(token_t));
    dst->token_type = DIGIT;
    dst->value = value;
    sprintf(dst->lexeme, "%f", value);
}

void print_double_token(token_t * dst) {
    if (dst->token_type != DIGIT)
        return;

    char *dec_point = strchr(dst->lexeme, '.');
    if (dec_point == NULL) {
        printf("%s\n", dst->lexeme);
        return;
    }

    int dec_digits = strlen(dec_point + 1);
    char *end = dst->lexeme + strlen(dst->lexeme) - 1;
    while (end > dec_point && *end == '0') {
        *end = '\0';
        end--;
    }
    if (end == dec_point) {
        *dec_point = '\0';
    }
    printf("%s\n", dst->lexeme);
}