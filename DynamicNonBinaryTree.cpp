/*
File Name		: DynamicNonBinaryTree.cpp
Description		: 
Author			: SN
Editor			: Garly Nugraha
Created at		: 22/05/2011
Updated at		: 05/04/2022
*/

#include "DynamicNonBinaryTree.h"

void nbCreate(nbTree *x){
	(*x).root=NULL;
}

nbAddr nbCNode(nbType X){
	nbAddr newNode;
	newNode=(nbAddr) malloc(sizeof(nbTreeNode));
	if (newNode != NULL){
		newNode->fs=NULL;
		newNode->info=X;
		newNode->nb=NULL;
		newNode->parent=NULL;
	}
	return newNode;
}

void nbInsert(nbTree *tRoot, nbAddr parent, nbType X) {
	nbAddr newNode, temp;
	newNode=nbCNode(X);
	
	if (newNode !=NULL) {
		if (parent==NULL) {
			tRoot->root=newNode;
		} else {
			temp=parent;
			
			if (temp->fs != NULL) {
				temp=temp->fs;
				while(temp->nb!=NULL)
					temp=temp->nb;
					temp->nb=newNode;
			} else {
				temp->fs=newNode;
			}
			
			newNode->parent=parent;
		}
	}
}

nbAddr nbSearch(nbAddr root, nbType src){
	nbAddr nSrc;
	
	if (root!=NULL){
		if (root->info==src)
			return root;
		else{
			nSrc=nbSearch(root->fs,src);
			if (nSrc==NULL)
				return nbSearch(root->nb,src);
			else
				return nSrc;
		}
	}
	
	return NULL;
}

void nbUpgrade(nbAddr *root){
	nbAddr temp;
	temp=(*root)->nb;
	
	if ((*root)->fs==NULL) {
		(*root)->fs=temp;
	}
	
	while(temp!=NULL) {
		temp->parent=*root;
		temp=temp->nb;
	}
}

void nbDelete(nbAddr *pDel, nbTree *pTree) {
	nbAddr pCur;
	pCur = *pDel;

	if (pCur == pTree->root && pCur->fs == NULL) {
		pTree->root = NULL;
		return;
	}

	while(pCur->fs!=NULL)
		pCur=pCur->fs;

	while (pCur != *pDel) {
		nbUpgrade(&pCur);
		
		if (pCur->parent!=NULL) {
			pCur->nb=pCur->parent->nb;
		} else {
			pCur->nb=NULL;
		}
		
		pCur=pCur->parent;
	}

	if (pCur->parent!=NULL)
		pCur->parent->fs=pCur->fs;
	if (pCur->fs!=NULL)
		pCur->fs->parent=pCur->parent;
	if (pCur->parent==NULL)
		pTree->root=pCur;
}

int nbDepth(nbAddr root)
{
	int y, z;

	if(root==NULL) {
		return -1;
	}
	
	y=nbDepth(root->fs);
	z=nbDepth(root->nb);
	
	if(y > z) {
		return (y + 1);
	} else {
		return (z + 1);
	}
}

/* ========= Traversal Tree ========== */

void nbPost(nbAddr root){
	if (root!=NULL){
		nbPost(root->fs);
		printf("%d ", root->info);
		nbPost(root->nb);
	}
}

void nbPre(nbAddr root){
	if (root!=NULL){
		printf("%d ", root->info);
		nbPre(root->fs);
		nbPre(root->nb);
	}
}

void nbIn(nbAddr root){
	if (root!=NULL){
		nbIn(root->fs);
		if (root->fs==NULL) {
			printf("%d ", root->info);
		}
		
		if (root->parent !=NULL) {
			if (root->parent->fs==root) {
				printf("%d ", root->parent->info);
			}
		}
			
		nbIn(root->nb);
	}
}

void nbLevelOrder(nbAddr root,int curLevel, int desLevel)
{
	if(root!=NULL)
	{
		if(curLevel==desLevel)
			printf("%d  ",root->info);
		nbLevelOrder(root->fs,curLevel+1,desLevel);
		nbLevelOrder(root->nb,curLevel,desLevel);
	}
}

/* ========== Print Tree ========== */
void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	
	if (node != NULL){
		printf("%s%d\n",tab,node->info);
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}

/* ========== Modul Tambahan ========= */
int Level(nbAddr Root, nbType DataLevel) {
	int CountLevel;
	nbAddr pSearch = nbSearch(Root, DataLevel);
	
	if(pSearch != NULL) {
		CountLevel = 0;
		
		while(pSearch != Root) {
			CountLevel = CountLevel + 1;
			pSearch = pSearch->parent;
		}
		
		return CountLevel;
	}
	
	return -1;
}

void LeafCount(nbAddr Root, int *Leaf) {
	if (Root != NULL) {
		if (Root->fs == NULL) {
			printf("%d ", Root->info);
			*Leaf = *Leaf + 1;
		}
		
		LeafCount(Root->fs, &(*Leaf));
		LeafCount(Root->nb, &(*Leaf));
	}
}

int Degree(nbAddr Root) {
	int Degree = 0;
	
	if(Root == NULL) {
		return Degree;	
	}
	
	if(Root->fs != NULL) {
		Root = Root->fs;
		Degree = 1;
		
		while(Root->nb != NULL) {
			Degree++;
			Root = Root->nb;
		}
		
		return Degree;
	}
	
	return Degree;
}

void Predecessor(nbAddr *pPre, nbTree *pTree) {
	nbAddr Temp;
	Temp = *pPre;
	
	(Temp->parent != NULL) ? Temp = Temp->parent, printf("Predecessor : %d", Temp->info), printf("\n") : printf("Node has no predecessor"), printf("\n");
}

void Successor(nbAddr *psec, nbTree *pTree) {
	nbAddr Temp;
	Temp = *psec;
	
	if(Temp->fs != NULL) {
		Temp = Temp->fs;
		printf("Successor : %d\n", Temp->info);
		
		while(Temp->nb!=NULL) {
			Temp = Temp->nb;
			printf("Successor : %d\n", Temp->info);
		}
	} else {
		printf("Node haven't Sucessor \n");
	}
}

void Ancestor(nbAddr *psec, nbTree *pTree) {
	nbAddr Temp;
	Temp = *psec;
	
	while(Temp->parent != NULL) {
		Temp = Temp->parent;
		
		printf("Ancestor is : %d", Temp->info);
		printf("\n");
	}
}
