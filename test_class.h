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
#include <stdexcept>
using std::size_t;
#include <vector>

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
public:
    BaseClass();
    BaseClass(int32_t s);
    BaseClass(const BaseClass& original);
    ~BaseClass();
    int32_t GetS() const;
    size_t GetBufferSize() const;
    const char* GetBuffer() const;
    void SetBuffer(const char* buffer, const size_t size) 
            throw (std::logic_error);
    void SetS(const int32_t s);
    void SetBitInS(const size_t bit_number);
    bool IsSetBitInS(const size_t bit_number) const;
    bool IsEvenS() const;
}; /* -----  end of class BaseClass  ----- */


/*
 * =====================================================================================
 *        Class:  StorageClass
 *  Description:  
 * =====================================================================================
 */
class StorageClass
{
    std::vector<int> data_;
public:
    void SetData(const std::vector<int> &data);
    size_t GetDataSize() const;
    int GetDataAt(size_t index) const throw (std::logic_error);
    void SortData();
    size_t FindItemPosition(int item);
}; /* -----  end of class StorageClass  ----- */


namespace MyNamespace
{
}

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
        virtual int GetSomeIntValue() = 0;
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
        void DummyFunction()
        {
        }
        
        int GetSomeIntValue()
        {
            return 222;
        };

        char GetCharA()
        {
            return 'A';
        }

}; /* -----  end of class ClassA  ----- */

/*
 * =====================================================================================
 *        Class:  ClassB
 *  Description:  
 * =====================================================================================
 */
class ClassB: public ClassA
{
    public:
        char GetCharB()
        {
            return 'B';
        }
        
        int GetSomeIntValue()
        {
            return 333;
        }

}; /* -----  end of class ClassB  ----- */

/*
 * =====================================================================================
 *        Class:  ClassC
 *  Description:  
 * =====================================================================================
 */
class ClassC: public ClassB
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

