#include <iostream>

struct node{
    int data;
    node *next;
};

class linkedlist{
    private:
    node *head;
    node *tail;
    int count = 0;

    public:
    linkedlist(){     //default constructor
        head = NULL;
        tail = NULL;
        std::cout << "Default Constructor called \n";
    }
    linkedlist(const linkedlist &o1);  //copy constructor
    const linkedlist& operator=(const linkedlist &o2);  //assignment operator
    ~linkedlist(){
        std::cout << "Destructor called \n";
    }

    void display(){
        node *itr = new node;
        itr = head;
        while(itr != NULL){
            std::cout << itr->data << "\n";
            itr = itr->next;
        }
        std::cout << "There are " << count << " nodes in the list. \n";
    }

    void add_to_start(int n){   //adding a node to the beginning of the list
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
        if(head == NULL){   //empty list
        head = temp;
        tail = head;
        count++;
    }
    else if(head == tail){ //one item
        head = temp;
        temp->next = tail;
        count++;
    }
    else if(head != NULL && head != tail){   //multiple elements in list
        temp->next = head;   //this assigns tail's next pointer to what head is pointing to
        head = temp;    //this makes head pointer point to what temp is pointing to
        count++;
    }
    }

    void add_to_end(int n){
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        if(head == NULL){    //empty list
            head = temp;
            tail = head;
                count++;
        }
        else if(head == tail){  //only one element
            head->next = temp;  //head next now points to what temp points to
            tail = temp;  //tail pointer now points to what temp points to
            count++;
        }
        else if(head != NULL && head != tail){     //multiple elements in list
            tail->next = temp;
            tail = temp;
            count++;
        }
    }

    void add_at_position(){  //assuming indexing starts at 1
        int pos = 0, i =1, val =0;
        node *temp = new node;
        node *ins = new node;
        std::cout << "Enter the position at which you want to insert the node(indexing starts at 1): ";
        std::cin >> pos;
        if(pos>(count+1) || pos < 1){
            std::cout << "Invalid position.\n";
            std::cout << "Length of list is: " << count << "\n";
        }
        else{
            std::cout << "Enter the value you'd like to insert: ";
            std::cin >> val;
            if(count == 0){   //empty list
                head = temp;  
                tail = head;
                count++;
            }
            else if(count == 1){  //list with one node
                temp = head;
                temp->data = val;
                temp->next = NULL;
                head->next = temp;  //head's next now points to temp, so temp is at 2nd position
                tail = temp;   //tail is updated to temp;
                count++;
            }
            else if(count > 1){  //list with multiple nodes
                temp = head;
                while(i < pos){   //get temp to the position
                    temp = temp->next;
                    i++;
                }
                ins->data = val;
                ins->next = temp;
                temp = ins;
                count++;
            }
        }
    }

    void delete_head(){
        node *temp = new node;
        if(head == NULL)   //empty list
            std:: cout << "List is already empty.\n";
        else if(head == tail){    //only one element
            temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            count --;
        }
        else{  //list has multiple elements
            temp = head;   //temp points to what head is pointing to
            head = head->next;   //head is shifted to its next pointer
            delete temp;    //delete whatever temp is pointing to
            count--;
        }
    }

    void delete_tail(){
        node *temp = new node;
        if(head == NULL)    //list is empty
            std::cout << "List is empty.\n";
        else if(head != NULL && head == tail){   //list has one node
            temp = head;  //temp points to what head points to
            head = NULL;
            tail = head;
            delete temp;  //delete whatever tail points to
            count--;
        }
        else{  //multiple elements
            temp = head;
            while(((temp->next)->next)!=NULL){   //loop stops at 2nd to last node
                temp = temp->next;  
            }
            //std::cout << temp->data << "\n";
            tail = temp;  //tail is now pointing to second to last node
            tail->next = NULL; //otherwise it may point to a garbage value
            temp = temp->next;  //set temp to last node
            delete temp;   //delete the last node
            count--;
        }
    }

};

int main(){
    linkedlist a;
    a.add_to_start(2);
    a.add_to_start(1);
    a.add_to_end(3);
    a.add_to_end(4);
    a.display();
    a.delete_head();
    a.display();
    a.delete_tail();
    a.display();
    a.add_at_position();
    a.display();
    a.add_at_position();
    a.display();
}