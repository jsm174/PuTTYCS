/**
 * Base64.cpp - PuTTYCS BASE64 Encoder/Decoder
 *
 * This code is based HEAVILY on the code found at:
 * http://www.adp-gmbh.ch/cpp/common/base64.html
 *
 * Copyright (c) 2005 - 2008 Jason Millard (jsm174@gmail.com)
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * REVISION HISTORY:
 *
 * 11/07/2005: Initial version                       J. Millard
 * 11/17/2005: Added UNICODE support                 J. Millard
 */

#include "stdafx.h"
#include "puttycs.h"
#include "Base64.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CString CBase64::BASE64_CHARS =
   _T( "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" );

/**
 * CBase64::encode()
 */

CString CBase64::encode( CString csBuffer )
{
   CString csValue = "";

   TCHAR buffer3[3];
   TCHAR buffer4[4];

   TCHAR* bytes = csBuffer.GetBuffer(0);
   int pos = csBuffer.GetLength();

   int i = 0;
   int j = 0;
 
   while ( pos-- )
   {
      buffer3[i++] = *(bytes++);

      if (i == 3) 
      {
         buffer4[0] = (buffer3[0] & 0xfc) >> 2;

         buffer4[1] =
            ((buffer3[0] & 0x03) << 4) +
            ((buffer3[1] & 0xf0) >> 4);

         buffer4[2] =
            ((buffer3[1] & 0x0f) << 2) +
            ((buffer3[2] & 0xc0) >> 6);

         buffer4[3] = buffer3[2] & 0x3f;

         for( i = 0; (i <4) ; i++ )
         {
            csValue +=
               BASE64_CHARS.GetAt( buffer4[i] );
         }

         i = 0;
      }
   }

   if (i)
   {
      for( j = i; j < 3; j++ )
      {
         buffer3[j] = '\0';
      }

      buffer4[0] =
         (buffer3[0] & 0xfc) >> 2;

      buffer4[1] =
         ((buffer3[0] & 0x03) << 4) + 
         ((buffer3[1] & 0xf0) >> 4);

      buffer4[2] =
         ((buffer3[1] & 0x0f) << 2) + 
         ((buffer3[2] & 0xc0) >> 6);

      buffer4[3] = buffer3[2] & 0x3f;

      for ( j = 0; (j < i + 1); j++ )
      {
         csValue +=
            BASE64_CHARS.GetAt( buffer4[j] );
      }

      while( (i++ < 3) )
      {
         csValue += '=';
      }
   }

   return csValue;
}

/**
 * CBase64::decode()
 */

CString CBase64::decode( CString csBuffer )
{
   CString csValue = "";

   TCHAR buffer4[4];
   TCHAR buffer3[3];

   int pos = csBuffer.GetLength();
   int offset = 0;

   int i = 0;
   int j = 0;

   while ( (pos--) && (
      BASE64_CHARS.Find(csBuffer.GetAt(offset)) != -1) )
   {
      buffer4[i++] =
         csBuffer.GetAt(offset++);

      if ( i == 4 )
      {
         for ( i = 0; i < 4; i++ )
         {
            buffer4[i] =
               BASE64_CHARS.Find( buffer4[i] );
         }

         buffer3[0] =
            (buffer4[0] << 2) +
            ((buffer4[1] & 0x30) >> 4);

         buffer3[1] =
            ((buffer4[1] & 0xf) << 4) +
            ((buffer4[2] & 0x3c) >> 2);

         buffer3[2] =
            ((buffer4[2] & 0x3) << 6) +
            buffer4[3];

         for ( i = 0; (i < 3); i++ )
         {
            csValue += buffer3[i];
         }

         i = 0;
      }
   }

   if (i)
   {
      for ( j = i; j < 4; j++ )
      {
         buffer4[j] = 0;
      }

      for ( j = 0; j < 4; j++ )
      {
         buffer4[j] =
            BASE64_CHARS.Find( buffer4[j]) ;
      }
    
      buffer3[0] =
         (buffer4[0] << 2) + 
         ((buffer4[1] & 0x30) >> 4);

      buffer3[1] =
         ((buffer4[1] & 0xf) << 4) +
         ((buffer4[2] & 0x3c) >> 2);

      buffer3[2] =
         ((buffer4[2] & 0x3) << 6) + 
         buffer4[3];

      for ( j = 0; (j < i - 1); j++ )
      {
         csValue += buffer3[j];
      }
   }

   return csValue;
}
