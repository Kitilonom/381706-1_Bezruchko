#include "Queue.h"

#include <gtest.h>

TEST(Queue, size)
{
	ASSERT_ANY_THROW(Queue<int> Q(-1));
}

TEST(Queue, enqueue)
{
	Queue<int> Q(1);
	int a = 1;
	Q.enqueue(a);
	ASSERT_TRUE(1 == Q.dequeue());
}

TEST(Queue, getelemCT)
{
	Queue<int> Q(3);
	int a = 1;
	Q.enqueue(a);
	ASSERT_TRUE(1 == Q.getelemCT());
}

TEST(Queue, getsize)
{
	Queue<int> Q(3);
	int a = 1;
	Q.enqueue(a);
	ASSERT_TRUE(3 == Q.getsize());
}

TEST(Queue, throwsize)
{
	Queue<int> Q(3);
	int a = 1;
	Q.enqueue(a++);
	Q.enqueue(a++);
	Q.enqueue(a++);
	ASSERT_ANY_THROW(Q.enqueue(a));
}

TEST(Queue, Emptytrue)
{
	Queue<int> Q(1);
	ASSERT_TRUE(Q.IsEmpty());
}

TEST(Queue, EmptyFalse)
{
	Queue<int> Q(3);
	int a = 1;
	Q.enqueue(a);
	ASSERT_FALSE(Q.IsEmpty());
}