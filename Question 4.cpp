#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};
void insert(Node** first,int input){
    Node* new_node = new Node();

    new_node->data = input;

    new_node->next = (*first);

    (*first) = new_node;
}
void selectionSort(Node** first)
{
    Node* i,*j;
    for (i = *first; i!=nullptr; i=i->next)
    {
        Node* miny = i;
        for (j = i->next; j!=nullptr ; j=j->next){
        if (j->data < miny->data)
            miny = j;

        }
        if(miny!=i)
        {
            int temp;
            temp = miny->data;
            miny->data = i->data;
            i->data = temp;
        };
    }
}
void print(Node *node)
{
    while (node != nullptr)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}


int main(){
    Node* head = nullptr;
	int num[10] = {2,4,4,0,1,0,5,7,8,5};
	for(int i = 9; i > -1; i--) {
        insert(&head,num[i]);
    }
    print(head);
    selectionSort(&head);
    cout<< "\n\n";
    print(head);

}
