/*
Problem Statement:
------------------
In operating systems that use paging for memory management, page replacement algorithm is needed to decide which page needs to be replaced when the new page comes in. 
Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page.

Given a sequence of pages in an array pages[] of length N and memory capacity C, find the number of page faults using Least Recently Used (LRU) Algorithm. 

Example 1:
---------
Input: N = 9, C = 4
pages = {5, 0, 1, 3, 2, 4, 1, 0, 5}
Output: 8
Explaination: memory allocated with 4 pages 5, 0, 1, 
3: page fault = 4
page number 2 is required, replaces LRU 5: 
page fault = 4+1 = 5
page number 4 is required, replaces LRU 0: 
page fault = 5 + 1 = 6
page number 1 is required which is already present: 
page fault = 6 + 0 = 6
page number 0 is required which replaces LRU 1: 
page fault = 6 + 1 = 7
page number 5 is required which replaces LRU 3: 
page fault = 7 + 1  =8.
Your Task:
You do not need to read input or print anything. Your task is to complete the function pageFaults() which takes N, C and pages[] as input parameters and 
returns the number of page faults.

Expected Time Complexity: O(N*C)
*/

// Link -->  https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1#

// Code:
class Solution
{
public:
    int pageFaults(int n, int c, int pages[])
    {
        int faults = 0;
        // to store pages in the memory.
        unordered_set <int> s;
        // to store index of pages of the memory.
        unordered_map <int , int> mp;
        
        for(int i=0 ; i<n ; i++)
        {
            // if set is not full.
            if(s.size() < c)
            {
                // if page is not present in the memory.
                if(s.find(pages[i]) == s.end())
                {
                    faults++;
                    s.insert(pages[i]);
                }
                // inserting index of the current page.
                mp[pages[i]] = i;
            }
            
            else
            {
                if(s.find(pages[i]) == s.end())
                {
                    faults++;
                    
                    int lru_page = INT_MAX;
                    int value = 0;
                    
                    // finding the least recently used page.
                    for(auto it=s.begin() ; it!=s.end() ; it++)
                        if(mp[*it] < lru_page)
                        {
                            lru_page = mp[*it];
                            value = *it;
                        }
                    // removing the LRU page and inserting current page in memory and
                    // its index in the map.
                    s.erase(value);
                    s.insert(pages[i]);
                    mp[pages[i]] = i;
                }
                mp[pages[i]] = i;
            }
        }
        return faults;
        
    }
};
