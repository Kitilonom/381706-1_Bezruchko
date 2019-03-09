#include "List_on_array.h"
#include <iostream>
using namespace std;
#include <gtest.h>

TEST(List_on_array, size)
{
	ASSERT_ANY_THROW(List_on_array<int> L(-1));
}

TEST(List_on_array, nothrow_pushend)
{
	List_on_array<int> L(1);
	ASSERT_NO_THROW(L.pushEnd(1));
}

TEST(List_on_array, nothrow_pullend)
{
	List_on_array<int> L(1);
	L.pushEnd(1);
	ASSERT_NO_THROW(L.pullEnd());
}

TEST(List_on_array, pullEnd)
{
	List_on_array<int> L(1);
	int a = 1;
	L.pushEnd(a);
	ASSERT_EQ (a, L.pullEnd());
}

TEST(List_on_array, nothrow_pushstart)
{
	List_on_array<int> L(1);
	ASSERT_NO_THROW(L.pushStart(1));
}

TEST(List_on_array, nothrow_pullstart)
{
	List_on_array<int> L(1);
	L.pushEnd(1);
	ASSERT_NO_THROW(L.pullStart());
}

TEST(List_on_array, pullstart)
{
	List_on_array<int> L(1);
	int a = 1;
	L.pushEnd(a);
	ASSERT_EQ (a, L.pullStart());
}



