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


<div align="center">

![Arena of Ratings](assets/arena-banner.svg)

# Arena of Ratings – BST Implementation

**🎮 Elite Matchmaking & Leaderboard System Powered by Binary Search Tree**

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://github.com/yourusername/arena-ratings)
[![BST](https://img.shields.io/badge/Data_Structure-BST-00f3ff?style=for-the-badge)](https://github.com/yourusername/arena-ratings)
[![No STL](https://img.shields.io/badge/No_STL-Pure_Pointers-ff00e5?style=for-the-badge)](https://github.com/yourusername/arena-ratings)

*Developed for Data Structures Lab (C++) Final Exam*

</div>

---

## 📌 Overview

This project implements a **Binary Search Tree (BST)**–based matchmaking and leaderboard system for a game called **Arena of Ratings**.

Each player is stored in the tree using their **rating as the unique key**.  
All searching, ordering, and ranking operations are performed using BST properties.

### ✨ Key Highlights

- 🌳 **Pure BST Implementation** - No STL containers
- ⚡ **O(log n) Average Complexity** - Efficient operations
- 🎯 **15+ Commands** - Complete player management
- 💻 **Pointer-Based** - Dynamic memory management
- ⚔️ **Combat System** - Health, damage, healing

---

## 🧠 Data Structure Used

- Binary Search Tree (BST)
- Pointer-based dynamic structure
- No STL ordered containers used

**Player Node Structure:**
```cpp
struct Player {
    int rating;        // Unique key
    string name;       // Player name
    long long hp;      // Health points
    Player* left;      // Left child
    Player* right;     // Right child
};
```

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

## 📊 Time Complexity

| Operation | Average | Worst Case |
|-----------|---------|------------|
| INSERT    | O(log n) | O(n) |
| DELETE    | O(log n) | O(n) |
| SEARCH    | O(log n) | O(n) |
| SUCCESSOR | O(log n) | O(n) |
| PREDECESSOR | O(log n) | O(n) |

---

## 🚀 How to Run

### Compile
```bash
g++ arena.cpp -o arena
```

### Run
```bash
./arena
```

### Example Session
```
> JOIN 100 Alice 1000
JOINED

> STATUS 100
100 Alice 1000

> DAMAGE 100 200
DAMAGED 800

> STATS
PLAYERS 1
MIN 100
MAX 100
HEIGHT 0
LEAVES 1
```

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

## 👨‍💻 Author

**Your Name**  
Data Structures Lab - Final Exam Project

---

<div align="center">

⭐ **If you found this helpful, please star the repository!** ⭐

</div>
