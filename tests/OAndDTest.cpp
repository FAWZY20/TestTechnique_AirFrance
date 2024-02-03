#include <gtest/gtest.h>
#include "../src/OAndD.h"


std::set<long> tarifs = {100, 200, 300};
OAndD od("CDG", "JFK", tarifs);

TEST(OAndD, get)
{
    EXPECT_EQ(od.getOrigine(), "CDG");
    EXPECT_EQ(od.getDestination(), "JFK");
    EXPECT_EQ(od.getTarifs(), tarifs);
}

TEST(OAndD, tarifMin)
{
     EXPECT_EQ(tarifMin(tarifs), 100);
}

TEST(OAndD, tarifMax)
{
     EXPECT_EQ(tarifMax(tarifs), 300);
}

TEST(OAndD, tarifMoy)
{
     EXPECT_EQ(tarifMoy(tarifs), 233);
}