//
// Created by 杨钧博 on 2023/12/25.
//
#include "buffer.h"

static char * __expr_strlist[EXPR_STRLIST_LEN] = {};
static int __expr_strlist_size = 0;

void ee_expr_strlist_push(char * expr_ptr) {
    if (__expr_strlist_size >= EXPR_STRLIST_LEN) {
        perror("Too many expressions.");
        return;  
    }
    __expr_strlist[__expr_strlist_size ++] = expr_ptr;
}

char * ee_expr_strlist_get(int pos) {
    if (pos >= 0 && pos < EXPR_STRLIST_LEN)
        return __expr_strlist[pos];
    return NULL;
}

int ee_expr_strlist_size() {
    return __expr_strlist_size;
}