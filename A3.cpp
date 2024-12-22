#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode *current = &dummy;

    while (current->next)
    {
        if (current->next->val == val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
    return dummy.next;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >> n;

    ListNode *head = nullptr, *tail = nullptr;
    cout << "Enter the elements of the linked list: ";
    while (n--)
    {
        int nodeVal;
        cin >> nodeVal;
        ListNode *newNode = new ListNode(nodeVal);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail = tail->next = newNode;
        }
    }

    cout << "Enter the value to remove: ";
    cin >> val;

    head = removeElements(head, val);

    cout << "Linked list after removal: ";
    printList(head);

    return 0;
}
