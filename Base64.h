/**
 * Base64.h - PuTTYCS BASE64 Encoder/Decoder header
 *
 * This code is based HEAVILY on the code found at:
 * http://www.adp-gmbh.ch/cpp/common/base64.html
 *
 * Copyright (c) 2005 Jason Millard (jsm174@gmail.com)
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
 * 11/05/2005: Initial version                       J. Millard
 */

#if !defined(AFX_BASE64_H__8D695A8F_54ED_4819_AA0E_33ADC00CDF60__INCLUDED_)
#define AFX_BASE64_H__8D695A8F_54ED_4819_AA0E_33ADC00CDF60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBase64  
{
public:
	CBase64();
	virtual ~CBase64();
   
   static CString encode( CString csBuffer );
   static CString decode( CString csBuffer );

protected:
   static CString BASE64_CHARS;
};

#endif // !defined(AFX_BASE64_H__8D695A8F_54ED_4819_AA0E_33ADC00CDF60__INCLUDED_)
