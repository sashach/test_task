/*
 * =============================================================================
 *
 *       Filename:  test_class.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.05.2014 09:07:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alexander Chebotarsky (), sashach@aerotechnica.ua
 *   Organization:  Aerotechnica, Ukraine
 *
 * =============================================================================
 */


/*-----------------------------------------------------------------------------
 *  You can edit this file to complete all test tasks.
 *----------------------------------------------------------------------------*/

#include "test_class.h"
#include <cstring>
#include <limits>
#include <bitset>
#include <algorithm>

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  BaseClass
 * Description:  constructor
 *------------------------------------------------------------------------------
 */
BaseClass::BaseClass ()  
{
    SetS(10);
    SetBuffer(nullptr, 0);
} /* -----  end of method BaseClass::BaseClass  (constructor)  -------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  BaseClass(int32_t s)
 * Description:  constructor that sets s_ to inputed value
 *------------------------------------------------------------------------------
 */
BaseClass::BaseClass(int32_t s)
{
    SetS(s);
    SetBuffer(nullptr, 0);
} /* -----  end of method BaseClass::BaseClass  (constructor that sets s_ to 
   *        inputed value)  ------------------------------------------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  BaseClass(const BaseClass& original)
 * Description:  copy constructor
 *------------------------------------------------------------------------------
 */
BaseClass::BaseClass(const BaseClass& original)
{
    SetS(original.GetS());
    SetBuffer(original.GetBuffer(), original.GetBufferSize());
} /* -----  end of method BaseClass::BaseClass (copy constructor)  ---------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  ~BaseClass()
 * Description:  destructor
 *------------------------------------------------------------------------------
 */
BaseClass::~BaseClass()
{
    delete buffer_;
} /* -----  end of method BaseClass::~BaseClass() (destructor)  ------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  GetS
 * Description:  gets value of s_
 *------------------------------------------------------------------------------
 */
int32_t BaseClass::GetS() const
{
    return s_;
} /* -----  end of method BaseClass::GetS  (gets value of s_)  -------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  GetBufferSize
 * Description:  gets value of size_
 *------------------------------------------------------------------------------
 */
size_t BaseClass::GetBufferSize() const
{
    return size_;
} /* -----  end of method BaseClass::GetBufferSize  (gets value of size_)  -- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  GetBuffer
 * Description:  gets value of pointer buffer_
 *------------------------------------------------------------------------------
 */
const char* BaseClass::GetBuffer() const
{
    return buffer_;
} /* -----  end of method BaseClass::GetBufferSize  (gets value of pointer 
   * -----  buffer_) -------------------------------------------------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  SetS
 * Description:  gets s_
 *------------------------------------------------------------------------------
 */
void BaseClass::SetS(const int32_t s)
{
    s_ = s;
} /* -----  end of method BaseClass::SetS  (sets s_)  ----------------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  SetBuffer
 * Description:  sets buffer_ and size_
 *------------------------------------------------------------------------------
 */
void BaseClass::SetBuffer(const char* buffer, const size_t size)
        throw (std::logic_error)
{
    if(buffer == nullptr && size != 0)
    {
        throw std::logic_error("Buffer is pointer to nullptr, but size is not zero");
    }
    if(buffer != nullptr && size == 0)
    {
        throw std::logic_error("Buffer not is pointer to nullptr, but size is zero");
    }
    if(size >= std::numeric_limits<size_t>::max())
    {
        throw std::logic_error("Size has unacceptable value.");
    }
    if(buffer == nullptr)
    {
        buffer_ = nullptr;
        size_ = 0;
    }
    if(buffer != GetBuffer())
    {
        delete buffer_;
        buffer_ = 0;
        buffer_ = new char[size];
        strncpy(buffer_, buffer, size);
        buffer_[size] = '\0';
        size_ = size;
    }
    else if(size != GetBufferSize())
    {
        char* temporary_buffer = buffer_;
        buffer_ = new char[size];
        strncpy(buffer_, buffer, size);
        buffer_[size] = '\0';
        delete temporary_buffer;
        size_ = size;
    }
} /* -----  end of method BaseClass::SetBuffer  (sets buffer_ and size_) ---- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  SetBitInS
 * Description:  sets bit of s_ with inputed number
 *------------------------------------------------------------------------------
 */
void BaseClass::SetBitInS(const size_t bit_number)
{
    int32_t bit_to_set = 1;
    bit_to_set = bit_to_set << bit_number;
    SetS(GetS() | bit_to_set);
} /* -----  end of method BaseClass::SetBitInS  (sets bit of s_ with 
   *        inputed number) ------------------------------------------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  IsSetBitInS
 * Description:  checks if bit of s_ with inputted number is set
 *------------------------------------------------------------------------------
 */
bool BaseClass::IsSetBitInS(const size_t bit_number) const
{
    return std::bitset<sizeof(GetS())*8>(GetS()).test(bit_number);
} /* -----  end of method BaseClass::IsSetBitInS  (checks if bit of s_ with
   *        inputted number is set) ----------------------------------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  IsEvenS
 * Description:  checks if s_ is even
 *------------------------------------------------------------------------------
 */
bool BaseClass::IsEvenS() const
{
    return GetS() % 2 == 0;
} /* -----  end of method BaseClass::IsEvenS  (checks if s_ is even) -------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  StorageClass
 *      Method:  SetData
 * Description:  sets data_ to data's value
 *------------------------------------------------------------------------------
 */
void StorageClass::SetData(const std::vector<int>& data)
{
    data_ = data;
} /* -----  end of method StorageClass::SetData (sets data_ to data's value)  */

/*
 *------------------------------------------------------------------------------
 *       Class:  StorageClass
 *      Method:  GetDataSize
 * Description:  gets data_'s size
 *------------------------------------------------------------------------------
 */
size_t StorageClass::GetDataSize() const
{
    return data_.size();
} /* -----  end of method StorageClass::GetDataSize (gets data_'s size) ----  */

/*
 *------------------------------------------------------------------------------
 *       Class:  StorageClass
 *      Method:  GetDataAt
 * Description:  gets value of data_'s element
 *------------------------------------------------------------------------------
 */
int StorageClass::GetDataAt(size_t index) const throw (std::logic_error)
{
    if(index >= GetDataSize())
    {
        throw std::logic_error("Index is out of range.");
    }
    return data_.at(index);
} /* -----  end of method StorageClass::GetDataAt (gets value of data_'s 
   *        element) -------------------------------------------------------  */

/*
 *------------------------------------------------------------------------------
 *       Class:  StorageClass
 *      Method:  SortData
 * Description:  sorts data in descending order
 *------------------------------------------------------------------------------
 */
void StorageClass::SortData()
{
    std::sort(data_.begin(), data_.end(), std::greater<int>());
} /* -----  end of method StorageClass::SortData (sorts data in descending 
   *        order) ---------------------------------------------------------  */

/*
 *------------------------------------------------------------------------------
 *       Class:  StorageClass
 *      Method:  FindItemPosition
 * Description:  finds item's value in data_, if found returns it's index, else
 *               returns -1
 *------------------------------------------------------------------------------
 */
size_t StorageClass::FindItemPosition(int item)
{
    std::vector<int>::iterator find_iterator = 
        std::find(data_.begin(), data_.end(), item);
    if(find_iterator == data_.end())
    {
        return -1;
    }
    return find_iterator - data_.begin();
} /* -----  end of method StorageClass::FindItemPosition (find's item's value 
   *        in data_, if found returns it's index, else returns -1) --------  */
