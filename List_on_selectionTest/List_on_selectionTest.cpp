#include "List_on_selection.h"

#include <gtest.h>

TEST (List_on_selection, push)
{
	list_on_selection<int> L;
	L.add(1);
	ASSERT_EQ(1, L.getData(0));
}

TEST (List_on_selection, count)
{
	list_on_selection<int> L;
	L.add(1);
	ASSERT_EQ(1, L.getCount());
}

TEST (List_on_selection, clear)
{
	list_on_selection<int> L;
	L.add(1);
	L.clear();
	ASSERT_EQ(0, L.getCount());
}

TEST (List_on_selection, many_push)
{
	list_on_selection<int> L;
	int a = 1;
	L.add(a++);
	L.add(a++);
	L.add(a++);
	L.add(a++);
	L.add(a++);
	L.add(a++);
	L.add(a++);
	ASSERT_EQ(7, L.getCount());
}

TEST (List_on_selection, del_start)
{
	list_on_selection<int> L;
	L.add(1);
	L.add(1);
	L.add(1);
	ASSERT_NO_THROW(L.del(0));
}

TEST (List_on_selection, del_gde_to_v_seredine)
{
	list_on_selection<int> L;
	L.add(1);
	L.add(1);
	L.add(1);
	ASSERT_NO_THROW(L.del(1));
}

TEST (List_on_selection, del_end)
{
	list_on_selection<int> L;
	L.add(1);
	L.add(1);
	L.add(1);
	ASSERT_NO_THROW(L.del(2));
}

TEST(List_on_selection, del_throw)
{
	list_on_selection<int> L;
	ASSERT_ANY_THROW(L.del(1));
}