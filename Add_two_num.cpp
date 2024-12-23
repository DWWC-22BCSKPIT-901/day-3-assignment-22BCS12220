//Add two numbers
#include <iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(); 
    ListNode* current = dummyHead;      
    int carry = 0;                       

    while (l1 || l2 || carry) {
        int sum = carry; 
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10; 
        current->next = new ListNode(sum % 10); 
        current = current->next;
    }

    return dummyHead->next; // Return the head of the result list
}
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " , ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input
    vector<int> l1Values = {2, 4, 3};
    vector<int> l2Values = {5, 6, 4};

    // Create linked lists from input arrays
    ListNode* l1 = createLinkedList(l1Values);
    ListNode* l2 = createLinkedList(l2Values);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result linked list
    cout << "Result: ";
    printLinkedList(result);

    return 0;
}
