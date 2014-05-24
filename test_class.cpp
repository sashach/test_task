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
{
    if(buffer == nullptr)
    {
        buffer_ = nullptr;
        size_ = 0;
    }
    if(buffer != GetBuffer())
    {
        delete buffer_;
        buffer_ = 0;
        buffer_ = new char[size + 1];
        strncpy(buffer_, buffer, size);
        buffer_[size] = '\0';
    }
    else if(size != GetBufferSize())
    {
        char* temporary_buffer = buffer_;
        buffer_ = new char[size + 1];
        strncpy(buffer_, buffer, size);
        buffer_[size] = '\0';
        delete temporary_buffer;
    }
} /* -----  end of method BaseClass::SetBuffer  (sets buffer_ and size_) ---- */

/*
 *------------------------------------------------------------------------------
 *       Class:  StorageClass
 *      Method:  StorageClass
 * Description:  constructor
 *------------------------------------------------------------------------------
 */
//StorageClass::StorageClass ()
//{
//}  /* -----  end of method StorageClass::StorageClass  (constructor)  ----- */

