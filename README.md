# 42_minitalk

The purpose of this project is to code a small data exchange program using UNIX signals.

## How It Works

The program uses UNIX signals (`SIGUSR1` and `SIGUSR2`) to transmit data between a client and a server. Each signal represents a single bit of information:

- `SIGUSR1` represents a binary `0`.
- `SIGUSR2` represents a binary `1`.

### Extracting Bits (Client)

The client processes each character of the message by converting it into its binary representation (8 bits). The bits are extracted from left to right, starting with the most significant bit (MSB). For each bit:

1. If the bit is `0`, the client sends `SIGUSR1`.
2. If the bit is `1`, the client sends `SIGUSR2`.

This ensures that the server receives the bits in the correct order.

### Writing Bits (Server)

The server receives the signals and reconstructs the binary sequence. It processes the bits from right to left, starting with the least significant bit (LSB). For each signal:

1. The server shifts the current byte one position to the left to make space for the new bit.
2. It appends the received bit (`0` for `SIGUSR1`, `1` for `SIGUSR2`) to the rightmost position.

Once 8 bits are collected, the server converts the binary sequence back into a character and appends it to the reconstructed message. This process continues until the entire message is received.
