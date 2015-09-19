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
* Doubly linked list
  * Nodes point backward and forward
* Array list
  * See dynamic array
* Self-organizing list
  * Automatically moves elements that will be accessed frequently toward the head
* Skip list
  * Multiple layers of linked lists
  * Faster traversal at the cost of more space
  * Can be used to implement binary search on a linked list
  * Usually determine which nodes are in higher layers probabilistically
* Unrolled linked list
  * Multple elements in each node, e.g. via array
  * Faster performance due to caching
* VList
  * O(1) access on average, O(log n) worst case
  * O(1) append to front
  * O(1) remove first element
  * O(log n) compute length
  * Immutable
  * Linked list of arrays with geometrically decreasing sizes
* Xor linked list
  * Doubly linked list with saved space
  * XOR next and prev together
  * When traversing, XOR nextprev with the last address
* Doubly connected edge list
  * Represents embedding of planar graph
  * Used in computational geometry
  * Used to represent Voronoi diagrams
* Difference list
  * Contains two lists and represents the difference between them
* Free list
  * Linked list of unallocated blocks
  * O(1) to allocate
  * O(1) to free
  * Poor locality of reference
  * Speed is lost when blocks differ in size

## Trees

### Binary trees

* AA tree
  * Variation on red-black tree
* AVL tree
  * First self-balancing BST
* Binary search tree
  * Binary tree
  * Every node in left subtree is less than parent
  * Every node in right subtree is greater than parent
* Binary tree
  * Each node has at most 2 children
  * Can be stored in array
* Cartesian tree
  * Binary tree derived from sequence of numbers
  * Heap-ordered
  * In-order traversal yields original sequence
  * O(n) construction
* Order statistic tree
  * Self-balancing B-tree
  * O(log n) selection and rank
* Pagoda
  * Priority queue with variant of binary tree
  * Root points to left and right child
  * Other nodes point to parent and leftmost/rightmost descendant leaf
  * Merge/meld operation
* Randomized binary search tree
  * Cartesian tree where each key gets a random priority
  * Heap-ordered by priority, but also satisfies BST property
  * O(log n) average height
* Red-black tree
  * Self-balancing BST
* Rope
  * Leaves are short strings
  * Represents very big string
  * O(log n) selection
  * O(log n) concatenation
  * O(log n) split
  * O(log n) insert
  * O(log n) delete
  * O(j + log n) report (read substring)
  * Many tradeoffs with regular strings
* Scapegoat tree
  * Self-balancing BST
* Self-balancing binary search tree
  * BST that balances itself
* Splay tree
  * Self-adjusting BST
  * Fast access to recently accessed elements
* T-tree
  * BST that stores pointers to other data
* Tango tree
  * Really freaking complicated
  * Multiple trees to give faster searches
  * Worth reading more about later
* Threaded binary tree
  * Each leaf also points to its in-order predecessor or successor (or both)
  * Allows fast traversal
* Top tree
  * Represents subdivision of another tree into clusters
  * Allows divide-and-conquer algorithms
  * Worth reading more about later
* Treap
  * See randomized BST
* Weight-balanced tree
  * Self-balancing BST
  * Each node has a "size" that is the number of nodes below it
  * Useful for order statistic
  * Used in MIT Scheme, SLIB, and implementations of Haskell

### B-trees

* B-tree
  * Binary search tree but not binary
* B+ tree
  * B-tree, where each node has only a key and no value
  * Very large branching factor (but bounded)
  * Additional level at bottom with linked leaves
  * Used in filesystems
* B*-tree
  * B-tree, but different
* Dancing tree
  * Self-balancing binary search tree
  * Balances only when writing to disk
* 2-3 tree
  * Two types of nodes
  * 2-nodes have 1 data element and 2 children
  * 3-nodes have 2 data elements and 3 children
  * Search tree
  * Fast searching and easy insertion
  * Isometry of AA tree
* 2-3-4 tree
  * B-tree of order 4
  * Similar idea to 2-3 tree
  * Isometry of red-black tree
* Queap
  * Doubly linked list and 2-3-4 tree, modified to keep track of min priority
  * All newly inserted items are stored in linked list
  * After a deletion, all items are moved to 2-3-4 tree
  * 2-3-4 tree stores elements in insertion order
* Fusion tree
  * O(log<sub>w</sub> n) search on w-bit integers
  * Faster than traditional BST
  * B-tree with branching factor w<sup>1/5</sup>
* Bx-tree
  * B+ tree-based index structure for moving objects
  * Fast queries and updates

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