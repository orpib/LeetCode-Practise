/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class CompareList {
public:
    bool operator()(const ListNode* below, const ListNode* above)
    {
        // if(below == NULL|| above == NULL ) {
        //     cout<<"KHAICE"<<endl;
        // }
        return below->val > above->val ;

    }
};

struct ListNodeComparator {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {




        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;//value,index of ListNode in vector
        // for(int i=0;i<lists.size();i++)
        // {
        //     if(lists[i]!=NULL)
        //     {
        //         minheap.push({lists[i]->val,i});
        //     }
        // }



        
        priority_queue<ListNode*  , vector<ListNode*> , ListNodeComparator> listPQ;


        for (auto list : lists) {
            if (list) listPQ.push(list);
        }
        
        // ListNode dummy(0);
        // ListNode* curr = &dummy;
        // while (!pq.empty()) {
        //     auto node = pq.top();
        //     pq.pop();
            
        //     curr->next = node;
        //     curr = curr->next;
            
        //     if (node->next) pq.push(node->next);
        // }
        
        // return dummy.next;


        // for(auto list : lists){
        //     ListNode* root = list;
        //     while(root!= NULL){
        //         listPQ.push(root);
        //         root = root->next;
        //     }
        // }

         if(listPQ.empty())//Edge Case Handling
        {
            //cout<< "ENDED  "<<endl;
            return NULL;
        }
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(!listPQ.empty()){
            auto node = listPQ.top();
            listPQ.pop();
            
            curr->next = node;
            curr = curr->next;
            
            if (node->next) listPQ.push(node->next);





            // cout<<listPQ.top()<<endl;
            // // curr = listPQ.top();
            // // head = listPQ.top();
            // if(head == NULL){
            //     curr = listPQ.top();
            //     head = listPQ.top();
            // }
            // else{
            //     curr = listPQ.top();
                
            // }
            // curr = curr->next;
            
            
            // listPQ.pop();
        }
        
        return dummy.next;
        
        //return head;
    }
};