//
// Created by 杨钧博 on 2023/12/25.
//

#ifndef DATA_STRUCT_EXPEVAL_H
#define DATA_STRUCT_EXPEVAL_H

#include "token.h"
#include "operator.h"

#define EXPR_LEN_MAX    1024

struct _token_queue {
    token_t queue[EXPR_LEN_MAX];
    int head;
    int tail;
};
typedef struct _token_queue token_queue_t;

struct _token_stack {
    token_t stack[EXPR_LEN_MAX];
    int top;
};
typedef struct _token_stack token_stack_t;

const func_tbl_entry_t op_func_tbl[FUNC_TBL_SIZE];

//struct _parser_base {
//
//};
//typedef struct _parser_base parser_base_t;
//
//struct _parser {
//
//};
//typedef struct _parser parser_t;

#endif //DATA_STRUCT_EXPEVAL_H
