#include "Polynom.h"

#include <gtest.h>

TEST(Polynom, deg)
{
	Polynom P;
	ASSERT_EQ(0, P.GetDeg());
}

TEST(Polynom, throw_deg)
{
	double mas[] = { 0,1,2 };
	Polynom P(2, mas);
	ASSERT_ANY_THROW(P.SetKoef(42, 5));
}

TEST(Polynom, deg_koef)
{
	double mas[] = { 0,1,2 };
	Polynom P(2, mas);
	ASSERT_EQ(P.GetKoef(1), 1);
}

TEST(Polynom, sravn_no_throw)
{
	double mas[] = { 0,1,2 };
	Polynom P(2, mas);
	Polynom P1 = P;
	ASSERT_NO_THROW(P.GetKoef(1));
}

TEST(Polynom, sravn)
{
	double mas[] = { 0,1,2 };
	Polynom P(2, mas);
	Polynom P1 = P;
	ASSERT_EQ(P.GetKoef(1), P1.GetKoef(1));
}

