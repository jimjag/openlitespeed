/*****************************************************************************
*    Open LiteSpeed is an open source HTTP server.                           *
*    Copyright (C) 2013 - 2015  LiteSpeed Technologies, Inc.                 *
*                                                                            *
*    This program is free software: you can redistribute it and/or modify    *
*    it under the terms of the GNU General Public License as published by    *
*    the Free Software Foundation, either version 3 of the License, or       *
*    (at your option) any later version.                                     *
*                                                                            *
*    This program is distributed in the hope that it will be useful,         *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of          *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
*    GNU General Public License for more details.                            *
*                                                                            *
*    You should have received a copy of the GNU General Public License       *
*    along with this program. If not, see http://www.gnu.org/licenses/.      *
*****************************************************************************/
#ifndef FILEAPPENDER_H
#define FILEAPPENDER_H

#include <lsdef.h>
#include <edio/aiooutputstream.h>
#include <log4cxx/appender.h>

#include <stddef.h>
#include <stdarg.h>
#include <sys/types.h>

BEGIN_LOG4CXX_NS

class FileAppender : public Appender
{
protected:
    explicit FileAppender(const char *pName)
        : Appender(pName)
        , m_ino(0)
        , m_stream()
    {}
    Duplicable *dup(const char *pName);
    int open2();
public:
    virtual ~FileAppender() {};
    static int init();

    virtual int open();
    virtual int close();
    virtual int reopenExist();
    virtual int reopenIfNeed();
    virtual int append(const char *pBuf, int len);
    virtual int getfd() const               {   return m_stream.getfd();        }
    void setAsync(int v)                    {   return m_stream.setAsync(v);    }
    int flush()                             {   return m_stream.flush();        }
    AioOutputStream *getStream()            {   return &m_stream;               }

private:
    ino_t           m_ino;
    AioOutputStream m_stream;

    LS_NO_COPY_ASSIGN(FileAppender);
};

END_LOG4CXX_NS


#endif

