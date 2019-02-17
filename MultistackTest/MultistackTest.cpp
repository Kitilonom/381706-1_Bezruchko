#include "Multistack.h"

#include <gtest.h>

TEST(Multistack, throw_n)
{
	ASSERT_ANY_THROW(Multistack<int> M(-1, 10));
}


TEST(Multistack, throw_size)
{
	ASSERT_ANY_THROW(Multistack<int> M(1,0 -1));
}

TEST(Multistack, getsize)
{
	Multistack<int> M(10, 15);
	ASSERT_EQ(M.getsize(), 15);
}

TEST(Multistack, getn)
{
	Multistack<int> M(10, 15);
	ASSERT_EQ(M.getn(), 10);
}
