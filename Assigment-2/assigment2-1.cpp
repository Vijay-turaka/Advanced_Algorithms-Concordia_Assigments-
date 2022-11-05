#include <iostream>
using namespace std;

int main()
{
    int n, m, size=0, value, k=0;
    cout<<"enter inputs \n";
    cin>>n;
    cin>>m;
	int sMatrix[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		    cout<<"enter array values ["<<i<<"] ["<<j<<"] :";
		    cin>>value;
			if (value != 0) {
				size++;
			}
			sMatrix[i][j]=value;
		}
	}
	int Matrix[3][size];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sMatrix[i][j] != 0)
			{
				Matrix[0][k] = i;
				Matrix[1][k] = j;
				Matrix[2][k] = sMatrix[i][j];
				k++;
			}
		}
	}

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<size; j++)
			cout <<Matrix[i][j] <<" ";
		cout <<"\n";
	}
	return 0;
}

