#include <iostream>
#include <vector>

using namespace std;

class Edge
{
	public: 
		string edgeName;
		vector <Edge*> childrens;
};

void printing(string &row, Edge& thisEdge) {
	row += thisEdge.edgeName;
	cout << row << endl;

	for (int i = 0; i < thisEdge.childrens.size(); i++) {
		printing(row, *thisEdge.childrens[i]);
	}
	row = row.substr(0, row.size() - 1);
}


int main()
{
	string emptyRow = "";
	Edge m1,m2,m3,m4,m5;
	m1.edgeName = "A";
	m2.edgeName = "B";
	m3.edgeName = "C";
	m4.edgeName = "D";
	m5.edgeName = "E";

	m1.childrens.push_back(&m2);
	m1.childrens.push_back(&m3);
	m1.childrens.push_back(&m4);
	m2.childrens.push_back(&m3);
	m2.childrens.push_back(&m4);
	m3.childrens.push_back(&m4);
	m3.childrens.push_back(&m5);

	printing(emptyRow, m1);

	return 0;
}
