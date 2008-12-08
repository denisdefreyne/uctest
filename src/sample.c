/*
 * test/sample.c
 * uctest
 *
 * Copyright (c) 2006 Denis Defreyne
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <uctest/uctest.h>

static void test_1_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(true);
}

static void test_2_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(true);
}

static void test_3_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(true);
}

static void test_4_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(4 == 7);
}

static void test_5_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(4 == 7);
}

static void test_6_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(true);
}

static void test_7_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(true);
}

static void test_8_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(true);
}

static void test_9_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(true);
}

static void test_10_proc(void)
{
	UC_ASSERT(true);
	UC_ASSERT(4 == 7);
}

#pragma mark -

static void run_sample_1(void)
{
	/* create suite */
	uc_suite_t *test_suite = uc_suite_create("sample 1");
	
	/* add tests to suite */
	uc_suite_add_test(test_suite, uc_test_create("sample 1",  &test_1_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 2",  &test_2_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 3",  &test_3_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 4",  &test_4_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 5",  &test_5_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 6",  &test_6_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 7",  &test_7_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 8",  &test_8_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 9",  &test_9_proc ));
	uc_suite_add_test(test_suite, uc_test_create("sample 10", &test_10_proc));
	
	/* run suite */
	uc_suite_run(test_suite);
	
	/* destroy suite */
	uc_suite_destroy(test_suite);
}

static void run_sample_2(void)
{
	/* create suite */
	uc_suite_t *test_suite = uc_suite_create("sample 2");
	
	/* add tests to suite */
	uc_suite_add_test(test_suite, uc_test_create("sample 1", &test_4_proc));
	uc_suite_add_test(test_suite, uc_test_create("sample 2", &test_9_proc));
	uc_suite_add_test(test_suite, uc_test_create("sample 3", &test_5_proc));
	uc_suite_add_test(test_suite, uc_test_create("sample 4", &test_1_proc));
	uc_suite_add_test(test_suite, uc_test_create("sample 5", &test_8_proc));
	uc_suite_add_test(test_suite, uc_test_create("sample 6", &test_2_proc));
	uc_suite_add_test(test_suite, uc_test_create("sample 7", &test_7_proc));
	uc_suite_add_test(test_suite, uc_test_create("sample 8", &test_3_proc));
	uc_suite_add_test(test_suite, uc_test_create("sample 9", &test_6_proc));
	
	/* run suite */
	uc_suite_run(test_suite);
	
	/* destroy suite */
	uc_suite_destroy(test_suite);
}

#pragma mark -

int main(void)
{
	run_sample_1();
	run_sample_2();
	
	return 0;
}
