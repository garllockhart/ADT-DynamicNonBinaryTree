/*
File Name		: main.cpp
Description		: Program Non Binary tree, dengan tipe dari subvar info pada node-nya adalah integer.
				  Nilai subvar info pada setiap node tidak boleh ada yang sama.
				  Proses delete node hanya bisa dilakukan terhadap leaf / terminal node. 
				  Silakan tambahkan fitur delete lain dengan aturan misalnya Node yang diHapus akan digantikan oleh anak pertama dari node tersebut.
				  
	****Keterangan Print Node****
	tampilan :
	1
	-2
	-3
	--4
	-5
	--8
	--9

	1 merupakan root
	2,3 dan 5 adalah anak dari 1
	4 adalah anak dari 3
	8 dan 9 adalah anak dari 5
	****************************

	*****Keterangan Proses penghapusan ********
	awal :
	1
	-2
	-3
	--4
	-5
	--8
	--9

	bila dilakukan penghapusan node 5 maka akan menjadi
	1
	-2
	-3
	--4
	-8
	--9
	
	
Author			: SN
Editor			: Garly Nugraha
Created at		: 22/05/2011
Updated at		: 05/04/2022
*/

#include <conio.h>
#include "DynamicNonBinaryTree.h"

int main(){
	nbTree pTree;
	nbAddr srcNode;
	nbCreate(&pTree);
	int Menu = 0, newData, parent, i;
	char str[]="";
	
	do{
		system("cls");
		
		printf("<様様様様様様様様様様様様様様様様様様様様様様様様様>\n");
		printf("|1. Insert Node                                    |\n");
		printf("|2. Delete Node                                    |\n");
		printf("|3. Search Node                                    |\n");
		printf("<様様様様様様様様様様様様様様様様様様様様様様様様様>\n");
		printf("|                  Traversal Node                  |\n");
		printf("<様様様様様様様様様様様様様様様様様様様様様様様様様>\n");
		printf("|4. Pre Order                                      |\n");
		printf("|5. Post Order                                     |\n");
		printf("|6. In Order                                       |\n");
		printf("|7. Level Order                                    |\n");
		printf("<様様様様様様様様様様様様様様様様様様様様様様様様様>\n");
		printf("|8. Print Tree                                     |\n");
		printf("<様様様様様様様様様様様様様様様様様様様様様様様様様>\n");
		printf("|9. Level                                          |\n");
		printf("|10. Leaf                                          |\n");
		printf("|11. Dept                                          |\n");
		printf("|12. Degree                                        |\n");
		printf("|13. Predecessor                                   |\n");
		printf("|14. Successor                                     |\n");
		printf("|15. Ancestor                                      |\n");
		printf("<様様様様様様様様様様様様様様様様様様様様様様様様様>\n");
		printf("|16. Exit                                          |\n");
		printf("<様様様様様様様様様様様様様様様様様様様様様様様様様>\n");
		
		printf("\n");
		
		("Select Menu : ");
		fflush(stdin);
		scanf("%d", &Menu);
	
		switch(Menu){
			case 1:
				printf("\n\n");
				printf("Data	: ");
				scanf("%d", &newData);
				
				if (nbSearch(pTree.root, newData)==NULL) {
					if (pTree.root != NULL){
						printf("Parent	: ");
						scanf("%d", &parent);
						
						if ((srcNode = nbSearch(pTree.root, parent)) != NULL) {
							nbInsert(&pTree, srcNode, newData);
						} else {
							printf("ERROR : The parent node is not registered in Tree");
							printf("\n");
							getch();
						}
					} else {
						nbInsert(&pTree, NULL, newData);
					}	
				} else {
					printf("ERROR : The node with the data already exists in the tree");
					printf("\n");
					getch();
				}
				break;
			case 2:
				if (pTree.root == NULL){
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				printf("\n\n");
				printf("Data	: ");
				scanf("%d", &newData);
				
				if ((srcNode = nbSearch(pTree.root, newData)) != NULL) {
					nbDelete(&srcNode, &pTree);
					printf("\n\n");
					printf("Data has been deleted");
					printf("\n");
					
					getch();
				} else {
					printf("ERROR : The node with the data does not exist in Tree");
					printf("\n");
					getch();
				}
				break;
			case 3:
				if (pTree.root == NULL){
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				printf("\n\n");
				printf("Data	: ");
				scanf("%d", &newData);
				
				if ((srcNode=nbSearch(pTree.root, newData)) != NULL) {
					if (srcNode->parent != NULL) {
						printf("Node found");
						printf("\n");
						printf("Node %d child of %d", srcNode->info, srcNode->parent->info);
					} else {
						printf("Node found");
						printf("\n");
						printf("The node is Root");
					}
				} else {
					printf("The node with the data doesn't exist in Tree");
					printf("\n");
				}
				
				getch();
				break;
			case 4:
				if (pTree.root == NULL) {
					printf("Empty Tree");
					getch();
					break;
				}
				
				printf("Pre Order : ");
				nbPre(pTree.root);
				
				getch();
				break;
			case 5:
				if (pTree.root == NULL) {
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				printf("Post Order : ");
				nbPost(pTree.root);
				
				getch();
				break;
			case 6:
				if (pTree.root == NULL) {
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				printf("In Order : ");
				nbIn(pTree.root);
				
				getch();
				break;
			case 7:
				if (pTree.root == NULL) {
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				for(i = 0; i <= nbDepth(pTree.root); i++) {
					nbLevelOrder(pTree.root,0,i);
				}
				
				getch();
				break;
			case 8:
				system("CLS");
				
				if (pTree.root == NULL) {
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				nbPrint(pTree.root,str);
				
				printf("\n\n");
    			printf("Press Any Key to continue . . .");
				
				getch();
				break;
			case 9:
				system("CLS");
				
				if (pTree.root==NULL) {
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				printf("Data	: ");
				scanf("%d", &newData);
				
				if (Level(pTree.root, newData) == -1) {
					printf("\n");
					printf("Node %d is not in Tree", newData);
				} else {
					printf("\n");
					printf("Level : %d", Level(pTree.root, newData));
				}
				
				getch();
				break;
			case 10:
				system("cls");
				
				int	TotalLeaf;
	        	TotalLeaf = 0;
	        	
		  		LeafCount(pTree.root, &TotalLeaf);
		  		
		  		printf("\n");
		  		printf("Total Leaf : %d", TotalLeaf);
		  		
		  		getch();
		  		break;
	        case 11:
	        	system("CLS");
	        	
	        	printf("\n");
	            printf("Tree depth : %d", nbDepth(pTree.root));
	            printf("\n");
	                                   
	            getch();
	            break;
	        case 12:
	        	system("CLS");
	        	
	        	if (pTree.root == NULL){
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				printf("\n");
				printf("Data	: "); 
				scanf("%d", &newData);
				
				if (Degree(nbSearch(pTree.root, newData)) == -1) {
					printf("\n");
					printf("Node %d is not in Tree", newData);
				} else {
					printf("\n");
					printf("Degree: %i", Degree(nbSearch(pTree.root, newData)));
				}
				
				getch();
				break;	
		  	case 13:
				system("CLS");
				
		        if (pTree.root == NULL){
			        printf("Empty Tree");
			        
			        getch();
		        	break;
				}
				
				printf("\n\n");
				printf("Data : "); 
				scanf("%d", &newData);
				
				if ((srcNode=nbSearch(pTree.root, newData)) != NULL){
					Predecessor(&srcNode, &pTree);
				}
				
				getch();
				break;
			case 14:
				system("CLS");
				
				if (pTree.root == NULL){
					printf("Empty Tree");
					
			        getch();
		        	break;
				}
				
				printf("\n");
				printf("Data	: "); 
				scanf("%d", &newData);
				
				if ((srcNode=nbSearch(pTree.root, newData)) != NULL){
					Successor(&srcNode, &pTree);
				}
				
				getch();
				break;
			case 15:
				system("CLS");
				
			  	if (pTree.root == NULL) {
					printf("Empty Tree");
					
					getch();
					break;
				}
				
				printf("\n");
				printf("Data	: "); 
				scanf("%d", &newData);
					
				if ((srcNode=nbSearch(pTree.root, newData)) != NULL){
					Ancestor(&srcNode, &pTree);
				}
					
				getch();
				break;
		}
	}while(Menu != 16);
	
	exit(1);
	return 0;
}
