# Contributing to C Learning & DSA Toolkit

Welcome! We are thrilled that you want to contribute.

This project is built specifically to help **first-year computer science students** learn how open source works in practice. Even if this is your very first Git commit or GitHub pull request, you are in the right place!

---

## The 8 Steps to Your First Contribution

### Step 1 — Fork the Repository
A **fork** is your personal copy of the repository on GitHub.
1. Click the **Fork** button at the top-right corner of this repository on GitHub.
2. Select your personal account.
3. GitHub creates a copy at `https://github.com/<your-username>/c-learning-dsa-toolkit`.

---

### Step 2 — Clone Your Fork
Download your copy of the repository to your local computer:

```bash
# Replace <your-username> with your GitHub handle
git clone https://github.com/<your-username>/c-learning-dsa-toolkit.git
cd c-learning-dsa-toolkit
```

---

### Step 3 — Create a New Branch
A **branch** allows you to work on an isolated feature without affecting the `main` branch.

```bash
# Choose a clear, hyphenated branch name prefixed with fix/ or feature/
git checkout -b fix/binary-search-duplicates
```

> **Why use branches?**
> Working directly on `main` makes it difficult to manage multiple features or undo mistakes. Branches keep your work neat, independent, and easy to review.

---

### Step 4 — Make Your Changes
Open the code in your favorite text editor (VS Code, Vim, CLion, etc.).

* Keep your change **focused on one specific problem or feature**.
* Write clear, readable C code that first-year students can easily understand.
* Follow the project conventions:
  - Put declarations in `include/*.h` with header guards.
  - Put implementations in `src/*.c`.
  - Add doc-comments explaining parameters and return values.

---

### Step 5 — Verify and Test
Never commit code without testing! Run:

```bash
# 1. Check compilation
make clean
make

# 2. Run all automated unit tests
make test

# 3. If you added a new function, add a test in tests/test.c and verify it passes!
```

Ensure there are **zero compiler warnings** (`-Wall -Wextra` is enabled).

---

### Step 6 — Commit Your Changes
A **commit** records a snapshot of your changes.

```bash
# Stage the files you modified
git add src/searching.c tests/test.c

# Commit with a clear, concise description
git commit -m "fix: clarify duplicate handling in binary search"
```

> **Good commit message format:**
> `feat: add array median function`
> `fix: correct stack overflow boundary check`
> `docs: fix typo in algorithms.md`
> `test: add edge cases for palindrome strings`

---

### Step 7 — Push Your Branch to GitHub
Send your committed branch to your fork on GitHub:

```bash
git push -u origin fix/binary-search-duplicates
```

---

### Step 8 — Open a Pull Request (PR)
1. Go to the original repository on GitHub.
2. You will see a banner saying *"Compare & pull request"*. Click it!
3. Fill in the Pull Request template:
   - **What did you change?**
   - **Which issue does this resolve?** (e.g., `Closes #12`)
   - **How did you test your changes?**
4. Click **"Create pull request"**.

---

## What Happens During Code Review?

* A maintainer will read your code and might leave comments or suggestions.
* If changes are requested, simply edit your local file, commit again, and push to the same branch. The pull request will update automatically!
* Once everything looks great, a maintainer will **merge** your PR into the project.
* Congratulations! You are officially an open-source contributor!

---

## Helpful Guidelines for Contributors

* **Keep PRs Small:** Small, focused PRs (50–150 lines) are reviewed and merged much faster than huge PRs.
* **Be Kind and Respectful:** Please read and follow our [Code of Conduct](CODE_OF_CONDUCT.md).
* **Ask Questions:** If you get stuck or aren't sure how to do something, open an issue or ask in the PR comments. We are here to help you learn!
