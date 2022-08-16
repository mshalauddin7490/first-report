#include <bits/stdc++.h>

using namespace std;

class DoublyNode
{
public:
  int val;
  DoublyNode *next;
  DoublyNode *prev;
  DoublyNode(int val)
  {
    this->val = val;
    this->next = NULL;
    this->prev = NULL;
  }
};
void printDoublyNode(DoublyNode *&head)
{
  DoublyNode *temp = head;
  while (temp != NULL)
  {
    cout << temp->val;
    if (temp->next != NULL)
      cout << " -> ";
    temp = temp->next;
  }
  cout << endl
       << "End of nodes." << endl;
}
void insert_doubly_node(DoublyNode *&head, int val)
{
  DoublyNode *newDoublyNode = new DoublyNode(val);
  DoublyNode *temp = head;
  if (head == NULL)
  {
    head = newDoublyNode;
  }
  else
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newDoublyNode;
  }
}
void insert_doubly_node_by_position(DoublyNode *&head, int val, int pos)
{
  DoublyNode *temp = head;
  DoublyNode *newDoublyNode = new DoublyNode(val);
  for (int i = 1; i < pos - 1; i++)
  {
    temp = temp->next;
  }
  DoublyNode *temp1 = temp->next;
  newDoublyNode->prev = temp;
  newDoublyNode->next = temp1;
  temp->next = newDoublyNode;
  temp1->prev = newDoublyNode;
}
void move_doubly_node_head(DoublyNode *&head)
{
  DoublyNode *temp1 = head;
  DoublyNode *temp2 = head->next;
  temp1->next = NULL;
  temp2->prev = NULL;
  head = temp2;
  while (temp2->next != NULL)
  {
    temp2 = temp2->next;
  }
  temp2->next = temp1;
}
void move_doubly_node_tail(DoublyNode *&head)
{
  DoublyNode *temp = head;
  DoublyNode *temp2 = NULL;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  temp2 = temp->next;
  temp->next = NULL;
  temp2->next = head;
  head = temp2;
}
void delete_doubly_node_by_position(DoublyNode *&head, int pos)
{
  DoublyNode *temp = head;
  for (int i = 1; i < pos - 1; i++)
  {
    temp = temp->next;
  }
  DoublyNode *temps = temp->next;
  temp->next = temp->next->next;
  temp->next->prev = temp;
  delete (temps);
}
int main()
{
  int n, val, pos;
  cin >> n;
  DoublyNode *head = NULL;
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    insert_doubly_node(head, val);
  }
  printDoublyNode(head);
  // move_doubly_node_head(head);
  // printDoublyNode(head);
  // move_doubly_node_tail(head);
  // printDoublyNode(head);
  // cout << "Enter value and position: ";
  // cin >> pos;
  // cin >> val;
  // insert_doubly_node_by_position(head, val, pos);
  // printDoublyNode(head);
  cout << "Enter position: ";
  cin >> pos;
  delete_doubly_node_by_position(head, pos);
  printDoublyNode(head);
  return 0;
}