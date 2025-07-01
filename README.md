# Duration-Finder

> **Made during CSO-101 lab evaluation**

## Overview

**Duration-Finder** is a C-based command-line utility designed to compute the duration between two time points. Given two time values (in a specified format), the program calculates and displays the elapsed time between them in hours, minutes, and seconds.

---

## Features

- Accepts user input for two time points.
- Computes and displays the duration in HH:MM:SS format.
- Simple command-line interface.

## Use Cases

- **Educational Purposes:** Demonstrate time calculations and C programming concepts.
- **Lab Assignments:** Useful for Computer Science students as a lab evaluation project.
- **Scripting:** Can be used in scripts where duration calculation is needed.

## Installation

### Prerequisites

- GCC or any standard C compiler.
- `make` (optional, for using the included Makefile).

### Steps

1. **Clone the Repository**
   ```bash
   git clone https://github.com/Jayesh-Dev21/Duration-Finder.git
   cd Duration-Finder
   ```

2. **Build the Program**
   - If you have make installed:
     ```bash
     make
     ```
   - Or compile manually:
     ```bash
     gcc -o duration_finder main.c
     ```

## Usage

Run the compiled executable:

```bash
./duration_finder
```

You will be prompted to enter the start and end times. The program will output the duration between the two.

> **Note:** Ensure you follow the time input format as prompted by the program.

## Example

```
Enter start time (HH MM SS): 10 30 00
Enter end time (HH MM SS): 12 45 30
Duration: 2 hours, 15 minutes, 30 seconds
```

## Project Structure

```
.
├── main.c           # Main source code
├── Makefile         # Build instructions
└── README.md        # Project documentation
```

## Contributing

Feel free to fork the repository and submit pull requests for improvements or bug fixes.

## License

This project is for educational use.
