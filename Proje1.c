// Bağlı Liste Araya Ekleme


#include <stdio.h>
#include <stdlib.h>
#define function_nodes 20
#define max_nodes 100
struct Node{
    int data;
    struct Node* next; 
};

struct Node* newNode(int newData){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = newData;
    node->next = NULL;
    return node;
}

void displayList(const struct Node* head){
    printf("\nLinked list: ");
    const struct Node* temp = head;
    while (temp){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

void inputMiddle(struct Node **head){
    if (*head == NULL){
        printf("Liste bos, once en az bir dugum ekleyin.\n");
        return;
    }

    int afterValue, newData;
    printf("Hangi degerden sonra eklensin: ");
    scanf("%d", &afterValue);
    printf("Eklenecek veri: ");
    scanf("%d", &newData);

    struct Node* temp = *head;

    // afterValue bulmak için yazdım
    while (temp != NULL && temp->data != afterValue)
        temp = temp->next;

    // bulunamazsa bunu desin
    if (temp == NULL){
        printf("%d degeri listede bulunamadi.\n", afterValue);
        return;
    }

    
    struct Node* n = newNode(newData);
    n->next = temp->next;
    temp->next = n;

    printf("%d degerinden sonra %d eklendi.\n", afterValue, newData);
}

int main(){
    
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(8);
    head->next->next->next->next = newNode(21);
    head->next->next->next->next->next = newNode(27);

    printf("Baslangic listesi:\n");
    displayList(head);

    inputMiddle(&head); 

    printf("\nGuncellenmis liste:\n");
    displayList(head);

    return 0;
}
