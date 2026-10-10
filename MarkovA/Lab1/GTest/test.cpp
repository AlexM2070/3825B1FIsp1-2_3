#include "pch.h"

#include "tbitfield.h"
#include "tset.h"

//TBitField
TEST(TestTBitField, Create_BitField) {
    ASSERT_NO_THROW(TBitField bf(10));
}

TEST(TestTBitField, SetBit_GetBit) {
    TBitField bf(32);
    bf.SetBit(5);
    EXPECT_EQ(1, bf.GetBit(5));
}

TEST(TestTBitField, ClrBit) {
    TBitField bf(32);
    bf.SetBit(10);
    bf.ClrBit(10);
    EXPECT_EQ(0, bf.GetBit(10));
}
TEST(TestTBitField, Operation_OR) {
    TBitField bf1(10), bf2(10);
    bf1.SetBit(2);
    bf2.SetBit(5);
    TBitField res = bf1 | bf2;
    EXPECT_EQ(1, res.GetBit(2));
    EXPECT_EQ(1, res.GetBit(5));
    EXPECT_EQ(0, res.GetBit(0));
}

TEST(TestTBitField, Operation_AND) {
    TBitField bf1(10), bf2(10);
    bf1.SetBit(2);
    bf1.SetBit(5);
    bf2.SetBit(5);
    TBitField res = bf1 & bf2;
    EXPECT_EQ(0, res.GetBit(2));
    EXPECT_EQ(1, res.GetBit(5));
}

TEST(TestTBitField, Operation_NOT) {
    TBitField bf(5); 
    bf.SetBit(0);
    bf.SetBit(2);
    TBitField res = ~bf;
    EXPECT_EQ(0, res.GetBit(0));
    EXPECT_EQ(1, res.GetBit(1));
    EXPECT_EQ(0, res.GetBit(2));
    EXPECT_EQ(1, res.GetBit(3));
    EXPECT_EQ(1, res.GetBit(4));
}

// TSet
TEST(TestTSet, Create_Set) {
    ASSERT_NO_THROW(TSet s(50));
}

TEST(TestTSet, InsElem_IsMember) {
    TSet s(20);
    s.InsElem(7);
    EXPECT_TRUE(s.IsMember(7));
    EXPECT_FALSE(s.IsMember(6));
}

TEST(TestTSet, DelElem) {
    TSet s(20);
    s.InsElem(7);
    s.DelElem(7);
    EXPECT_FALSE(s.IsMember(7));
}

TEST(TestTSet, Operation_Union) {
    TSet s1(10), s2(10);
    s1.InsElem(1);
    s2.InsElem(3);
    TSet res = s1 + s2;
    EXPECT_TRUE(res.IsMember(1));
    EXPECT_TRUE(res.IsMember(3));
    EXPECT_FALSE(res.IsMember(2));
}

TEST(TestTSet, Operation_Intersection) {
    TSet s1(10), s2(10);
    s1.InsElem(1);
    s1.InsElem(3);
    s2.InsElem(3);
    TSet res = s1 * s2;
    EXPECT_FALSE(res.IsMember(1));
    EXPECT_TRUE(res.IsMember(3));
}

TEST(TestTSet, Operation_Ñomplement) {
    TSet s(5);
    s.InsElem(0);
    s.InsElem(2);
    TSet res = ~s;
    EXPECT_FALSE(res.IsMember(0));
    EXPECT_TRUE(res.IsMember(1));
    EXPECT_FALSE(res.IsMember(2));
    EXPECT_TRUE(res.IsMember(3));
    EXPECT_TRUE(res.IsMember(4));
}
