/*
Problem Statement:
-----------------
Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. 
Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: If two elements have same frequency, then the element which occur at first will be taken on the left of Binary Tree and other one to the right.

Example 1:
---------
S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111
Explanation:
HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Hence printing them in the PreOrder of Binary Tree.

Your Task: You don't need to read or print anything. Your task is to complete the function huffmanCodes() which takes the given string S, 
frequency array f[ ] and number of characters N as input parameters and returns a vector of strings containing all huffman codes in order of preorder traversal of the tree.

Expected Time complexity: O(N * LogN) 
Expected Space complexity: O(N) 
*/

// Link --> https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

// Code:
struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data , unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode* l , MinHeapNode* r)
    {
        return(l->freq > r->freq);
    }
};

class Solution
{
	public:
	    void getCodes(struct MinHeapNode* root , string str , vector<string> &res)
        {
            if(!root)
                return;
                
            if(root->data != '$')
                res.push_back(str);
            
            getCodes(root->left, str + "0",res);
            getCodes(root->right, str + "1",res);
        }
    
		vector<string> huffmanCodes(string S , vector<int> f , int N)
		{
		    struct MinHeapNode *left , *right , *top;
		    
            priority_queue <MinHeapNode*, vector<MinHeapNode*> , compare> minHeap;
            
            for(int i = 0; i<N ; ++i)
                minHeap.push(new MinHeapNode(S[i] , f[i]));
                
            while(minHeap.size() != 1)
            {
                left = minHeap.top();
                minHeap.pop();
                
                right = minHeap.top();
                minHeap.pop();
        
                top = new MinHeapNode('$', left->freq + right->freq);
                
                top->left = left;
                top->right = right;
                
                minHeap.push(top);
            }
            
            vector<string> res;
            getCodes(minHeap.top(), "",res);
            
            return res;
		}
};
