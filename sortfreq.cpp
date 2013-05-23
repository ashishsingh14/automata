#include <iostream>
#include <stdlib.h>

using namespace std;

struct BSTnode{
    struct BSTnode *left;
    struct BSTnode *right;
    int data;
    int freq;
};

struct freqnode{
    int data;
    int freq;
};

int compare(const void *a, const void *b)
{
    return ( (*(const freqnode*)b).freq - (*(const freqnode*)a).freq );
}

BSTnode* createnode(int a)
{
   struct BSTnode *node = new BSTnode;
            node->data = a;
            node->left = NULL;
            node->right = NULL;
            node->freq = 1;
    return (node);
}

BSTnode* insertnode (BSTnode* root, int a)
{
    if(root==NULL)
        return createnode(a);
    if (root->data==a)
        root->freq+=1;
    else if(a<root->data)
        root->left = insertnode(root->left,a);

    else
            root->right = insertnode(root->right,a);
    return root;
}

void store(BSTnode *root, freqnode count[], int *index)
{
    // Base Case
    if (root == NULL) return;

    // Recur for left substree
    store(root->left, count, index);

    // Store item from root and increment index
    count[(*index)].freq = root->freq;
    count[(*index)].data = root->data;
    (*index)++;

    // Recur for right subtree
    store(root->right, count, index);
}

void sortByFrequency(int arr[], int n)
{
    // Create an empty BST and insert all array items in BST
    struct BSTnode *root = NULL;
    for (int i = 0; i < n; ++i)
        root = insertnode(root, arr[i]);

    // Create an auxiliary array 'count[]' to store data and
    // frequency pairs. The maximum size of this array would
    // be n when all elements are different
    freqnode count[n];
    int index = 0;
    store(root, count, &index);

    // Sort the count[] array according to frequency (or count)
    qsort(count, index, sizeof(count[0]), compare);

    // Finally, traverse the sorted count[] array and copy the
    // i'th item 'freq' times to original array 'arr[]'
    int j = 0;
    for (int i = 0; i < index; i++)
    {
        for (int freq = count[i].freq; freq > 0; freq--)
            arr[j++] = count[i].data;
    }
}

void printBSTtree(BSTnode*root)
{
	printBSTtree(root->left);
	cout<<root->data<<" "<<root->freq<<endl;
	printBSTtree(root->right);
	
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
        int n = sizeof(arr)/sizeof(arr[0]);
        sortByFrequency(arr, n);
        printArray(arr, n);

    return 0;
}

