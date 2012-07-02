#include <gtest/gtest.h>

#include "action/coulomb/CoulombLinkAction.h"

namespace {

class CoulombLinkActionTest: public testing::Test {
protected:
	CoulombLinkAction* action;
	double q1q2;
	double epsilon;
	double deltaTau;
	double mu;

	virtual void SetUp() {
		q1q2 = -1.0;
		epsilon = 12.0;
		deltaTau = 0.1;
		mu = 1.0;
		action = new CoulombLinkAction(q1q2, epsilon, mu, deltaTau);
	}

	virtual void TearDown() {
		delete action;
	}

};

TEST_F(CoulombLinkActionTest, testAverageSeparation) {
	CoulombLinkAction::Vec delta1 = 0.0;
	delta1(0) = 2.0;
	CoulombLinkAction::Vec delta2 = 0.0;
	delta2(0) = 6.0;
	double value =
			CoulombLinkAction::calculateAverageSeparation(delta1, delta2);
	ASSERT_DOUBLE_EQ(4.0, value);
}

TEST_F(CoulombLinkActionTest, testS2) {
	CoulombLinkAction::Vec delta1 = 0.0;
	delta1(0) = 2.0;
	CoulombLinkAction::Vec delta2 = 0.0;
	delta2(0) = 6.0;
	double value = CoulombLinkAction::calculateS2(delta1, delta2);
	ASSERT_DOUBLE_EQ(16.0, value);
}

TEST_F(CoulombLinkActionTest, testValueAtOrigin) {
	CoulombLinkAction::Vec delta1 = 0.0;
	CoulombLinkAction::Vec delta2 = 0.0;
	double value = action->getValue(delta1, delta2);
	double expect = -0.066158726800149281;
	ASSERT_NEAR(expect, value, 1e-8);
}

TEST_F(CoulombLinkActionTest, testDiagonalValue) {
	double dist = 50.0;
	CoulombLinkAction::Vec delta1 = 0.0;
	delta1(0) = dist;
	CoulombLinkAction::Vec delta2 = 0.0;
	delta2(0) = dist;
	double value = action->getValue(delta1, delta2);
	double expect = -0.00016653810535920257;
	ASSERT_NEAR(expect, value, 1e-8);
}

}
