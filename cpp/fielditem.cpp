#include "FieldItem.h"
#include <cstdio>
#include <string>

FieldItem::FieldItem(/* args */)
{
}

FieldItem::~FieldItem()
{

}

int FieldItem::getShow()
{
    switch (this->st)
    {
    case UNSOLVE:
        printf(" * ");
        break;
    case DETECTED:
        printf(" %d ", this->around);
        break;
    case MARKED:
        printf(" M ");
        break;
    default:
        fprintf(stderr, "error! invalid field status");
        break;
    }
}

void FieldItem::init(bool ismine, int nums)
{
    this->mine = ismine;
    if(!this->mine){
        this->around = nums;
    }
}