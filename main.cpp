/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.05.2014 09:10:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Chebotarsky (), sashach@aerotechnica.ua
 *   Organization:  Aerotechnica, Ukraine
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#include <gtest/gtest.h>

#include "test_class.h"

const char test_string[] = "My test string";
const char new_string[] = "Another test string";

TEST(BaseClass, sizeof) {
	typedef struct { int32_t s; char* b; size_t sise; } base_class_t;
    BaseClass b;
    
    EXPECT_EQ(sizeof(b), sizeof(base_class_t));
    EXPECT_EQ(b.GetS(), 10);
    EXPECT_EQ(b.GetBufferSize(), 0);
    EXPECT_EQ(b.GetBuffer(), nullptr);
}

TEST(BaseClass, Initialisation) {
    BaseClass b;
    EXPECT_EQ(b.GetS(), 10);
}

TEST(BaseClass, Copy) {

    BaseClass b(20);
    EXPECT_EQ(b.GetS(), 20);

    BaseClass c = b;
    
    EXPECT_EQ(c.GetS(), 20);
}

TEST(BaseClass, CopyConstructor) {

    BaseClass b(30);
    EXPECT_EQ(b.GetS(), 30);

    BaseClass c;
    c = b;
    
    EXPECT_EQ(c.GetS(), 30);
}

TEST(BaseClass, Buffer) {

    BaseClass b;
    b.SetBuffer(test_string, sizeof(test_string));

    EXPECT_EQ(b.GetBufferSize(), sizeof(test_string));
    EXPECT_STREQ(b.GetBuffer(), test_string);

    BaseClass c = b;

    EXPECT_EQ(b.GetBufferSize(), c.GetBufferSize());
    EXPECT_STREQ(b.GetBuffer(), c.GetBuffer());

    BaseClass d(b);

    EXPECT_EQ(b.GetBufferSize(), d.GetBufferSize());
    EXPECT_STREQ(b.GetBuffer(), d.GetBuffer());

    d.SetBuffer(new_string, sizeof(new_string));

    EXPECT_NE(b.GetBufferSize(), d.GetBufferSize());
    EXPECT_STRNE(b.GetBuffer(), d.GetBuffer());
}

TEST(BaseClass, Destructor) {

    BaseClass *b = new BaseClass();
    b->SetBuffer(test_string, sizeof(test_string));
    EXPECT_STREQ(b->GetBuffer(), test_string);

    const char * c = b->GetBuffer();
    EXPECT_STREQ(c, test_string);

    delete b;

    EXPECT_STRNE(c, test_string);
}

TEST(BaseClass, Limits) {
    BaseClass b;

	EXPECT_THROW(b.SetBuffer(0, 10), std::logic_error);
	EXPECT_THROW(b.SetBuffer(test_string, 0), std::logic_error);
	EXPECT_THROW(b.SetBuffer(test_string, std::numeric_limits< size_t >::max()), std::logic_error);
}

TEST(BaseClass, BitOperations) {
    BaseClass b(0);

    b.SetBitInS(5);
    EXPECT_EQ(b.GetS(), 32);

    EXPECT_TRUE(b.IsSetBitInS(5));
    EXPECT_FALSE(b.IsSetBitInS(3));

    EXPECT_TRUE(b.IsEvenS());
    b.SetS(11);
    EXPECT_FALSE(b.IsEvenS());
}
//
//TEST(DataStorageTest, algorithm) {
//    StorageClass s;
//
//    std::vector<int> v1 = {1, 2, 3, 4};
//    s.SetData(v1); 
//    EXPECT_EQ(s.GetDataSize(), 4);
//
//    std::vector<int> v2 = {11, 2, 31, 24, 16};
//    s.SetData(v2); 
//    EXPECT_EQ(s.GetDataSize(), 5);
//
//    EXPECT_EQ(s.GetDataAt(3), 24);
//	EXPECT_THROW(s.GetDataAt(10), std::logic_error);
//
//    s.SortData(); // sorting descending
//    EXPECT_EQ(s.GetDataAt(0), 31);
//    EXPECT_EQ(s.GetDataAt(1), 24);
//    EXPECT_EQ(s.GetDataAt(2), 16);
//    EXPECT_EQ(s.GetDataAt(3), 11);
//    EXPECT_EQ(s.GetDataAt(4), 2);
//
//    EXPECT_EQ(s.FindItemPosition(99), -1);
//    EXPECT_EQ(s.FindItemPosition(24), 1);
//}
//
//using namespace MyNamespace;
//
//TEST(DerivedClass, Inheritance) {
//    ClassA a;
//    EXPECT_EQ(a.GetSomeIntValue(), 222);
//
//    ClassB b;
//    EXPECT_EQ(b.GetSomeIntValue(), 333);
//
//    ClassA *ab = new ClassB();
//    EXPECT_EQ(ab->GetSomeIntValue(), 333);
//    delete ab;
//
//    ClassC c;
//    EXPECT_EQ(c.GetCharA(), 'A');
//    EXPECT_EQ(c.GetCharB(), 'B');
//}
//
//TEST(GetValue, template_function) {
//    ClassA a;
//    EXPECT_EQ(GetValue < ClassA >(a), 222);
//
//    ClassB b;
//    EXPECT_EQ(GetValue < ClassB >(b), 333);
//
//    ClassD d;
//    EXPECT_EQ(GetValue < ClassD >(d), 555);
//}
//
//TEST(Coordinates, template_class) {
//    Coordinates <int> a(10, 10);
//    Coordinates <double> b(20.555, 20.555);
//
//    EXPECT_EQ(a.GetX(), 10);
//    EXPECT_EQ(a.GetY(), 10);
//
//    EXPECT_EQ(b.GetX(), 20.555);
//    EXPECT_EQ(b.GetY(), 20.555);
//}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}				/* ----------  end of function main  ---------- */
