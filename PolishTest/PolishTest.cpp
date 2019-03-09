#include "Polish.h"

#include <gtest.h>

TEST(Polish, isOk_true)
{
	Polish P;
	ASSERT_TRUE(P._isOK());
}