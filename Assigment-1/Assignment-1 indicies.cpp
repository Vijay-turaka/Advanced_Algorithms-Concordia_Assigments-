#include <bits/stdc++.h>
#include <map>
using namespace std;

void check_pairs(int arr[], int size, int Totalsum)
{
	std::map<int, int> Hashmap = {};
	for(int i = 0; i < size; i++) {
		int temp = Totalsum - arr[i];
		if(Hashmap.find(temp) != Hashmap.end()) {
		    cout << Hashmap[temp] << "," << i << endl;
	        return; 
		}
		Hashmap.insert(pair<int, int>(arr[i],i));
	}
	cout << "No values matched" << endl;
}

int main()
{
    int n, target;
	cout << "Enter size of the array:" << "\n";
	cin >>n;
	int *arr = new int(n);
	cout << "Enter array values" << endl;
	for (int x = 0; x < n; x++) {
		cin >> arr[x];
	}
	cout << "Enter target value"<<"\n";
	cin >>target;
	check_pairs(arr, n, target);
	return 0;
}
