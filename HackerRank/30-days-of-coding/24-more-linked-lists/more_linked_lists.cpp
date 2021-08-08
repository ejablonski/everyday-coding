// https://www.hackerrank.com/challenges/30-linked-list-deletion
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Solution {
public:   
    Node* removeDuplicates(Node* head) {
        vector<int> v_data;
        v_data.push_back(head->data);
        Node* prev = head;
        Node* current = head->next;

        while(current != NULL) {
            bool dupe = false;

            for(int i = 0; i < v_data.size(); i++) {                    
                if(v_data[i] == current->data) {
                    dupe = true;
                    break;
                }
            }

            if(!dupe) {
                v_data.push_back(current->data);
                prev = current;
                current = prev->next;
            } else {
                delete prev->next;
                prev->next = current->next;
                current = current->next;
            }                
        }
        return head;
    }

    Node* insert(Node* head, int data) {
        Node* p = new Node(data);
        if(head == NULL) {
            head = p;
        } else if(head->next == NULL) {
            head->next = p;
        } else {
            Node* start = head;
            while(start->next != NULL) {
                start = start->next;
            }
            start->next = p;
        }
        return head;   
    }

    void display(Node* head) {
        Node *start = head;
        while(start) {
            cout << start->data << " ";
            start = start->next;
        }
    }
};
			
int main()
{
    Node* head = NULL;
    Solution mylist;

    int T, data;
    cin >> T;

    while(T-- > 0) {
        cin >> data;
        head = mylist.insert(head, data);
    }

    head = mylist.removeDuplicates(head);

    mylist.display(head);		
}