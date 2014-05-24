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
    SetBufferSize(0);
    SetBuffer(nullptr);
}  /* -----  end of method BaseClass::BaseClass  (constructor)  ------------- */

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
void BaseClass::SetS(int32_t s)
{
    s_ = s;
} /* -----  end of method BaseClass::SetS  (sets s_)  ----------------------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  SetBufferSize
 * Description:  sets size_
 *------------------------------------------------------------------------------
 */
void BaseClass::SetBufferSize(size_t size)
{
    size_ = size;
} /* -----  end of method BaseClass::SetBufferSize  (sets size_)  ----------- */

/*
 *------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  SetBuffer
 * Description:  sets buffer_
 *------------------------------------------------------------------------------
 */
void BaseClass::SetBuffer(char* buffer)
{
    buffer_ = buffer;
} /* -----  end of method BaseClass::SetBuffer  (sets buffer_) -------------- */

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

