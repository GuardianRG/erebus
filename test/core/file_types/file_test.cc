#include <gtest/gtest.h>

#include <file.h>
#include <stdexcept>

namespace {
class FileTest: public ::testing::Test {
  protected:
	erebus::File	file1_;

	FileTest() : file1_(erebus::File(new binVec{52,45,100,34,21},"test_path")) {

	}

	virtual void SetUp() {
	}

	virtual void TearDown() {

	}
};


//Test for the correct file size
TEST_F(FileTest, TestFileSize) {
	unsigned int expectedLen=5;
	EXPECT_EQ(expectedLen,file1_.getFileSize());
}

//Test for correct indexing
TEST_F(FileTest, TestIndexing) {
	unsigned char ch1=52;
	unsigned char ch2=45;
	unsigned char ch3=100;
	unsigned char ch4=34;
	unsigned char ch5=21;

	EXPECT_EQ(ch1,file1_.getUnsignedByteAt(0));
	EXPECT_EQ(ch2,file1_.getUnsignedByteAt(1));
	EXPECT_EQ(ch3,file1_.getUnsignedByteAt(2));
	EXPECT_EQ(ch4,file1_.getUnsignedByteAt(3));
	EXPECT_EQ(ch5,file1_.getUnsignedByteAt(4));
}

//Test for inavlid index
TEST_F(FileTest,TestInvalidIndex) {
	EXPECT_THROW(file1_.getUnsignedByteAt(-1),std::out_of_range);
}


}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
