/*
File Name		: DynamicNonBinaryTree.h
Description		: Dynamic Non Binary Tree ADT program specifications
Author			: SN
Editor			: Garly Nugraha
Created at		: 22/05/2011
Updated at		: 05/04/2022
*/

#ifndef DynamicNonBinaryTree_H
#define DynamicNonBinaryTree_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int nbType;
typedef struct TnbTreeNode *nbAddr;

typedef struct TnbTreeNode{
	nbAddr fs;
	nbType info; 
	nbAddr nb;
	nbAddr parent;
}nbTreeNode;

struct nbTree{
	nbAddr root;
};

/* ========== Konstruktor Tree ========== */
void nbCreate(nbTree *x); //Membuat tree kosong (X.root=NULL)

/* ========== Alokasi node baru Tree ========== */
nbAddr nbCNode(nbType X); //Alokasi untuk membuat node baru

/* ========== Operasi-operasi Tree ========== */
void nbInsert(nbTree *tRoot, nbAddr parent, nbType X); // Menambah element pada node parent
nbAddr nbSearch(nbAddr root, nbType src); // Mencari node dengan info ttn dan mengembalikan addressnya
void nbUpgrade(nbAddr *root); // Mengupgrade parent dari beberapa node. (digunakan pada proses penghapusan)
void nbDelete(nbAddr *pDel, nbTree *pTree); // Menghapus node tertentu dan jika node tersebut memiliki child, maka posisinya digantikan oleh fs dari node tsb
int nbDepth(nbAddr root); // Mengukur kedalaman suatu node dari root

/* ========== Traversal Tree ========== */
void nbPost(nbAddr root); // Postorder traversing
void nbPre(nbAddr root); // Preorder traversing
void nbIn(nbAddr root); // Inorder traversing
void nbLevelOrder(nbAddr root,int curLevel, int desLevel); // Levelorder traversing

/* ========== Print Tree ========== */
void nbPrint(nbAddr node, char tab[]); // Boleh diganti dengan : void nbPrint(nbAddr node, char *tab);

/* ========== Modul Tambahan ========== */
int Level(nbAddr Root, nbType DataLevel); // 
void LeafCount(nbAddr Root, int *Leaf); // Menghitung jumlah daun pada data tree
int Degree(nbAddr Root); // Menghitung banyaknya child pada data tree
void Predecessor(nbAddr *pPre, nbTree *pTree); // Menampilkan data parent dari child yang dipilih
void Successor(nbAddr *psec, nbTree *pTree); // Menampilkan data penerus root selanjutnya jika root dihapus pada data tree
void Ancestor(nbAddr *psec, nbTree *pTree); // Menampilkan data leluhur dari child yang dipilih

#endif
