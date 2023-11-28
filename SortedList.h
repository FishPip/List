#pragma once
#include "List.h"


class SortedListElement : public ListElement {
private:
    int data = 0;
public:
    void set_data(int new_data) {
        data = new_data;
    }
    int get_data() {
        return data;
    }

    SortedListElement& operator>(SortedListElement&& const other) {
        return data > other.get_data();
    }
};