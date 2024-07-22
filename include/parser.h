//
// Created by 杨钧博 on 2023/12/25.
//

#ifndef DATA_STRUCT_EXPEVAL_H
#define DATA_STRUCT_EXPEVAL_H

#include "token.h"
//#include "operator.h"

#define EXPR_LEN_MAX    1024

struct _token_queue {
    token_t *queue;
    int buflen;
    int head;
    int tail;
};
typedef struct _token_queue token_queue_t;

struct _token_stack {
    token_t *stack;
    int buflen;
    int top;
};
typedef struct _token_stack token_stack_t;

struct _expr_t {
    char *seq;
    int buflen;
    int slen;
    int pos;
};
typedef struct _expr_t expr_t;

int ee_init_parser();
int ee_parser_setexpr(const char * src);
char * ee_parser_expr_seq();
void ee_uninit_parser();
void ee_parser_stdin();
void ee_parser_reset();
void calc();

#endif //DATA_STRUCT_EXPEVAL_H
