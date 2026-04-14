# 🔍 Inverted Search

An efficient full-text search system implemented in **C**, using **Hash Tables** and **Linked Lists** to map words to their locations across multiple files. This project simulates how modern search engines index and retrieve documents at high speed.

---

## 📌 Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Data Structures Used](#data-structures-used)
- [How It Works](#how-it-works)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Sample Output](#sample-output)
- [Contributing](#contributing)
- [License](#license)

---

## 📖 About the Project

**Inverted Search** builds an *inverted index* — a data structure that maps each unique word found across a set of documents to the list of files in which it appears. Instead of scanning every file on every search query, the system looks up the pre-built index to return results instantly.

This is the foundational technique used by search engines like Google and indexing systems like Elasticsearch.

---

## ✨ Features

- 📂 **Multi-file Indexing** — Index multiple files in one go
- ⚡ **Fast Search** — O(1) average lookup using hash tables
- 🗂️ **Inverted Index** — Maps words → files, not files → words
- 💾 **Save & Load Index** — Persist the index to disk and reload it
- 🔁 **Update Index** — Add new files to an existing index without rebuilding
- 🧹 **Display Index** — View the complete word-to-file mapping

---

## 🧱 Data Structures Used

| Structure | Purpose |
|---|---|
| **Hash Table** | O(1) lookup for words in the index |
| **Singly Linked List** | Stores the list of files per word |
| **Double Linked List** | Maintains the list of all indexed files |

---

## ⚙️ How It Works

```
Documents → Tokenize Words → Hash Each Word → Store in Index
                                                     ↓
Query Word → Hash Lookup → Return List of Files Containing Word
```

1. **Create Database** — Read files from the system and tokenize words
2. **Build Index** — Each word is hashed; files are appended to its linked list
3. **Search** — A query word is hashed, and the linked list of matching files is returned
4. **Save/Load** — The index is serialized to a file for persistence across sessions

---

## 📁 Project Structure

```
invertedsearch/
│
├── main.c              # Entry point and menu-driven interface
├── index.c             # Core indexing logic
├── index.h             # Header file for index structures and functions
├── hash.c              # Hash table implementation
├── hash.h              # Hash table header
├── linkedlist.c        # Linked list operations
├── linkedlist.h        # Linked list header
├── fileops.c           # File I/O for save/load
├── fileops.h           # File operations header
├── database/           # Sample text files for indexing
│   ├── file1.txt
│   ├── file2.txt
│   └── file3.txt
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Linux / Unix environment (or WSL on Windows)

### Installation

```bash
# Clone the repository
git clone https://github.com/nayakawadesajid111-hue/invertedsearch.git

# Navigate to the project directory
cd invertedsearch

# Compile the project
gcc -o invertedsearch main.c index.c hash.c linkedlist.c fileops.c

# Run the program
./invertedsearch
```

---

## 🖥️ Usage

Once running, you will see a menu like:

```
============================
   INVERTED SEARCH SYSTEM
============================
1. Create Database
2. Display Database
3. Search Word
4. Save Database
5. Load Database
6. Update Database
7. Exit
============================
Enter your choice:
```

| Option | Description |
|---|---|
| **Create Database** | Index all files in the `database/` directory |
| **Display Database** | Print the full inverted index |
| **Search Word** | Enter a word and get the list of files containing it |
| **Save Database** | Write the index to a `.dat` file |
| **Load Database** | Read a previously saved index from disk |
| **Update Database** | Add new files to the existing index |

---

## 📋 Sample Output

```
Enter word to search: hello

Word "hello" found in:
  -> file1.txt
  -> file3.txt

Total files: 2
```

---

## 🤝 Contributing

Contributions are welcome! To contribute:

1. Fork the repository
2. Create a new branch (`git checkout -b feature/your-feature`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to the branch (`git push origin feature/your-feature`)
5. Open a Pull Request

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

## 👤 Author

**Sajid Nayakawade**  
GitHub: [@nayakawadesajid111-hue](https://github.com/nayakawadesajid111-hue)
