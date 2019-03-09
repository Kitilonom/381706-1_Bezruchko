#include "Stack_on_list.h"

#include <gtest.h>

TEST(Stack_on_list, push)
{
	Stack_on_list<int> St;
	int a = 3;
	St.Push(a);
	ASSERT_EQ(3, St.Pop());
}

TEST(Stack_on_list, size)
{
	Stack_on_list<int> St;
	ASSERT_TRUE(St.Size() == 0);
}

TEST(Stack_on_list, many_size)
{
	Stack_on_list<int> St;
	int a = 3;
	St.Push(a);
	St.Push(a);
	ASSERT_TRUE(St.Size() == 2);
}

TEST(Stack_on_list, IsEmpty)
{
	Stack_on_list<int> St;
	ASSERT_TRUE(St.IsEmpty());
}

TEST(Stack_on_list, equally_size)
{
	Stack_on_list<int> St;
	Stack_on_list<int> St1;
	int a = 3;
	St.Push(a);
	St.Push(++a);
	St.Push(++a);
	St1 = St;
	ASSERT_TRUE(St.Size() == St1.Size());
}

TEST(Stack_on_list, equally_Pop)
{
	Stack_on_list<int> St;
	Stack_on_list<int> St1;
	int a = 3;
	St.Push(a);
	St.Push(++a);
	St.Push(++a);
	St1 = St;
	ASSERT_TRUE(St.Pop() == St1.Pop());
}
