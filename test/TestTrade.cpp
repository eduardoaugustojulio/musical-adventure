#include <gtest/gtest.h>

#include "Trade.hpp"

TEST(TestTrade, CheckCategoryDefaulted){
    Trade trade(400000, "Public", "07/01/2020");
    EXPECT_STREQ(trade.categorizeRisk("12/11/2020").c_str(), RiskCategories::DEFAULTED.c_str());
}

TEST(TestTrade, CheckCategoryMediumRisk){
    Trade trade(5000000, "Public", "01/02/2024");
    EXPECT_STREQ(trade.categorizeRisk("12/11/2020").c_str(), RiskCategories::MEDIUMRISK.c_str());
}

TEST(TestTrade, CheckCategoryHighRisk){
    Trade trade(2000000, "Private", "12/29/2025");
    EXPECT_STREQ(trade.categorizeRisk("12/11/2020").c_str(), RiskCategories::HIGHRISK.c_str());
}

TEST(TestTrade, UnknownCategory){
    Trade trade(200, "Public", "10/26/2023");
    EXPECT_TRUE(trade.categorizeRisk("12/11/2020").empty());
}
