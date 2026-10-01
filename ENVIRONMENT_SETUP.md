# Environment Setup & Verification Guide

This document records the environment setup required for the project, following the provided workshop guide.

## 1. Tooling & Runtime Installation

### Node.js and npm

Install the LTS version of Node.js and ensure Node is added to the system PATH.

Verify:

```bash
node -v
npm -v
```

Expected versions from the guide: Node.js v20.x.x or v22.x.x and npm 10.x.x.

### Git

Install Git for your operating system.

Verify:

```bash
git --version
```

Expected output: Git version 2.x.x.

### GitHub CLI

Install GitHub CLI (`gh`).

Windows:

```powershell
winget install GitHub.cli
```

macOS:

```bash
brew install gh
```

Verify:

```bash
gh --version
```

Expected output: gh version 2.x.x.

## 2. GitHub Identity & Authentication

Prepare the GitHub account by verifying the email address and enabling Two-Factor Authentication (2FA).

Configure Git identity:

```bash
git config --global user.name "Your Full Name"
git config --global user.email "you@example.com"
```

Verify:

```bash
git config --global user.name
git config --global user.email
```

Authenticate the local machine with GitHub:

```bash
gh auth login
gh auth status
```

During `gh auth login`, select GitHub.com, choose HTTPS (or SSH if already configured), allow Git authentication, and authenticate through the web browser.

## 3. Project Environment

The provided guide also documents Vite + React + Tailwind CSS scaffolding for a portfolio environment:

```bash
npm create vite@latest portfolio -- --template react
cd portfolio
npm install
npm install -D tailwindcss postcss autoprefixer
npx tailwindcss init -p
npm run dev
```

The expected Vite development URL is:

```text
http://localhost:5173
```

Expected generated configuration files include:

- `tailwind.config.js`
- `postcss.config.js`
- `package.json`
- `vite.config.js`

## 4. Git Repository Setup

For a new local project, initialize Git:

```bash
git init
git branch -M main
git remote add origin https://github.com/<your-username>/portfolio.git
git push -u origin main
```

The project should use a `.gitignore` containing at least:

```text
node_modules/
dist/
.env
.env.local
```

This prevents dependencies, build output, and local environment secrets from being tracked.

## 5. Line Editor Project

The current repository is a C command-line line editor. Its normal build environment uses GCC rather than the Vite/React stack.

Compile:

```bash
gcc line_editor.c -o line_editor
```

Run on Windows PowerShell:

```powershell
.\line_editor.exe
```

Run on macOS/Linux:

```bash
./line_editor
```

## 6. Verification Checklist

- [ ] Node.js installed and `node -v` works
- [ ] npm installed and `npm -v` works
- [ ] Git installed and `git --version` works
- [ ] GitHub CLI installed and `gh --version` works
- [ ] GitHub email verified
- [ ] 2FA enabled
- [ ] Git username and email configured
- [ ] `gh auth login` completed
- [ ] `gh auth status` confirms authentication
- [ ] `.gitignore` excludes local secrets and build/dependency directories
- [ ] GCC can compile `line_editor.c`
- [ ] The line editor executable runs successfully

## Source

This setup follows the supplied Environment Setup & Verification Guide. The guide specifies Node.js/npm, Git, GitHub CLI, Git identity, GitHub authentication, project scaffolding, `.gitignore`, repository initialization, and verification commands.