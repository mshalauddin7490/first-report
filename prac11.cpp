#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};
void printNode(Node *&head);
void insertNode(Node *&head, int val);
void insert_node_by_position(Node *&head, int val, int pos);
void delete_node_by_position(Node *&head, int pos);
int countNode(Node *&head);
void move_tail(Node *&head);

void printNode(Node *&head)
{
  Node *temp = head;
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
void insertNode(Node *&head, int val)
{
  Node *temp = head;
  Node *newNode = new Node(val);
  if (temp != NULL)
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  else
  {
    head = newNode;
  }
}
void insert_node_by_position(Node *&head, int val, int pos)
{
  Node *temp = head;
  Node *newNode = new Node(val);

  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}
void delete_node_by_position(Node *&head, int pos)
{
  Node *temp = head;
  for (int i = 1; i < pos - 1; i++)
  {
    temp = temp->next;
  }
  Node *delNode = temp->next;
  temp->next = temp->next->next;
  delete (delNode);
}
int countNode(Node *&head)
{
  Node *temp = head;
  int count = 1;
  while (temp->next != 0)
  {
    temp = temp->next;
    count++;
  }
  return count;
}
void move_tail(Node *&head)
{
  Node *temp = head;
  Node *temp2 = NULL;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  temp2 = temp->next;
  temp->next = NULL;
  temp2->next = head;
  head = temp2;
}
void create_cycle(Node *&head, int pos)
{
  Node *temp = head;
  Node *cycle_start = head;
  int count = 1;
  while (temp->next != NULL)
  {
    if (count == pos)
      cycle_start = temp;
    temp = temp->next;
    count++;
  }
  temp->next = cycle_start;
}
int find_mid(Node *&head)
{
  Node *temp = head;
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->val;
}

bool detect_cycle(Node *&head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
    {
      return true;
    }
  }
  return false;
}
void deletion_of_cycle(Node *&head)
{
  if (detect_cycle(head))
  {
    Node *slow = head;
    Node *fast = head;
    do
    {
      slow = slow->next;
      fast = fast->next->next;
    } while (fast != slow);
    fast = head;
    while (slow->next != fast->next)
    {
      slow = slow->next;
      fast = fast->next;
    }
    slow->next = NULL;
  }
  else
  {
    cout << "No cycle Available" << endl;
  }
}
int main()
{
  Node *head = NULL;
  int n, val, pos, option;
  cout << "How many nodes you want to enter: ";
  cin >> n;
  cout << "Enter the nodes: ";
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    insertNode(head, val);
  }
  printNode(head);
  // cout << "Choise 1: Insert value by postion." << endl
  //      << "choise 2: Delete node by position." << endl
  //      << "Choise 0; To Exit." << endl;
  // cout << "Enter your option: ";
  // cin >> option;
  // while (option != 0)
  // {
  //   switch (option)
  //   {
  //   case 1:
  //     cout << "Enter the position of the value: ";
  //     cin >> pos;
  //     cout << "Enter the value of the node: ";
  //     cin >> val;
  //     insert_node_by_position(head, val, pos);
  //     break;
  //   case 2:
  //     cout << "Enter the position of the value: ";
  //     cin >> pos;
  //     delete_node_by_position(head, pos);
  //     break;
  //   case 3:
  //     break;
  //   default:
  //     break;
  //   }
  //   cout << "Enter next option: ";
  //   cin >> option;
  // }
  cout << "Number of Nodes: ";
  cout << countNode(head) << endl;
  // move_tail(head);
  // printNode(head);
  // int mid = find_mid(head);
  // cout<<mid<<endl;
  cout << "Enter the cycle position: ";
  cin >> pos;
  create_cycle(head, pos);
  // printNode(head);
  if (detect_cycle(head) == true)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  deletion_of_cycle(head);
  if (detect_cycle(head) == true)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}