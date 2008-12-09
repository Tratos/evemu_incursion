/*  EVEmu: EVE Online Server Emulator

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; version 2 of the License.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY except by those people which sell it, which
  are required to give you total support for your newly bought product;
  without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
	
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#ifndef PACKET_FUNCTIONS_H
#define PACKET_FUNCTIONS_H

#include "types.h"

static const uint8 GZipStreamHeaderByte = 0x78;	// 'x'

int32 roll(int32 in, int8 bits);
int64 roll(int64 in, int8 bits);
int32 rorl(int32 in, int8 bits);
int64 rorl(int64 in, int8 bits);

uint8 *DeflatePacket(const uint8 *data, uint32 *length);						//returns ownership of buffer!
uint8 *InflatePacket(const uint8 *data, uint32 *length, bool quiet = false);	//returns ownership of buffer!

#endif
