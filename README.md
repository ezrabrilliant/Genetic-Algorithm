# Genetic-Algorithm
 Implementations of Genetic Algorithms in Artificial Intelligence for efficient optimization and problem-solving tasks. 

#Soal:
Buatlah sebuah program untuk mencari solusi dari Graph Coloring Problem!
Penjelasan tentang Graph Coloring Problem:
Input dari problem ini adalah sebuah Undirected, Unweighted Graph
Tujuan yang ingin dicapai dalam problem ini adalah untuk memberi “warna” terhadap semua vertex dalam graph, dengan ketentuan:
Setiap pasangan vertex yang adjacent tidak diwarnai dengan warna yang sama
Total jumlah warna yang digunakan sesedikit mungkin
Referensi: https://en.wikipedia.org/wiki/Graph_coloring
Input program:
Input yang diterima program adalah sebuah text file
Isi dari text file input adalah Adjacency List dengan detail sebagai berikut:
Baris pertama berisi 2 angka V dan E, di mana V adalah jumlah vertex pada graph dan E adalah jumlah edge pada graph
E baris berikutnya masing-masing berisi 2 angka vx dan vy, di mana tiap baris melambangkan sebuah edge antara vertex vx dan vertex vy
vx dan vy (nama vertex) berada pada range antara 0 sampai V - 1
Contoh text file input:


Output program:
Output dari program berupa text file
Isi dari text file output adalah sebagai berikut:
Baris pertama berisi 1 angka X yaitu jumlah warna yang digunakan untuk mewarnai graph input
Baris kedua berisi V angka v0 v1 ... vV-1, di mana sebuah angka vi melambangkan warna yang digunakan untuk mewarnai vertex ke-i
vi (warna) berada pada range antara 0 sampai X - 1
Contoh text file output (dari input di atas):
2
0 1 0 0

Artinya:
Jumlah warna yang digunakan: 2
Vertex 0, 2, dan 3 diwarnai dengan warna “0”
Vertex 1 diwarnai dengan warna “1”
Nama text file output: “out_” + [nama text file input]
Misal untuk input file “gc_4_1”, output file diberi nama “out_gc_4_1”
Keterangan tentang program yang dibuat:
Bahasa pemrograman: Bebas
Metode yang disarankan: Genetic Algorithm, Local Search
