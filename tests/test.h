/*
 * Copyright (c) 2020 Siddharth Chandrasekaran <siddharth@embedjournal.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _TEST_H_
#define _TEST_H_

#include <time.h>
#include <stdio.h>
#include <utils/utils.h>

#define mod_printf(fmt, ...) fprintf(stdout,"  - "fmt"\n", ## __VA_ARGS__)

#define TEST_DEF(m)          void do_test_ ## m (test_result_t *res)
#define TEST_MOD_INIT()      test_result_t _test = { 0 , 0 }
#define TEST_MOD_EXEC(f)     if (f == 0) _test.pass++; _test.total++;
#define TEST_MOD_REPORT()    res->pass = _test.pass; res->total = _test.total;
#define TEST_MOD(m)          { STR(m), do_test_ ## m }
#define TEST_MOD_SENTINEL    { NULL, NULL }

typedef struct
{
    int total;
    int pass;
} test_result_t;

typedef struct {
    const char *name;
    void (*runner)(test_result_t *result);
} test_module_t;

typedef struct {
    time_t start_time;
    time_t end_time;
    int total;
    int pass;
} test_t;

#endif
