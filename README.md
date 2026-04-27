# The Algorithm Hub

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A curated, growing collection of algorithms and implementations across languages and domains. This repository aims to collect clear, tested algorithm implementations, explanations, and complexity notes so learners and contributors can learn, compare, and extend core algorithms.

Released under the MIT License — see `LICENSE`.

Tagline: "Collect, learn, and contribute implementations of algorithms — one hub for clear, tested code across languages."

Call-to-action: Fork this repo, add your language or algorithm, and open a PR — help build the biggest open algorithms collection.

## What this repo is

- A single place to store algorithm implementations (sorting, searching, graphs, DP, numeric methods, etc.).
- Each algorithm should have a clear, commented implementation and (when applicable) a small example or test.
- Language-agnostic: prefer one file/folder per algorithm per language.

## How this repo works

- Add each algorithm as its own file or folder. Name files with the algorithm and language, e.g. `bubblesort.cpp`
- Prefer simple build/run instructions near the top of each file or in a short README in the algorithm's folder.
- Keep implementations readable, documented, and include time/space complexity notes.

## Repository files

Below is a current inventory of files and folders in this repository and a short description of what each does. As the repo grows this list will expand.

Root files:

- [`.DS_Store`](.DS_Store) — macOS Finder metadata file (can be safely ignored or removed; included here because it exists in the working directory).
- [`.gitignore`](.gitignore) — Ignore rules for macOS, common IDEs, build artifacts, and compiled files.
- [`README.md`](README.md) — This file: project description, usage, contribution guide, and file index.
- [`CONTRIBUTING.md`](CONTRIBUTING.md) — Contribution guide and PR checklist.
- [`LICENSE`](LICENSE) — MIT License for the project.
- [`a.out`](a.out) — Compiled executable (likely produced by compiling a C/C++ example). Consider removing or adding to `.gitignore` if not needed.

Algorithm directories:

- [`sorting/`](sorting/) — C++ implementations of sorting algorithms:
    - [`bubblesort.cpp`](sorting/bubblesort.cpp) — Bubble sort implementation with a small example.
    - [`bucketsort.cpp`](sorting/bucketsort.cpp) — Bucket sort implementation.
    - [`countingsort.cpp`](sorting/countingsort.cpp) — Counting sort implementation.
    - [`cyclesort.cpp`](sorting/cyclesort.cpp) — Cycle sort implementation.
    - [`heapsort.cpp`](sorting/heapsort.cpp) — Heap sort implementation.
    - [`insertionsort.cpp`](sorting/insertionsort.cpp) — Insertion sort implementation.
    - [`introsort.cpp`](sorting/introsort.cpp) — Introsort implementation (hybrid quick/heap sort).
    - [`mergesort.cpp`](sorting/mergesort.cpp) — Merge sort implementation.
    - [`pigeonholesort.cpp`](sorting/pigeonholesort.cpp) — Pigeonhole sort implementation.
    - [`quicksort.cpp`](sorting/quicksort.cpp) — Quick sort implementation.
    - [`radixsort.cpp`](sorting/radixsort.cpp) — Radix sort implementation.
    - [`selectionsort.cpp`](sorting/selectionsort.cpp) — Selection sort implementation.
    - [`threewaymergesort.cpp`](sorting/threewaymergesort.cpp) — 3-way merge sort or variant.
    - [`timsort.cpp`](sorting/timsort.cpp) — Timsort implementation (hybrid stable sort used by Python/Java).

- [`searching/`](searching/) — C++ implementations of searching and lookup algorithms:
   - [`avltreesearch.cpp`](searching/avltreesearch.cpp) — Search/lookup using AVL trees.
   - [`b+treesearch.cpp`](searching/b+treesearch.cpp) — B+ tree search operations.
   - [`b-treesearch.cpp`](searching/b-treesearch.cpp) — B-tree search operations.
   - [`binarysearch.cpp`](searching/binarysearch.cpp) — Binary search implementation for sorted arrays.
   - [`binarysearchtree.cpp`](searching/binarysearchtree.cpp) — Binary search tree insert/search/traverse examples.
   - [`breadthfirstsearch.cpp`](searching/breadthfirstsearch.cpp) — BFS graph traversal implementation.
   - [`chainingsearch.cpp`](searching/chainingsearch.cpp) — Hash table chaining example (search in chained buckets).
   - [`depthfirstsearch.cpp`](searching/depthfirstsearch.cpp) — DFS graph traversal implementation.
   - [`exponentialsearch.cpp`](searching/exponentialsearch.cpp) — Exponential search (for unbounded/infinite lists).
   - [`fibonaccisearch.cpp`](searching/fibonaccisearch.cpp) — Fibonacci search implementation.
   - [`hashtablesearch.cpp`](searching/hashtablesearch.cpp) — Hash table lookup examples.
   - [`interpolationsearch.cpp`](searching/interpolationsearch.cpp) — Interpolation search implementation (for uniformly distributed data).
   - [`jumpsearch.cpp`](searching/jumpsearch.cpp) — Jump search implementation.
   - [`linearsearch.cpp`](searching/linearsearch.cpp) — Linear search implementation.
   - [`openaddressingsearch.cpp`](searching/openaddressingsearch.cpp) — Hash table open addressing example.
   - [`redblacktreesearch.cpp`](searching/redblacktreesearch.cpp) — Red-black tree search/insert examples.

- [`pathfinding/`](pathfinding/) — Pathfinding and graph-search algorithms:
   - [`a*search.cpp`](pathfinding/a*search.cpp) — A* search implementation (heuristic-guided shortest path).
   - [`dijkstraalgorithm.cpp`](pathfinding/dijkstraalgorithm.cpp) — Dijkstra's shortest path algorithm.
   - [`greedybestfirstsearch.cpp`](pathfinding/greedybestfirstsearch.cpp) — Greedy Best-First Search implementation.

- [`patternmatching/`](patternmatching/) — String and pattern matching algorithms:
   - [`boyermoore.cpp`](patternmatching/boyermoore.cpp) — Boyer–Moore string search algorithm.
   - [`kmpmatching.cpp`](patternmatching/kmpmatching.cpp) — Knuth–Morris–Pratt algorithm.
   - [`naivestringmatching.cpp`](patternmatching/naivestringmatching.cpp) — Naive string matching (educational example).
   - [`rabinkarpmatching.cpp`](patternmatching/rabinkarpmatching.cpp) — Rabin–Karp rolling-hash search.
   - [`z-algorithm.cpp`](patternmatching/z-algorithm.cpp) — Z-algorithm for pattern matching.

Notes and recommendations:

- Many files are C++ source files (`*.cpp`) implementing standard algorithms; each file should include a short usage example and complexity notes near the top.
- `a.out` is a binary and should typically be removed from the repo or added to `.gitignore` to avoid committing built artifacts.
- There is a duplicate `linearsearch.cpp` in `sorting/` and `searching/`; consider keeping the one in `searching/` and removing/moving the other.
- If you'd like, I can reorganize the repository into language-named folders (`cpp/`, `python/`, etc.) and move these files into a `cpp/` folder to make the layout clearer.

(As the repository grows, this section can be kept up-to-date automatically with a script or CI step that regenerates the inventory.)

## Quick start — run the included C++ example

If you have a C++ compiler installed (g++/clang++), from the repo root run:

```bash
# compile (macOS / zsh)
g++ -std=c++17 -O2 bubblesort.cpp -o bubblesort
# run
./bubblesort
```

Adjust the command for your compiler or project structure.

## Contribution guide — fork, add, and grow

We want this repo to become *the* hub for algorithms. Help us make it big:

1. Fork this repository.
2. Create a branch for your work: `git checkout -b feat/<algorithm>-<language>`.
3. Add your algorithm implementation. Follow these guidelines:
   - Put each algorithm in its own file or folder named clearly.
   - Include a short description, expected input/output, and complexity notes.
   - Add a tiny usage example or test where possible.
   - Keep code style consistent and add comments for clarity.
4. Add or update tests/examples if applicable.
5. Commit with a clear message and open a Pull Request describing your change.

We encourage contributions of all sizes — single-file implementations, improved docs, tests, or language ports.

See `CONTRIBUTING.md` for a short checklist and contribution guidelines.

## Code of conduct & licensing

- By contributing, you agree to follow standard open-source etiquette: be respectful, provide helpful reviews, and write clear PR descriptions.
- Add a `LICENSE` file if you'd like to adopt a specific license (MIT/Apache/CC BY are common choices). If none exists yet, please propose one in a PR.

## Maintainership & roadmap

- Initially community-maintained. Contributors and maintainers will review PRs and help organize algorithms into folders (by topic/language).
- Roadmap ideas: add a `docs/` section with algorithm theory, complexity tables, language index, and curated learning paths.

## Help us grow

Please fork, add algorithms, and send PRs. Share this repo with peers and on social platforms. The more contributors and implementations, the more valuable this hub becomes — let's make it big together!

---

