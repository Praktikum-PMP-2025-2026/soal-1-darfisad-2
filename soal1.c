/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 - Dynamic Array
 *   Hari dan Tanggal    : Selasa, 5 Mei 2026
 *   Nama (NIM)          : Darfis Ahmad Dostriano (13224096)
 *   Nama File           : segel.c
 *   Deskripsi           : Membuat program untuk cek validitas apakah susunan 
segel/Karakter valid hanya huruf kecil dan ()[]{} dianggap sah atau cacat
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* Next;
};

int main() {
    char input[256];
    struct Node* top = NULL;
    int i;
    
    fgets(input, sizeof(input), stdin);
    for (i = 0; input[i] != '\0'; i++) {
        char kurung = input[i];
        if (kurung == '(' || kurung == '[' || kurung == '{') {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = kurung;
            newNode->Next = top;
            top = newNode;
        }
        else if (kurung == ')' || kurung == ']' || kurung == '}') {
            if (top==NULL){
                printf("INVALUD\n");
                return 0;
            }
            char open = top->data;
            struct Node* temp = top;
            top = top->Next;
            free(temp);
            if ((kurung == ')' && open == '(') ||
                (kurung == ']' && open == '[') ||
                (kurung == '}' && open == '{')) {
            } else {
                printf("INVALID\n");
                return 0;
            }
        }
    }

    if (top == NULL) {
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }
    return 0;
}
