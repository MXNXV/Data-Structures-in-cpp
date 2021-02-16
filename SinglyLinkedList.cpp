/*
Singly linked list operations :
appendnode()
prependNode()
insertNodeAfter()
deleteNodeByKey()
UpdateNodeByKey()
print()
*/



#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node*next;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k,int d)
        {
            key = k;
            data = d;
        }
};

class SinglyLinkedList{
    public:
        Node *head;
        SinglyLinkedList()
        {
            head = NULL;
        }
        SinglyLinkedList(Node *n)
        {
            head = n;
        }
        //Check if node exists using the key value
        Node* NodeExists(int k)
        {
            Node *temp = NULL;
            Node* ptr = head;
            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } 
            return temp;//Return Null if the node doesnt exists else return dome value
        }

        //Append Node Function
        void AppendNode(Node *n)
        {
            if(NodeExists(n->key)!=NULL)
            {
                cout<<"Node already exists with key value : "<<n->key<<". Append the node at a different location"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head = n;
                    cout<<"Node Appended"<<endl;
                }
                else
                {
                    Node *ptr = head;
                    while(ptr->next!=NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    cout<<"Node Appended"<<endl;
                }
            }
        }
        //Used to prepend a node in the beginning
        void PrependNode(Node *n)
        {
            if(NodeExists(n->key)!=NULL)
            {
                cout<<"Node already exixts with key value : "<<n->key<<". Append node at a different location"<<endl;
            }
            else
            {
                n->next = head;
                head = n;
                cout<<"Node Prepended"<<endl;
            }
        }
        //Used to add node in the middle
        void InsertNode(int k, Node *n)
        {
            Node *ptr = NodeExists(k);
            if (ptr == NULL)
            {
                cout<<"No node exists with key value : "<<k<<endl;
            }
            else
            {
                if(NodeExists(n->key)!=NULL)
                {
                    cout<<"Node already exixts with key value : "<<n->key<<". Append node at a different location"<<endl;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout<<"Node Inserted"<<endl;
                }
            }
        }

        //Delete node by unique keys
        void deleteNode(int k)
        {
            if(head == NULL)
            {
                cout<<"Singly inked list is already empty. Can't delete"<<endl;
            }
            else if (head!=NULL)
            {
                if(head->key==k)
                {
                    head = head->next;
                    cout<<"Node UNLINKED with key value : "<<k<<endl;
                }
                else
                {
                    Node *temp = NULL;
                    Node *prevptr = head;
                    Node *currentptr = head->next;
                    while(currentptr!=NULL)
                    {
                        if(currentptr->key==k)
                        {
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else
                        {
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }
                    if(temp!=NULL)
                    {
                        prevptr->next = temp->next;
                        cout<<"Node UNLINKED with key values : "<<k<<endl;
                    }
                    else
                    {
                        cout<<"Node doesnt exist with key value : "<<k;
                    }
                }
            }
        }

        //Updating Node using the Key value
        void UpdateNodebyKey(int k, int d)
        {
            Node *ptr = NodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data = d;
                cout<<"Node data updated successfully!"<<endl;
            }
            else
            {
                cout<<"Node doesnt exist with key value : "<<k<<endl;
            }
        }

        //Printing out the entire linked list
        void PrintList()
        {
            if(head==NULL)
            {
                cout<<"No nodes in singly linked list exist"<<endl;
            }
            else
            {
                cout<<"Singly Linked list values : "<<endl;
                Node*temp = head;
                while(temp!=NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<")"<<"==>";
                    temp = temp->next;
                }
            }
            
        }
};

int main()
{
  SinglyLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
    //Node n1;
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.AppendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
 
    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.PrependNode(n1);
      break;
 
    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
 
      s.InsertNode(k1, n1);
      break;
 
    case 4:
 
      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNode(k1);
 
      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.UpdateNodebyKey(key1, data1);
 
      break;
    case 6:
      s.PrintList();
 
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}