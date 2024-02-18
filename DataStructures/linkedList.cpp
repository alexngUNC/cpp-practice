#include <stdlib.h>
#include <iostream>

struct Node {
  int data;
  Node* next;
};

Node* head;

void Insert(int x) {
  Node* temp = new Node();
  temp->data = x;
  temp->next = head;
  head = temp;
}

void Print() {
  Node* temp = head;
  while (temp != nullptr) {
    printf("%d", temp->data);
    temp=temp->next;
  }
}
int main() {
  head = nullptr;
  printf("How many numbers?\n");
  int n, i;
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    printf("Enter the number: \n");
    scanf("%d", &x);
    Insert(x);
    Print();
  }
  return 0;
}