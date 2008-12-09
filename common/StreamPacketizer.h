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


#ifndef STREAM_PACKETIZER_H
#define STREAM_PACKETIZER_H

#include "common.h"
#include <queue>

class StreamPacketizer {
public:
	class Packet {
	public:
		Packet();
		Packet(uint32 len);
		~Packet();
		
		Packet *Clone() const;
		uint32 length;
		uint8 *data;
	};
	
	StreamPacketizer();
	~StreamPacketizer();

	void InputBytes(const uint8 *data, uint32 len);	
	Packet *PopPacket();
	
	void ClearBuffers();

protected:
	uint8 *m_partial;
	uint32 m_partialLength;
	uint32 m_payloadLength;
	
	std::queue<Packet *> m_packets;
};



#endif


