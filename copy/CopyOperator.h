//
// Created by admin on 2019/1/12.
//

#ifndef C_DEMO_COPYOPERATOR_H
#define C_DEMO_COPYOPERATOR_H


class CopyOperator {
public:
   CopyOperator &operator=(const CopyOperator& );

    int getSize() const;

    CopyOperator(int size);

private:
    int size;
};


#endif //C_DEMO_COPYOPERATOR_H
