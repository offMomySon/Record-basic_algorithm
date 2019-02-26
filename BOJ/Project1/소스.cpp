#include<iostream>

using namespace std;

class CTest
{
public :
	CTest()
	{
		cout << "CTest()" << endl;
		m_nData = 100;
	}

	CTest(int n)
	{
		m_nData = n;
		cout << "CTest()" << endl;
	}
	
	~CTest()
	{
		cout << "~CTest()" << endl;
	}
	void print_data()
	{
		cout << m_nData << "\n";
	}
private :
	int m_nData;

};


int main()
{
	cout << "Begin of main()" << endl;	
	
	CTest *a = new CTest();
	CTest *b = new CTest(3);
	a->print_data();

	b->print_data();
	delete a;
	delete b;

	cout << "End of main()" << endl;

}