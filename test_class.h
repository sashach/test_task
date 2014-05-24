/*
 * =====================================================================================
 *
 *       Filename:  test_class.h
 *
 *        Version:  1.0
 *        Created:  14.05.2014 09:06:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Chebotarsky (), sashach@aerotechnica.ua
 *   Organization:  Aerotechnica, Ukraine
 *
 * =====================================================================================
 */

#include <cstdint>
#include <cstdio>
using std::size_t;

/*-----------------------------------------------------------------------------
 *  You can edit this file to complete all test tasks.
 *-----------------------------------------------------------------------------*/

/*
 * =====================================================================================
 *        Class:  BaseClass
 *  Description:  
 * =====================================================================================
 */
class BaseClass
{
    int32_t s_;
    char* buffer_;
    size_t size_;
    void SetS(const int32_t s);
    void SetBuffer(const char* buffer, const size_t size);
public:
    BaseClass();
    int32_t GetS() const;
    size_t GetBufferSize() const;
    char* GetBuffer() const;
    
}; /* -----  end of class BaseClass  ----- */


/*
 * =====================================================================================
 *        Class:  StorageClass
 *  Description:  
 * =====================================================================================
 */
class StorageClass
{

}; /* -----  end of class StorageClass  ----- */




/*
 * =====================================================================================
 *        Class:  Interface
 *  Description:  
 * =====================================================================================
 */
class Interface
{
    public:
        virtual void DummyFunction() = 0;
}; /* -----  end of class Interface  ----- */

/*
 * =====================================================================================
 *        Class:  ClassA
 *  Description:  
 * =====================================================================================
 */
class ClassA: public Interface
{
    public:
        int GetSomeIntValue()
        {
            return 222;
        };

        char GetCharA()
        {
            return 'A';
        };

}; /* -----  end of class ClassA  ----- */

/*
 * =====================================================================================
 *        Class:  ClassB
 *  Description:  
 * =====================================================================================
 */
class ClassB
{
    public:

        char GetCharB()
        {
            return 'B';
        };

}; /* -----  end of class ClassB  ----- */

/*
 * =====================================================================================
 *        Class:  ClassC
 *  Description:  
 * =====================================================================================
 */
class ClassC
{

}; /* -----  end of class ClassC  ----- */

/*
 * =====================================================================================
 *        Class:  ClassD
 *  Description:  
 * =====================================================================================
 */
class ClassD
{

}; /* -----  end of class ClassD  ----- */


class Coordinates
{

};

