#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
	Solution(): id_(0) {
		cout << "Default Constructor:id="
		     << id_ << "	addr=:" << this << endl;
	}
	Solution(int id): id_(id) {
		cout << "Constructor with Paramter:id="
		     << id_ << "	addr=:" << this << endl;
	}
	Solution(const Solution&course): id_(course.id_) {
		cout << "Copy Constructor :id="
		     << id_ << "	addr=:" << this << endl;
	}
	~Solution() {
		cout << "Destructor:id="
		     << id_ << "	addr=:" << this << endl;
	}
	int GetId() {return id_;};

  private:
	int id_;
};

Solution Max(Solution a, Solution b) {
	if (a.GetId() > b.GetId()) {
		cout << "end " << endl;
		return a;
		cout << "end after return" << endl;
	} else {
		cout << "end " << endl;
		return b;
		cout << "end after return" << endl;
	}
}

void Q2() {
	Solution class1(1);
	// Solution class2;
	Solution class2 = class1;
	// class2 = class1;
	Solution classX(5), classY(6);
	Solution classZ;
	// classZ = class1;
	// Max(classX, classY);
	classZ = Max(classX, classY);
	cout << "after max" << endl;
	Solution *pClasses = new Solution[3];
	delete [] pClasses;
}
int main(int argc, char const *argv[]) {
	/* code */
	Q2();
	system("pause");
	return 0;
}