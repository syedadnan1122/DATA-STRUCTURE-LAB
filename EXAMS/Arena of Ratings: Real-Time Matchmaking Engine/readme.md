# Arena of Ratings – BST Implementation (C++)

## 📌 Overview
This project implements a **Binary Search Tree (BST)**–based matchmaking and leaderboard system for a game called **Arena of Ratings**.

Each player is stored in the tree using their **rating as the unique key**.  
All searching, ordering, and ranking operations are performed using BST properties.

This project was developed for a **Data Structures Lab (C++) final exam**.

---

## 🧠 Data Structure Used
- Binary Search Tree (BST)
- Pointer-based dynamic structure
- No STL ordered containers are used

---

## 🧾 Player Information
Each player record contains:
- `rating` (int) – unique key for ordering
- `name` (string)
- `hp` (long long) – health points

---

## ⚙️ Supported Commands

### 🔹 Insertion & Deletion
- `JOIN rating name hp` – insert a new player
- `LEAVE rating` – delete an existing player

### 🔹 Search & Update
- `STATUS rating` – display player information
- `DAMAGE rating amount` – decrease health points
- `HEAL rating amount` – increase health points

### 🔹 Tree Queries
- `NEXT X` – next higher rated player
- `PREV X` – previous lower rated player
- `MATCH X` – closest rating to X
- `RANGE L R` – list players in rating range
- `RANK X` – count of players with rating less than X
- `KTH k` – k-th smallest rated player

### 🔹 Structural Queries
- `DUEL A B` – distance between two players in BST
- `STATS` – display tree statistics

---

## 📐 Tree Properties
- **Height**
  - Empty tree → `-1`
  - Single node → `0`
- **Leaf** → node with no children
- **Duel Distance** → number of edges on BST path

---

## 🚫 Restrictions Followed
- No use of:
  - `std::map`
  - `std::set`
  - `multiset` / `multimap`
- Fully pointer-based BST implementation
- Ordering strictly based on **rating**

---

## 🚀 How to Run

### Compile
```bash
g++ arena.cpp -o arena
