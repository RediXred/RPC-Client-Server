# Windows RPC Client-Server Application

## Overview
Windows RPC Client-Server is a **stateful** client-server application implemented in **C/C++**. The server provides access to its file directory using **impersonation**, allowing clients to interact with the file system securely.

## Prerequisites
To establish a connection between the client and server, ensure the following:
1. The **server application** is running.
2. The **client application** provides the necessary authentication details:
   - **Server IP address**
   - **Username** (on the server)
   - **Password** (for authentication)

## Features
Once authentication is successful, the client can execute the following commands:

| Command | Description          |
|---------|----------------------|
| `1`     | Download a file      |
| `2`     | Upload a file        |
| `3`     | Delete a file        |
| `4`     | Show command menu    |
| `5`     | Disconnect from server |

## Installation & Usage

### Server
1. Compile and run the server application:
   ```sh
   serverRPC.exe
   ```
2. Ensure the server is running and accessible on the network.

### Client
1. Compile and run the client application:
   ```sh
   clientRPC.exe
   ```
2. Provide the necessary credentials (server IP, username, and password).
3. Use the available commands to interact with the server.

## Testing
Unit tests are provided in the **unit_tests** folder in **test.cpp** file.

## Security Considerations
- The server uses **impersonation** to execute operations on behalf of the authenticated user.
- Ensure proper network security configurations to protect against unauthorized access.
- It is recommended to use **encrypted communication** (e.g., TLS) to enhance security.

## License
This project is licensed under the MIT License.

## Author
XRediX

