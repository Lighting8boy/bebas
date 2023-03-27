#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

/*
Nama	: Muhammad Naufal Musyaddad
NIM		: 2602152326
*/

struct node{
    int key;
    char* title;
    char* author;
	char* isbn;
	int page;
    struct node* next;
};

struct node** hash_table;
int size;

void init_hash_table(int table_size){
    size = table_size;
    hash_table = (struct node**) malloc(size * sizeof(struct node*));
    for (int i = 0; i < size; i++){
        hash_table[i] = NULL;
    }
}

int hash_function(int key){
    return key % size;
}

void insert(int key, char* title, char* author, char* isbn, int page){
	
    int index = hash_function(key);
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    new_node->key = key;
    new_node->title = (char*) malloc(strlen(title) + 1);
    strcpy(new_node->title, title);
	new_node->author = (char*) malloc(strlen(author) + 1);
    strcpy(new_node->author, author);
    new_node->isbn = (char*) malloc(strlen(isbn) + 1);
    strcpy(new_node->isbn, isbn);
    new_node->page = page;
    
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
    
    printf("\n\nInput Success\n");
    getch();
    system("cls");
}

void insert2(int key, char* title, char* author, char* isbn, int page){
	
    int index = hash_function(key);
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
    new_node->key = key;
    new_node->title = (char*) malloc(strlen(title) + 1);
    strcpy(new_node->title, title);
	new_node->author = (char*) malloc(strlen(author) + 1);
    strcpy(new_node->author, author);
    new_node->isbn = (char*) malloc(strlen(isbn) + 1);
    strcpy(new_node->isbn, isbn);
    new_node->page = page;
    
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

void hapus(int key){
    int index = hash_function(key);
    char sure[5];
    struct node* current = hash_table[index];
    struct node* previous = NULL;
    while (current != NULL){
        if (current->key == key){
            if (previous == NULL){
                hash_table[index] = current->next;
            }
			else{
                previous->next = current->next;
            }
            printf("\n\n");
            printf("Book key: %d\n", current->key);
			printf("Book Title: %s\n", current->title);
			printf("Book Author: %s\n", current->author);
			printf("Book ISBN: %s\n", current->isbn);
			printf("Book Author: %d\n\n", current->page);
			
			ulanghapus:
			printf("Are you sure to delete this book [y|n]? ");
			scanf("%s", sure);
//			printf("%s\n", sure);
			if(strcmp(sure, "y") == 0){
				free(current->title);
	            free(current);
	            printf("Delete Success!\n\n");
	            system("pause");
	            return;
	        }
	        if(strcmp(sure, "n") == 0){
            	printf("Delete failed!\n\n");
            	system("pause");
				return;
        	}
        	else{
        		goto ulanghapus;
			}
        }
        previous = current;
        current = current->next;
    }
    printf("Key doesn't exist!\n");
    system("pause");
}

// Display the contents of the hash table
void display(){
	printf("----------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Key | Size | Book Title\t\t\t\t\t | Book Author\t\t     | ISBN\t     | Page Number |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++){
        struct node* current = hash_table[i];
        while (current != NULL){
            printf("| %-4d| %-4d | %-50s| %-25s | %-13s | %-11d |\n", i, current->key, current->title, current->author, current->isbn, current->page);
            printf("----------------------------------------------------------------------------------------------------------------------------\n");
            current = current->next;
        }
//        printf("\n");
    }
}

int main(){
    int cho, key, page, ulangnama, ulangauth1, ulangauth2, ulangisbn;
    
    char title[50], author[25], isbn[14];
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    system("cls");
    init_hash_table(size);
    
    insert2(0, "Don't Make me think", "Mr. Krug S.", "9780321344755", 106);
    insert2(1, "Agile Project With Scrum", "Mr. Ken Schwaber", "978073561993", 192);
    insert2(0, "Agile Project me think", "Mr. Krug S.", "9780735619937", 110);
    insert2(5, "Buku 5", "Mr. 5", "9124235624141", 999);
	insert2(2, "Buku 2", "Mr. 2", "9780735619937", 2001);
    insert2(3, "Buku 3 ", "Mr.3", "9729242313123", 299);
    
    
    do{
    	printf("Hash table size = %d\n\n\n", size);
    	
        printf("Bluejack Library\n");
		printf("=================\n\n");
        printf("1. View Book\n");
		printf("2. Insert Book\n");
		printf("3. Remove BOok\n");	
		printf("4. Exit\n\n");
        
        printf(">> ");
        scanf("%d", &cho);
        switch(cho){
            case 1:
                system("cls");
				display();
				getch();
                system("cls");
                break;
    
            case 2:
            	system("cls");
                printf("Enter key [integer]: ");
                scanf("%d", &key);
                
				do{
					printf("Input book title[5-50][unique]: ");
					scanf(" %[^\n]", title);
					ulangnama=0;
					if(strlen(title)>50 || strlen(title)<5){
						ulangnama = 1;
					}
			//		printf("panjang %d\n", strlen(nama));
					//if sama0
					//printf book already exist
				}while(ulangnama==1);
				
				do{
					printf("Input author name[3-25] [Mr. |Mrs. ]:");
					scanf(" %[^\n]", author);
			//		fgets(author, 25, stdin);
			//		author[strcspn(author, "\n")] = '\0';
					ulangauth1=0;
					ulangauth2=1;
					
					if(strlen(author)>25 || strlen(author)<4){
						ulangauth1=1;
					}
					if(strncmp(author,"Mr.",3)==0 || strncmp(author,"Mrs.",4)==0){
						ulangauth2=0;
					}
			//		printf("%d",ulangauth2);
				}while(ulangauth1==1 || ulangauth2==1);
				
				do{
					printf("Input ISBN[10-13][numeric]: ");
					scanf(" %[^\n]", isbn);
					ulangisbn = 0;
					
					int i;
					if(strlen(isbn)>13 || strlen(isbn)<10){
						ulangisbn = 1;
					}
					for(i = 0; isbn[i] != '\0'; i++){
					    if (!isdigit(isbn[i])){
					        ulangisbn = 1; // Not all characters are digits
					        break;
					    }
					}
				}while(ulangisbn == 1);
				
				do{
					printf("Input page number[>=16]: ");
					scanf("%d", &page);	
				}while(page<16);
				
                insert(key, title, author, isbn, page);
//                system("cls");
				break;
                
            case 3:
                system("cls");
				display();
				printf("Enter book key to delete: ");
				scanf("%d", &key);
                hapus(key);
                system("cls");
                break;
            case 4:
                printf("Exit success\n");
                break; 
            default:
                printf("Please choose existing number!\n");
                getch();
                system("cls");
            }
        }while(cho != 4);
    
	free(hash_table);
    return 0;
}        

