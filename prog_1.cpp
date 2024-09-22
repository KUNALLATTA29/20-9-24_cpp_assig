#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    
    node* next;
    node(int data){
        this->data = data;
        next=nullptr;
    }
};

class linkedlist{
    private:
    node* head;
    
    public:
    linkedlist(){
        head = nullptr;
    }
    
    void appendfirst(int value){
        node* newnode = new node(value);
        newnode->next = head;
        head = newnode;
    }
    
    void appendlast(int value){
        node* newnode = new node(value);
        
         if(!head){
            head=newnode;
            return;
        }
        
        node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
    void appendmiddle(int value, int aftervalue){
        node* newnode = new node(value);
        node* temp = head;
        
        while(temp){
            if(temp->data==aftervalue){
                newnode->next = temp->next;
                temp->next = newnode;
                return;
            }
            temp = temp->next;
        }
    }
    
    void appendatposition(int value, int position){
        node* newnode = new node(value);
        
        if(position==0){
            appendfirst(value);
            return;
        }
        
        node* temp = head;
        for(int i = 0; temp && i< position-1; i++){
            temp=temp->next;
        }
        
        newnode->next = temp->next;
        temp->next = newnode;
    }
    
    int length(){
        int count=0;
        node* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    bool search(int value){
        node* temp = head;
        while (temp) {
            if (temp->data == value){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    int countduplicates() {
        unordered_map<int, int> freq;
        node* temp = head;
        while (temp) {
            freq[temp->data]++;
            temp = temp->next;
        }
        int count = 0;
        for (auto& pair : freq) {
            if (pair.second > 1){
                count++;
            }
        }
        return count;
    }
    
    int countunique() {
        unordered_set<int> unique;
        unordered_set<int> duplicate;
        node* temp = head;

        while (temp) {
            if (unique.find(temp->data) == unique.end()) {
                unique.insert(temp->data);
            } else {
                duplicate.insert(temp->data);
            }
            temp = temp->next;
        }
        return unique.size() - duplicate.size();
    }
    
    int index(int value) {
        node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == value){
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }
    
    void removeduplicates() {
        unordered_set<int> seen;
        node* current = head;
        node* prev = nullptr;

        while (current) {
            if (seen.find(current->data) != seen.end()) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                seen.insert(current->data);
                prev = current;
                current = current->next;
            }
        }
    }
    
    void display() {
        node* temp = head;
        while (temp) {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};

int main(){
    
    linkedlist list;
    
    list.appendfirst(1);
    list.appendlast(3);
    list.appendlast(7);
    list.appendfirst(11);
    list.appendlast(6);
    
    list.appendmiddle(20,3);
    list.appendatposition(19,2);
    cout<<list.length();
    cout<<endl;
    
    list.display();

    return 0;
    
}
