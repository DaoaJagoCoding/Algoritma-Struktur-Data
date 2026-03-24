#include <iostream>
#include <string>

using namespace std;
class Node {
    public:
    string sample_name;
    Node *next;
    Node *prev;

    Node (string name){
        sample_name = name;
        next = nullptr;
    }
};

class linked_list{
    Node* head;
    public :
    linked_list (){
        head = nullptr;
    }

    void add_Node (string data);
    void input_Node();
    void remove_Node();
    void run_queue(linked_list &list);
    void last_processed(linked_list &list);
    void display();

};
void linked_list::input_Node(){
    int n;
    string name;
    cout << "Please insert amount of sample : ";
    cin >> n;
    
    if(cin.fail()){
        cout<<"Insert number!\n\n"; 
        cin.clear();
        cin.ignore();
        return;
    }
    cin.ignore();
    
    for (int i = 0;i<n;i++){
        cout << "Please insert sample name "<<i+1<<": ";
        getline(cin,name);
        add_Node(name);
    }
}
void linked_list::add_Node(string data){
    Node* newNode = new Node(data);
    if (head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void linked_list::display(){
    if (head == nullptr){
        cout<<"List is empty\n\n";
        return;
    }
    Node* temp = head;
    cout << "Sample list : \n";
    while (temp != nullptr){
        cout << temp->sample_name << " -> ";
        temp = temp->next;
    }
    cout<<"null\n\n";
}

void linked_list::remove_Node(){
    if (head == nullptr) {
        cout << "List is empty\n\n";
        return;
    }

    int pos = 0;
    Node* temp = head;
    while (temp != nullptr){
        temp = temp->next;
        pos++;
    }

    cout << "Queue length : " << pos << "\n\n";

    int n;
    while (true) {
        cout << "Which position do you want to remove (1-" << pos << ") : ";
        if (cin.fail()) {
            cout << "Please input number\n\n";
            cin.clear();
            cin.ignore();
            continue;
        }
        cin.ignore();

        if (n < 1 or n > pos) {
            cout << "Position out of range, please choose between 1 and " << pos << ".\n\n";
            continue;
        }
        break;
    }

    temp = head;
    Node* prev = nullptr;
    for (int i = 0; i < n-1; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node not found at position " << n << ".\n\n";
        return;
    }

    char answer;
    cout << "Do you want to remove: " << temp->sample_name << " (y/n) : ";
    cin >> answer;
    cin.ignore();

    if (answer != 'y' && answer != 'Y'){
        cout << "Canceled.\n\n";
        return;
    }

    if (prev != nullptr) {
        prev->next = temp->next;
    } else {
        head = temp->next;
    }

    cout << temp->sample_name << " deleted\n\n";
    delete temp;
}
void linked_list::run_queue(linked_list &list){
    int cycle;
    cout << "How many cycles : ";
    cin >> cycle;
    if(cin.fail()){
        cout << "Input number!\n";
        cin.clear();
        cin.ignore();
        return;
    }
    cin.ignore();
    
    for (int i=0;i<cycle;i++){
        if (!head) {
            cout<<"List is empty\n\n"; 
            return;
        }
        Node* to_move = head;
        head = head->next;
        to_move->next = nullptr;

        if (!list.head) {
            list.head = to_move;
        }else {
            Node* temp = list.head;
            while (temp->next) 
            temp = temp->next;
            temp->next = to_move;
            }
        }
}
void linked_list::last_processed(linked_list &list){
    if (!head) {
        cout<<"List is empty\n\n"; 
        return;
    }
    Node* to_move = head;
    head = head->next;
    to_move->next = nullptr;

    if (!list.head) {
            list.head = to_move;
    }else {
            Node* temp = list.head;
            while (temp->next) 
            temp = temp->next;
            temp->next = to_move;
            cout<<"Last Processed Node : "<< temp->sample_name <<"\n\n";
        }

}

void main_menu(){
    int menu;
    linked_list processing;
    linked_list processed;
    do{
        cout << "Welcome, what do you want to do\n"<<
        "1. Input Sample\n"<<
        "2. Remove Sample\n"<<
        "3. Display Sample Queue\n"<<
        "4. Run Test Sampling\n"<<
        "5. Display Processed Sample\n"<<
        "6. Display Last Processed Sample\n"<<
        "7. Exit Program\n\n";
        cin >> menu;
        if(cin.fail()){
            "Input number!";
            cin.clear();
            cin.ignore();
            continue;
        }
        cin.ignore();
    
        switch(menu){
            case 1 :
                processing.input_Node();
                break;
            case 2 :
                processing.remove_Node();
                break;
            case 3 :
                processing.display();
                break;
            case 4 :
                processing.run_queue(processed);
                break;
            case 5 :
                cout<< "Processed";
                processed.display();
                break;
            case 6 :
                processing.last_processed(processed);
                break;
            case 7 :
                cout << "Exiting...";
                break;
            default :
                cout << "Try again...\n";    
        }
    } while(menu!=7);
}  
int main(){
    main_menu();
    return 0;
}  