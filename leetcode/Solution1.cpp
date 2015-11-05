#include <iostream>
using namespace std;
class Solution1
{
public:
	int removeElement(int A[], int n, int elem); 
private:
};

int Solution1::removeElement(int A[], int n, int elem)
{
	int i = 0, j = 0;
	for (j = 0; j < n; j++)
		if (A[j] != elem)
			A[i++] = A[j];
	return i;
}

int main() {
	int A[5] = { 1,2,3,4,5 };
	Solution1 a =  Solution1();
	int len = a.removeElement(A, 5, 3);
	cout << len << endl;
}