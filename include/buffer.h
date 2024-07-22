//
// Created by 杨钧博 on 2023/12/25.
//

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdio.h>
#include <stdlib.h>

/* Buddy */
/* 2^0 Start*/
#define BUFFER_0_0_MAX  1024
#define BUFFER_0_1_MAX  1024
#define BUFFER_0_2_MAX  1024
/* 2^0 End*/

#define ee_alloc_seq(ptr, len_ret)  \
    { ptr = malloc(sizeof(char)*BUFFER_0_0_MAX); len_ret = BUFFER_0_0_MAX; }
#define ee_alloc_type_seq(ptr, len_ret, type)  \
    { ptr = (type*)malloc(sizeof(type)*BUFFER_0_0_MAX); len_ret = BUFFER_0_0_MAX; }
#define ee_free(p)                  {free(p);p=NULL;}

#endif