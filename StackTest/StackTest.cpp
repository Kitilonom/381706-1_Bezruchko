#include "Stack.h"

#include <gtest.h>

TEST(_Stack, throw_size)
{
	ASSERT_ANY_THROW(_Stack<int> S(0));
}

TEST(_Stack, size)
{
	_Stack<int> S(2);
	ASSERT_EQ(2, S.getStackSize());
}

TEST(_Stack, push_throw)
{
	_Stack<int> S(2);
	S.push(1);
	S.push(1);
	ASSERT_ANY_THROW(S.push(2));
}

TEST(_Stack, pull)
{
	_Stack<int> S(3);
	S.push(4);
	S.push(5);
	ASSERT_EQ(5, S.pop());
}

TEST(_Stack, pop_throw)
{
	_Stack<int> S(2);
	ASSERT_ANY_THROW(S.pop());
}

TEST(_Stack, func)
{
	_Stack<int> S(2);
	ASSERT_ANY_THROW(S.Peek(4));
}