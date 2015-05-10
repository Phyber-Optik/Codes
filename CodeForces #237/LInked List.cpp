#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;
struct aNode{
    int data;
    aNode *next;
};

typedef aNode Node;
Node *head;
void insert(int val){
    Node *temp;
    Node *current;

    temp=(Node *) malloc(sizeof(Node));
    temp->data=val;
    temp->next=NULL;

    if(!head){
        head=temp;
    }

    else if(val<=head->data){
        temp->next=head;
        head=temp;
    }

    else{
        for(current=head; current->next; current=current->next){
            if(val > current->data && val<= current->next->data){
                break;
            }
        }


        if(!current->next){
            current->next=temp;
        }

        else{
            temp->next=current->next;
            current->next=temp;
        }
    }
}

void printList()
{
    Node *current;

    if( !head ) {
        printf( "No node available.\n" );
        return;
    }

    printf( "Here is the updated list:\n" );

    for( current = head; current; current = current->next )
        printf( "%d --> ", current->data );
    printf( "NULL\n" );

    return;
}

int main(){
    insert(20);

    printList();
}
