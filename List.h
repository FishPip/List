#pragma once
#include <string>
#include <iostream>

class ListElement {
private:
    std::string data;
    ListElement* previous;
    ListElement* next;
public:
    void set_data(std::string new_data) {
        data = new_data;
    }
    std::string get_data() {
        return data;
    }
    void set_next(ListElement* new_next) {
        next = new_next;
    }
    ListElement* get_next() {
        return next;
    }
    void set_previous(ListElement* new_previous) {
        previous = new_previous;
    }
    ListElement* get_previous() {
        return previous;
    }

    ListElement() {
        previous = NULL;
        next = NULL;
    }

};

class List {
private:
    ListElement* head;
    ListElement* tail;
    int ammount_of_elements = 0;
public:
    ~List() {
        ListElement* current = head;
        while (current != NULL) {
            ListElement* next = current->get_next();
            delete current;
            current = next;
        }
    }
    void push(std::string to_push) {
        ListElement* a = new ListElement();
        a->set_data(to_push);
        a->set_previous(head);
        a->set_next(NULL);

        if (ammount_of_elements == 0)
            tail = a;
        else
            head->set_next(a);

        head = a;
        ammount_of_elements++;
    }
    std::string pop() {
        if (!ammount_of_elements)
            return "NULL";

        std::string data_to_output = head->get_data();
        ListElement* new_head = head->get_previous();
        delete head;
        head = new_head;

        if (head != NULL)
            head->set_next(NULL);
        if (ammount_of_elements == 1)
            tail = NULL;

        ammount_of_elements--;

        return data_to_output;
    }

    void append(std::string to_push) {
        ListElement* a = new ListElement();
        a->set_data(to_push);
        a->set_next(tail);
        a->set_previous(NULL);

        if (ammount_of_elements == 0)
            head = a;
        else
            tail->set_previous(a);

        tail = a;
        ammount_of_elements++;
    }
    std::string remove() {
        if (!ammount_of_elements)
            return "NULL";

        std::string data_to_output = tail->get_data();
        ListElement* new_tail = tail->get_next();
        delete tail;
        tail = new_tail;
        if (tail != NULL)
            tail->set_previous(NULL);

        if (ammount_of_elements == 1)
            head = NULL;

        ammount_of_elements--;

        return data_to_output;
    }
    std::string to_string() {
        ListElement* current = head;
        while (current != NULL) {
            std::cout << current->get_data() << std::endl;
            ListElement* next = current->get_previous();
            current = next;
        }
    }
};
