 #include<bits/stdc++.h>
 using namespace std;
 typedef long long int LL;
 /*creating a linked list*/ 
 typedef struct Node
 {
    LL data;
    struct Node* next;
 } Node;
 //Inserion in a linked list 
 void push(Node** head_ref,LL tmp){
   Node* abc=(Node*)malloc(sizeof(Node));
   abc->data=tmp;
   abc->next=(*head_ref);
   (*head_ref)=abc;
 }
 void insertafter(Node **prev,LL tmp){
  Node* abc=(Node*)malloc(sizeof(Node));
  abc->data=tmp;
  abc->next=(*prev)->next;
  (*prev)->next=abc;
 }
 void append(Node ** head_ref,LL tmp){
    Node* abc=(Node*)malloc(sizeof(Node));
    abc->data=tmp;
    abc->next=NULL;
    if(*head_ref==NULL){
      *head_ref=abc;
      return;
    }
    Node* last=(* head_ref);
    while((last->next)!=NULL){
      (last)=last->next;
    }
    last->next=abc;
 }
 // Deletion in a linked list(GIVEN KEY)
 void Delete(Node **head_ref,LL key){
   Node * tmp=*head_ref,*prev;
   if(tmp==NULL){
      cout<<"Linked list is Empty\n";
      return;
   }
   if(tmp->data==key){
     (*head_ref)=tmp->next;
     free(tmp);
     return;
   }
   while(tmp!=NULL && tmp->data!=key){
      prev=tmp;
      tmp=tmp->next;
   }
   if(tmp==NULL){
      cout<<"Linked list does not have a node having that key value\n";
      return;
   }
   prev->next=tmp->next;
   free(tmp);
 }
 //DELETION OF A NODE (GIVEN A POSITION)
 void DeleteNode(Node **head_ref,LL pos){
   Node* tmp=*head_ref,*prev;
   for(LL i=1;i<pos-1;++i){
      tmp=tmp->next;
   }
   prev=tmp->next;
   tmp->next=(tmp->next)->next;
   free(prev);
 }
 // printing of Linked list
 void printlink(Node* node){
   if(node==NULL){
      cout<<"Linked list is Empty\n";
      return;
   }
   while(node!=NULL){
     cout<<node->data<<" ";
     node=node->next;
   }
   cout<<"\n";
 }
 // Length of a LINKED list
 void length(Node** head_ref){
  Node *tmp=*head_ref;
  LL a=0;
  while(tmp!=NULL){
    tmp=tmp->next;
    a++;
  }
  cout<<a<<"\n";
 }
 void search(Node** head_ref,LL key){
  Node *tmp=*head_ref;
  while((tmp)!=NULL){
    if(tmp->data==key) {
      cout<<"YES\n";
      return;
    }
    tmp=tmp->next;
  }
  cout<<"NO\n";
 }
 // Delete  whole LINKED list
 void Deletelinkedlist(Node** head_ref){
    Node * curr;
    while((*head_ref)!=NULL){
      curr=(*head_ref);
      (*head_ref)=(*head_ref)->next;
      free(curr);
    }
 }
 //Driver code
 void answer(){
   Node* head = NULL;
   // Insertion in a linked list 
   append(&head, 7);
   push(&head, 8);
   append(&head, 0);
   insertafter(&(head),90);
   insertafter(&((head->next)->next),11);
   printlink(head);
   // Deleting in a linked list 
   Delete(&head,8);
   printlink(head);
   Delete(&head,11);
   printlink(head);
   Delete(&head,90);
   printlink(head);
   Delete(&head,0);
   printlink(head);
   Delete(&head,7);
   printlink(head);
   Delete(&head,90);
   append(&head,88);
   printlink(head);
   append(&head,87);
   printlink(head);
   push(&head,78);
   printlink(head);
   rev(&head);
   printlink(head);
   length(&head);
   DeleteNode(&head,2);
   printlink(head);
   length(&head);
   search(&head,87);
   search(&head,88);
   Deletelinkedlist(&head);
   printlink(head);
 }
int main()
{
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    answer();
    return 0;
}