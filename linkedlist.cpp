#include <iostream>
#include <unordered_map>

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

    void reverse(){
        node *itr = new node;
        int reversecount = 1;
        std::unordered_map<int, int> reversekey;  //we store the position of each node with the value of each node
        itr = head;
        if(count==0){
            std::cout << "Nothing to reverse, list empty.\n";
        }
        else if(count == 1){
            std::cout << head->data << "\n";
        }
        else{
            while(itr != NULL){
                reversekey.insert(std::make_pair(reversecount,itr->data));  
                itr = itr->next;
                reversecount++;
            }
            int i;
            for(i = (reversecount-1); i >0; i--){
                std::cout << reversekey.at(i) << "\n";
            }
        }
    }

};

int main(){
    linkedlist a;
    a.add_to_start(3);
    a.add_to_start(4);
    a.add_to_start(5);
    a.display();
    a.reverse();
    //a.display();
}