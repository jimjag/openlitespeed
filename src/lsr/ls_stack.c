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
#include <lsr/ls_stack.h>

#include <lsr/ls_pool.h>


ls_stack_t *ls_stack_new()
{
    ls_stack_t *pThis;
    if ((pThis = (ls_stack_t *)ls_palloc(sizeof(ls_stack_t))) != NULL)
        ls_stack_init(pThis);
    return pThis;
}


void ls_stack_delete(ls_stack_t *pThis)
{
    if (pThis)
    {
        ls_stack_destroy(pThis);
        ls_pfree(pThis);
    }
    return;
}

