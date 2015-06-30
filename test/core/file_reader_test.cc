#include <gtest/gtest.h>

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

#include <file_reader.h>

namespace {

class FileReaderTest : public ::testing::Test {


protected:
	binVec file1_;
	binVec file2_;

	FileReaderTest() :
		file1_{0x48,0x61,0x6c,
		       0x6c,0x6f,0x20,
		       0x77,0x69,0x65,
		       0x20,0x67,0x65,
		       0x68,0x74,0x20,
		       0x65,0x73,0x20,
		       0x64,0x69,0x72,
		       0x3f,0x0a} ,

		file2_{0x2,0x30,0x20,
		       0x50,0xaa,0xbb}
	{

	}

	virtual void SetUp() {
		//Create file1
		std::ofstream file1("file1");
		for(auto& b:file1_) {
			file1<<b;
		}
		file1.close();

		//Create file2
		std::ofstream file2("file2");
		for(auto& b:file2_) {
			file2<<b;
		}
		file2.close();
	}

	virtual void TearDown() {
		remove("file1");
		remove("file2");
	}
};

//Test for file1
TEST_F(FileReaderTest, TestFile1) {
	binVec inp_file1=erebus::FileReader::readFile("file1");

	EXPECT_EQ(file1_.size(),inp_file1.size());
	for(unsigned int i=0; i<inp_file1.size(); i++) {
		EXPECT_EQ(inp_file1[i],file1_[i]);
	}
}


//Test for file2
TEST_F(FileReaderTest, TestFile2) {
	binVec inp_file2=erebus::FileReader::readFile("file2");

	EXPECT_EQ(file2_.size(),inp_file2.size());
	for(unsigned int i=0; i<inp_file2.size(); i++) {
		EXPECT_EQ(inp_file2[i],file2_[i]);
	}
}


}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
