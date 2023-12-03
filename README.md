# My_Teams 📨

![Teams](https://img.shields.io/badge/Microsoft_Teams-6264A7?style=for-the-badge&logo=microsoft-teams&logoColor=white)

Welcome to **My_Teams**.

A Network Programming project aimed at creating both a server and a CLI (Command Line Interface) client for a collaborative communication application akin to Microsoft Teams.

## Language and Tools 🛠️

![C Language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

- **Language:** C
- **Compilation:** Via Makefile, including `re`, `clean`, and `fclean` rules.
- **Binary Names:** myteams_server, myteams_cli

## Project Overview 🔎

The goal of my Teams is to implement a server and client model for a communication application.

This involves developing a custom protocol, managing multiple client connections, handling command requests, and ensuring secure and efficient communication.

### Server Features

- **Multi-Client Management:** Handle multiple clients simultaneously using `select` for command management.
- **Data Persistence:** Automatically save internal information to `save.txt` upon shutdown and restore it on startup from the same file.
- **Custom Protocol:** Implement a protocol as per RFC’s style documentation.
- **Security:** Implement basic security features like user authentication and access controls.

### CLI Client Features

- **User Commands:** Support for commands like `/login`, `/logout`, `/users`, `/subscribe`, and more.
- **Interactive Communication:** Enable personal messaging, team channels, and thread discussions.
- **Contextual Actions:** Allow users to create, list, and view teams, channels, threads, and comments based on the context.

## Data Management

- **Data Saving:** The server automatically saves all internal data to a file named `save.txt` upon shutdown.
- **Data Loading:** Upon startup, the server checks for the existence of `save.txt` and loads data from it if available, ensuring data persistence across sessions.

## Installation and Usage 💾

### Running the Server

1. **Compile the Server and Client:**
   - Navigate to the root directory of the project.
   - Run `make` to compile both `myteams_server` and `myteams_cli`.

2. **Start the Server:**
   - Execute `./myteams_server <port>` to start the server.
   - Replace `<port>` with the desired port number for the server to listen on.

3. **Start the Client:**
   - Execute `./myteams_cli <ip> <port>` to start the client.
   - Replace `<ip>` with the server's IP address and `<port>` with the port number used to start the server.

### Using the Application

- On the client side, input commands as per the features and functionalities provided.
- Use the `/help` command for guidance on available commands and their usage.

For detailed guidelines, refer to `myteams.pdf`.

## License ⚖️

This project is released under the MIT License. See `LICENSE` for more details.
