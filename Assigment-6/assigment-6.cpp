#include <bits/stdc++.h>
#include <cstring>
using namespace std;

struct Node
{
    char data;
    unsigned freq;
    Node *left, *right;
    Node(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct ComparisonType
{
    bool operator()(Node *l, Node *r)
    {
        return (l->freq > r->freq);
    }
};

void printchar_array(struct Node *root, string str)
{
    if (!root)
    {
        return;
    }
    if (root->data != '#')
    {
        cout << "\t"<<root->data << " : " << str << "\n";
    }
    printchar_array(root->left, str + "0");
    printchar_array(root->right, str + "1");
}

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    int size = s.length();
    char char_array[size];
    int freq[size];
    strcpy(char_array, s.c_str());
    for (int i = 0; i < size; i++)
    {
        cout << "Enter frequency (" << char_array[i] <<"): ";
        cin >> freq[i];
    }
    priority_queue<Node *, vector<Node *>, ComparisonType> Heap;
    for (int i = 0; i < size; ++i)
    {
        Heap.push(new Node(char_array[i], freq[i]));
    }
    struct Node *left, *right, *top;
    while (Heap.size() != 1)
    {
        left = Heap.top();
        Heap.pop();
        right = Heap.top(); 
        Heap.pop();
        top = new Node('#', left->freq + right->freq);
        top->left = left;
        top->right = right;
        Heap.push(top);
    }
    cout << "\ncharacter" << " : " << "frequency"<< "\n";
    printchar_array(Heap.top(), " ");
    return 0;
}
