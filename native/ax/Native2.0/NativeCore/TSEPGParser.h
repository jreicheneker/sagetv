/*
 * Copyright 2015 The SageTV Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef TS_EPG_PARSER_H
#define TS_EPG_PARSER_H

#include "TSParser.h"

#ifdef __cplusplus
extern "C" {
#endif



typedef struct TS_EPG_PARSER_DUMPER
{
	DUMP  pid_dumper;
	void* pid_dumper_context;

} TS_EPG_PARSER_DUMPER;

typedef struct TS_EPG_PARSER
{
	unsigned long state;
	TS_FILTER* ts_filter;
	TS_EPG_PARSER_DUMPER dumper;

	int stream_format;
	int sub_format;
	
} TS_EPG_PARSER;

TS_EPG_PARSER* CreateTSEPGParser( int nStreamFormat, int nSubFormat );
void ReleaseTSEPGParser( TS_EPG_PARSER *pTSEPGParser );
void ResetTSEPGParser( TS_EPG_PARSER *pTSEPGParser );
void SetupTSEPGParserDump( TS_EPG_PARSER *pTSEPGParser, 
					 DUMP pfnPidDump,   void* pfnPidDumpContext,
					 DUMP pfnEPGDump,	void* pfnEPGDumpContext );
int  StartTSEPGParser( TS_EPG_PARSER *pTSEPGParser );
void StopTSEPGParser( TS_EPG_PARSER *pTSEPGParser );
int  PushTSEPGPacketParser( TS_EPG_PARSER *pTSEPGParser, unsigned char* pData, int nSize );

#ifdef __cplusplus
}
#endif


#endif

