#ifndef STATE_H
#define STATE_H

struct Government {
    int population;
    double GDP;
    char first_letter;
    bool in_war;
    char name[20];
    int type_taxes[3];
};


class State {
   public:
    State();

   private:
};

#endif	// STATE_H
