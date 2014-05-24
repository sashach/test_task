/*
 * =====================================================================================
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
 * =====================================================================================
 */


/*-----------------------------------------------------------------------------
 *  You can edit this file to complete all test tasks.
 *-----------------------------------------------------------------------------*/

#include "test_class.h"


/*
 *--------------------------------------------------------------------------------------
 *       Class:  BaseClass
 *      Method:  BaseClass
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
BaseClass::BaseClass ()  
{
}  /* -----  end of method BaseClass::BaseClass  (constructor)  ----- */

int32_t BaseClass::GetS()
{
    return s_;
}
size_t BaseClass::GetBufferSize()
{
    return size_;
}
char* BaseClass::GetBuffer()
{
    return buffer_;
}

void BaseClass::setS(int32_t s)
{
    s_ = s;
}

void BaseClass::setBufferSize(size_t size)
{
    size_ = size;
}

void BaseClass::setBuffer(char* buffer)
{
    buffer_ = buffer;
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  StorageClass
 *      Method:  StorageClass
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
//StorageClass::StorageClass ()
//{
//}  /* -----  end of method StorageClass::StorageClass  (constructor)  ----- */

