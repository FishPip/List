#pragma once
#include "List.h"

class GeoreneteListElement : public ListElement {
private:
    int index;

public:
    void set_index(int nex_index) {
        index = nex_index;
    }
    int get_index() {
        return index;
    }

    GeoreneteListElement(int new_index) {
        index = new_index;
    }

};

class GeoreneteList : public List {
private:
    GeoreneteListElement* head;
    GeoreneteListElement* tail;
    int ammount_of_elements = 0;

public:
    ~GeoreneteList() {
        GeoreneteListElement* current = head;
        while (current != NULL) {
            GeoreneteListElement* next = reinterpret_cast<GeoreneteListElement*>(current->get_next());
            delete current;
            current = next;
        }
    }
    void push(std::string to_push) {
        GeoreneteListElement* a = new GeoreneteListElement(0);
        a->set_data(to_push);
        a->set_previous(head);
        a->set_next(NULL);

        if (ammount_of_elements == 0)
            tail = a;
        else
            head->set_next(a);

        head = a;
        ammount_of_elements++;

        change_indexes();
    }

    void change_indexes() {
        GeoreneteListElement* current = head;
        int current_index = 0;
        while (current != NULL) {
            current->set_index(current_index);
            GeoreneteListElement* next = reinterpret_cast<GeoreneteListElement*>(current->get_previous());
            current = next;
        }
    }

    std::string pop() {
        if (!ammount_of_elements)
            return "NULL";

        std::string data_to_output = head->get_data();
        GeoreneteListElement* new_head = reinterpret_cast<GeoreneteListElement*>(head->get_previous());
        delete head;
        head = new_head;

        if (head != NULL)
            head->set_next(NULL);
        if (ammount_of_elements == 1)
            tail = NULL;

        ammount_of_elements--;
        change_indexes();

        return data_to_output;
    }

    void append(std::string to_push) {
        GeoreneteListElement* a = new GeoreneteListElement(ammount_of_elements);
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
        GeoreneteListElement* new_tail = reinterpret_cast<GeoreneteListElement*>(tail->get_next());
        delete tail;
        tail = new_tail;
        if (tail != NULL)
            tail->set_previous(NULL);

        if (ammount_of_elements == 1)
            head = NULL;

        ammount_of_elements--;

        return data_to_output;
    }

    void add_at_index(std::string to_push, int index) {
        GeoreneteListElement* current = head;
        for (int i = 0; i < index; i++) {
            current = reinterpret_cast<GeoreneteListElement*>(current->get_previous());
            if (current == NULL)
                break;
        }

        if (current == NULL)
            append(to_push);
        else {
            GeoreneteListElement* a = new GeoreneteListElement(index);
            a->set_data(to_push);
            a->set_next(current->get_next());
            a->set_previous(current);

            current->get_next()->set_previous(a);
            current->set_next(a);

            ammount_of_elements++;

            change_indexes();
        }
    }

    std::string remove_at_index(int index) {
        GeoreneteListElement* current = head;
        for (int i = 0; i < index; i++) {
            current = reinterpret_cast<GeoreneteListElement*>(current->get_previous());
            if (current == NULL)
                break;
        }

        if (current == NULL)
            return remove();
        else {
            GeoreneteListElement* previous = reinterpret_cast<GeoreneteListElement*>(current->get_previous());
            GeoreneteListElement* next = reinterpret_cast<GeoreneteListElement*>(current->get_next());
            if (previous == NULL)
                return remove();
            else if (next == NULL)
                return pop();
            else {
                current->get_previous()->set_next(current->get_next());
                current->get_next()->set_previous(current->get_previous());
                std::string data_to_output = current->get_data();

                delete current;
                change_indexes();
                return data_to_output;
            }

        }
    }

    std::string to_string() {
        GeoreneteListElement* current = head;
        while (current != NULL) {
            std::cout << current->get_data() << std::endl;
            GeoreneteListElement* next = reinterpret_cast<GeoreneteListElement*>(current->get_previous());
            current = next;
        }

        return "";
    }
};

