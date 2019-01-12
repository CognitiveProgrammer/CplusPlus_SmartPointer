/*
* MIT Licence
* Copyright 2017 @CodesBay
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"), to deal in the 
* Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software, 
* and to permit persons to whom the Software is furnished to do so, subject to the following conditions :

* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR 
* ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
* THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/* 
* visit https://github.com/9lean/CplusPlus_SmartPointer for description of the code
*/

#include <iostream>
#include <memory>
using namespace std;

// A Sample class with prints in constructor and destructor, so that we can track when the memory
// is allocated and deallocated

class Sample {
public:
	Sample() { cout << "Sample Constructor" << endl; }
	~Sample() { cout << "Sample Destructor" << endl; }
	void publicFn() { cout << "This is public function of class" << endl; }
};

// Test to confirm that shared pointers do release memory without explicitely calling
// the delete
void  TestSharedPtr_ReleaseMemory() {
	shared_ptr<Sample> sp(new Sample{});
	sp->publicFn();
	return;
}

// A helper function which returns a shared pointer
shared_ptr<Sample> AFunc() {
	cout << "Enter AFunc" << endl;
	shared_ptr<Sample> sp(new Sample{});
	cout << "Exit AFunc" << endl;
	return sp;
}

// Test to confirm that shared pointers does use reference counts 
void TestSharedPtr_ReferenceCount() {
	cout << "Enter TestSharedPtr_ReferenceCount" << endl;
	shared_ptr<Sample> retSp = AFunc();
	cout << "Exit TestSharedPtr_ReferenceCount" << endl;
	return;
}
// Test to confirm that shared pointers does use reference counts and use it smartly
void TestSharedPtr_ReferenceCount_Assignments() {
	cout << "Enter TestSharedPtr_ReferenceCount_Assignments" << endl;
	AFunc();
	cout << "Exit TestSharedPtr_ReferenceCount_Assignments" << endl;
	return;
}

// Test for using inbuilt Make_Shared to create a shared pointer
void TestSharedPtr_MakeShared() {
	shared_ptr<Sample> sp = make_shared<Sample>();
	return;
}

int main() {
	TestSharedPtr_ReleaseMemory();
	cout << "------------------------------------------------" << endl;
	TestSharedPtr_ReferenceCount();
	cout << "------------------------------------------------" << endl;
	TestSharedPtr_ReferenceCount_Assignments();
	cout << "------------------------------------------------" << endl;
	TestSharedPtr_MakeShared();
	return 0;
}
