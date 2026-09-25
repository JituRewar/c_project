# Getting Started with C Learning & DSA Toolkit

Welcome! This guide will help first-year students set up a C development environment, build the project, run the code, and execute automated tests.

---

## 1. Prerequisites

To build and run this project, you need:
1. A **C compiler** (`gcc` or `clang`)
2. **GNU Make** (`make`)
3. **Git** (for version control)

### Installing on Linux (Ubuntu / Debian / Mint)
Open your terminal and run:
```bash
sudo apt update
sudo apt install build-essential git
```

### Installing on macOS
Open your terminal and run:
```bash
xcode-select --install
```

### Installing on Windows
You can use one of the following recommended setups:
* **WSL (Windows Subsystem for Linux)**: Install Ubuntu from the Microsoft Store, then run the Linux commands above. (Recommended)
* **MSYS2 / MinGW-w64**: Download and install `gcc` and `make`.

---

## 2. Verify Your Installation

Check that your compiler and tools are installed properly:

```bash
gcc --version
make --version
git --version
```

You should see output displaying the version numbers of each tool.

---

## 3. Clone the Repository

Clone the project to your local machine:

```bash
git clone https://github.com/your-username/c-learning-dsa-toolkit.git
cd c-learning-dsa-toolkit
```

---

## 4. Building the Project

We have included a beginner-friendly `Makefile` to automate compilation.

### Compile Everything
```bash
make
```
This builds both the example program (`bin/example`) and the test suite (`bin/test_suite`).

### Run the Example Demonstration
To see all the toolkit functions in action:
```bash
make run
```
Or directly:
```bash
./bin/example
```

### Run the Automated Test Suite
To verify that all functions pass their unit tests:
```bash
make test
```
Or directly:
```bash
./bin/test_suite
```

### Clean Up Build Files
To remove compiled object files and binaries:
```bash
make clean
```

### View Available Targets
```bash
make help
```

---

## 5. Next Steps

* Read [Project Structure](../README.md#project-structure) to understand where each file lives.
* Explore [Algorithms Reference](algorithms.md) for complexity analysis.
* Read [Contributing Guide](../CONTRIBUTING.md) to make your very first open-source contribution!
