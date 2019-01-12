//
// Created by admin on 2019/1/12.
//

#ifndef C_DEMO_COPYTEST_H
#define C_DEMO_COPYTEST_H


class CopyTest {
public:
    CopyTest();

    /**
    * 构造
    * @param value
    */
    CopyTest(int);

    /**
     *引用构造
     */
    CopyTest( const CopyTest &);

    int getValue() const;


private:
    int value;
};


#endif //C_DEMO_COPYTEST_H
