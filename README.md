# Unit Test Local Communication

This repository contains projects related to local communication testing, including HTTP and Socket-UDP for ESP32.

## Project Structure

```
.
├── .vscode                 # Visual Studio Code configuration files
├── HTTP
│   ├── ESP-AsyncWebServer  # HTTP server using ESP AsyncWebServer library
│   │   ├── .vscode         # Visual Studio Code configuration files
│   │   └── simple_server   # Simple server project
│   ├── ESP32-client        # HTTP client for ESP32
│   └── ESP32-wifi          # Wi-Fi related project for ESP32
│       ├── .vscode         # Visual Studio Code configuration files
│       └── main            # Main Wi-Fi project
└── Socket-UDP
    └── ESP32-socket-UDP-client  # UDP client project for ESP32
```

## Project Descriptions

### HTTP
- **ESP-AsyncWebServer:** Project utilizing the ESP AsyncWebServer library for implementing an HTTP server.
  - **simple_server:** Simple server project.

- **ESP32-client:** HTTP client project for ESP32.

- **ESP32-wifi:** Project related to Wi-Fi functionality for ESP32.

### Socket-UDP
- **ESP32-socket-UDP-client:** UDP client project for ESP32.

## Usage

Please refer to the respective subdirectories for detailed usage instructions for each project.

## Contributing

Feel free to contribute to this project by opening issues or submitting pull requests.

## License

This project is licensed under the [MIT License](LICENSE).

---
