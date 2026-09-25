# Security Policy

## Scope and Purpose

The **C Learning & DSA Toolkit** is an educational open-source repository designed for first-year students learning C programming and data structures. It is not intended for high-security production environments.

However, writing safe C code (preventing buffer overflows, null pointer dereferences, memory leaks, and integer overflows) is an essential part of learning software engineering!

## Supported Versions

Only the latest `main` branch of this repository is actively maintained.

| Version | Supported          |
| ------- | ------------------ |
| `main`  | :white_check_mark: |

## Reporting a Vulnerability

If you discover a potential memory safety bug or security vulnerability (such as a buffer overrun in string utilities or memory leak in data structures):

1. **Please do not publish an exploit publicly.**
2. Open a private GitHub security advisory or email the maintainers at `maintainers@example.com` (or create a draft issue marked with the `security` tag).
3. Provide:
   - The file and function name.
   - An example input that triggers the issue.
   - A proposed fix or explanation of the root cause.

We welcome student security researchers and will gladly credit you in our release notes and changelog!
