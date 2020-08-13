#ifndef FIELDITEM_H
#define FIELDITEM_H

enum ItemStatus{
    UNSOLVE,
    DETECTED,
    MARKED
};

class FieldItem
{
private:
    /* data */
    bool mine  = false;
    int around = 0;
    enum ItemStatus st = UNSOLVE;

public:
    FieldItem(/* args */);
    virtual ~FieldItem();
    virtual int getShow();
    void init(bool ismine, int nums);
};


#endif /* FIELDITEM_H */