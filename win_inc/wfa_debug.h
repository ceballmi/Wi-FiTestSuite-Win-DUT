/****************************************************************************
*
* Copyright (c) 2014 Wi-Fi Alliance
*
* Permission to use, copy, modify, and/or distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
* SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
* RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
* NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE
* USE OR PERFORMANCE OF THIS SOFTWARE.
*
*****************************************************************************/


#ifndef _WFA_DEBUG_H
#define _WFA_DEBUG_H

//#define WFA_ERR         stderr  /* error: can be redefined to a log file */
//#define WFA_OUT         stdout  /* info:  can be redefined to a log file */
//#define WFA_WNG         stdout  /* warning: can be redefined to a log file */

#define WFA_DEBUG_DEFAULT          0x0001
#define WFA_DEBUG_ERR              0x0001
#define WFA_DEBUG_INFO             0x0002
#define WFA_DEBUG_WARNING          0x0004

#define WFA_DEBUG 1

unsigned short wfa_defined_debug;
FILE* WFA_OUT;
FILE* WFA_ERR;
FILE* WFA_WNG;

#define DPRINT_ERR      fprintf(WFA_ERR, "ERROR: File %s, Line %ld: ", \
	__FILE__, (long)__LINE__); \
	fprintf 

#define DPRINT_INFOL     if(wfa_defined_debug & WFA_DEBUG_INFO) \
	fprintf(WFA_OUT, "DEBUG> File %s, Function %s, Line %ld: ", \
	__FILE__, __FUNCTION__, (long)__LINE__); \
	fprintf

#define DPRINT_INFO     if(wfa_defined_debug & WFA_DEBUG_INFO) \
	fprintf

#define DPRINT_WARNING  if(wfa_defined_debug & WFA_DEBUG_WARNING) \
	fprintf(WFA_WNG, "DEBUG> File %s, Line %ld: ", \
	__FILE__, (long)__LINE__); \
	fprintf


#define WFA_EXIT(x)     DPRINT_INFOL(WFA_OUT, "Exiting ...\n"); \
	exit(x) 
#endif
