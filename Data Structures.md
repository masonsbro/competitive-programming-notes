# Data Structures for Competitive Programming

## Linear data structures

### Arrays

* Array
  * O(1) access
  * O(1) append
  * O(n) insertion
  * Fixed size
  * Very fast
* Bit array
  * An array for bits
* Bit field
  * Small bit array
  * Declared as int, etc.
* Bitboard
  * Store board as bits
  * Used in chess engines
* Circular buffer
  * Buffer where end goes to beginning
  * Used in data stream buffering
* Dynamic array
  * O(1) access
  * Amortized O(1) append
  * Backed by dynamically allocated array
  * Slower than array
* Gap buffer
  * 2 arrays
  * Fast insertion in between (O(1) at end of first array)
  * Used in text editors
* Hashed array tree
  * Array of memory fragments, which store data
  * Improved memory usage patterns
  * Less wasted space in between resizings than dynamic array
  * O(1) access, but slower
  * No hash function
* Lookup table
  * Store computations in a table
  * Only do a computation once
  * Used in population function (count bits in number)
* Matrix
  * 2d array
  * Fast math
* Parallel array
  * Store related information at same index of different arrays
* Sorted array
  * Stores elements in sorted order
  * O(log n) search
* Sparse array
  * Most elements are 0 (or some other value)
  * Implemented with a linked list
* Sparse matrix
  * Same, but in a matrix
* Iliffe vector
  * How Java does 2d arrays
  * Vector of pointers to arrays
  * Supports jagged arrays
* Variable-length array
  * Length determined at runtime
  * Supported in Java and C (GCC)
  * Slow in C
    * Automatically converted to allocation and freeing code

### Lists

* Linked list
  * Each node points to the next one
  * O(n) traversal
  * O(1) insertion at beginning or end
  * O(n) insertion elsewhere
  * 
* Doubly linked list
* Array list
* Self-organizing list
* Skip list
* Unrolled linked list
* VList
* Xor linked list
* Zipper
* Doubly connected edge list
* Difference list
* Free list

## Trees

### Binary trees

* AA tree
* AVL tree
* Binary search tree
* Binary tree
* Cartesian tree
* Order statistic tree
* Pagoda
* Randomized binary search tree
* Red-black tree
* Rope
* Scapegoat tree
* Self-balancing binary search tree
* Splay tree
* T-tree
* Tango tree
* Threaded binary tree
* Top tree
* Treap
* Weight-balanced tree
* Binary data structure

### B-trees

* B-tree
* B+ tree
* B*-tree
* B sharp tree
* Dancing tree
* 2-3 tree
* 2-3-4 tree
* Queap
* Fusion tree
* Bx-tree
* AList

### Heaps

* Heap
* Binary heap
* Weak heap
* Binomial heap
* Fibonacci heap
* AF-heap
* Leonardo Heap
* 2-3 heap
* Soft heap
* Pairing heap
* Leftist heap
* Treap
* Beap
* Skew heap
* Ternary heap
* D-ary heap
* Brodal queue

### Trees

* Trie
* Radix tree
* Suffix tree
* Suffix array
* Compressed suffix array
* FM-index
* Generalised suffix tree
* B-trie
* Judy array
* X-fast trie
* Y-fast trie
* Ctrie

### Multiway trees

* Ternary tree
* K-ary tree
* And–or tree
* (a,b)-tree
* Link/cut tree
* SPQR-tree
* Spaghetti stack
* Disjoint-set data structure
* Fusion tree
* Enfilade
* Exponential tree
* Fenwick tree
* Van Emde Boas tree
* Rose tree

### Space-partitioning trees

* Segment tree
* Interval tree
* Range tree
* Bin
* Kd-tree
* Implicit kd-tree
* Min/max kd-tree
* Adaptive k-d tree
* Quadtree
* Octree
* Linear octree
* Z-order
* UB-tree
* R-tree
* R+ tree
* R* tree
* Hilbert R-tree
* X-tree
* Metric tree
* Cover tree
* M-tree
* VP-tree
* BK-tree
* Bounding interval hierarchy
* BSP tree
* Rapidly exploring random tree

### Application-specific trees

* Abstract syntax tree
* Parse tree
* Decision tree
* Alternating decision tree
* Minimax tree
* Expectiminimax tree
* Finger tree
* Expression tree
* Log-structured merge-tree

## Hashes

* Bloom filter
* Count-Min sketch
* Distributed hash table
* Double Hashing
* Dynamic perfect hash table
* Hash array mapped trie
* Hash list
* Hash table
* Hash tree
* Hash trie
* Koorde
* Prefix hash tree
* Rolling hash
* MinHash
* Quotient filter
* Ctrie

## Graphs

* Graph
* Adjacency list
* Adjacency matrix
* Graph-structured stack
* Scene graph
* Binary decision diagram
* Zero-suppressed decision diagram
* And-inverter graph
* Directed graph
* Directed acyclic graph
* Propositional directed acyclic graph
* Multigraph
* Hypergraph

## Other

* Lightmap
* Winged edge
* Doubly connected edge list
* Quad-edge
* Routing table
* Symbol table