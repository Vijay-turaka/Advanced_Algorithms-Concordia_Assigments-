
#include<iostream>
using namespace std;

class Node {
	public:
	int row;
	int col;
	int data;
	Node *next;
};

void createNode(Node **refFirst, int row, int col, int data) {
	Node *tempFirst = *refFirst;
	Node *newNode;
	if(tempFirst == NULL) {
		tempFirst = new Node();
		tempFirst->row = row;
		tempFirst->col = col;
		tempFirst->data = data;
		tempFirst->next = NULL;
		*refFirst = tempFirst;
	}
	else {
		while(tempFirst->next != NULL) {
			tempFirst = tempFirst->next;
	    }	
		newNode = new Node();
		newNode->row = row;
	    newNode->col = col;
		newNode->data = data;
		newNode->next = NULL;
		tempFirst->next = newNode;
	}
}

int main()
{
	int n, m, value, k=0;
	Node *startNode = NULL;
    cout<<"enter size of matrix n and m \n";
    cout<<"enter n value: ";
    cin>>n;
    cout<<"enter m value: ";
    cin>>m;
	int matrix[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		    cout<<"enter array values ["<<i<<"] ["<<j<<"] :";
		    cin>>value;
		    matrix[i][j]=value;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
		    if(matrix[i][j]!=0) {
		        createNode(&startNode, i, j, matrix[i][j]);
		    }
		}
	}
	cout<< "\nprinting linked list representation:\n";
	while (startNode != NULL)	{
	    cout << "* row[" << startNode->row << "]-"<< "col[" << startNode->col << "]-" << "data[" <<startNode->data <<"]--> ";
		startNode = startNode->next;
	}
	return 0;
}
