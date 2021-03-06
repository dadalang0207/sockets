/*
 * PackageLicenseDeclared: Apache-2.0
 * Copyright (c) 2015 ARM Limited
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
#ifndef __MBED_NET_SOCKETS_V0_TCP_ASYNCH__
#define __MBED_NET_SOCKETS_V0_TCP_ASYNCH__

#include "Socket.h"
#include "sal/socket_api.h"

#include "minar/minar.h"

namespace mbed {
namespace Sockets {
namespace v0 {
class TCPAsynch: public Socket {
protected:
    TCPAsynch(const socket_stack_t stack);
    ~TCPAsynch();

public:

   /**
     * Open the socket.
     * Instantiates and initializes the underlying socket. Receive is started immediately after
     * the socket is opened.
     * @param[in] af Address family (SOCKET_AF_INET4 or SOCKET_AF_INET6), currently only IPv4 is supported
     * @retval SOCKET_ERROR_NONE on success
     * @retval SOCKET_ERROR_BAD_STACK if there is no valid underlying network stack
     * @retval SOCKET_ERROR_BAD_FAMILY if an invalid Address is supplied
     * @return Error code on failure
     */
    virtual socket_error_t open(const socket_address_family_t af);

protected:
    static minar::callback_handle_t _tick_handle;
    // uintptr_t is used to guarantee that there will always be a large enough
    // counter to avoid overflows. Memory allocation will always fail before
    // counter overflow if the counter is the same size as the pointer type and
    // sizeof(TCPAsynch) > 0
    static uintptr_t _TCPSockets;
private:
    socket_error_t open(const socket_address_family_t af, const socket_proto_family_t pf);
};
} // namespace v0
} // namespace Sockets
} // namespace mbed
#endif // __MBED_NET_SOCKETS_V0_TCP_ASYNCH__
