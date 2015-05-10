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
void printList();
void insert_node(int val){
    Node *temp;
    Node *current;

    temp=new Node();
    temp->data=val;
    temp->next=NULL;

    if(!head){
        head=temp;
    }

    else{
        for(current=head; current->next; current=current->next);

        temp->next=current->next;
        current->next=temp;
    }

    printf("The value has been successfully inserted in the list!\n");
    printList();
}

void delete_node(int val)
{
    if(!head) {
        printf( "No node available yet.\n" );
        return;
    }

    Node *current, *temp;

    if(val == head->data) {
        temp=head;
        head=head->next;
        free(temp);
    }

    else {
        for(current=head; current->next; current=current->next) {
            if(current->next->data==val)
                break;
        }

        if(!current->next) {
            printf( "Can't Delete!!The value was not found in the list!!\n\n" );
            return;
        }

        temp = current->next;
        current->next=current->next->next;
        free(temp);
    }

    printf( "The node has been deleted!\n" );
    printList();

    return;
}

void find_node(int val){
    if(!head){
        printf("NOT FOUND!!\n\n");
        return;
    }

    Node *current;
    current=head;
    int pos=0, flag=0;

    for(current=head; current->next; current=current->next){
        pos++;
        if(val == current->data){
            flag=1;
            printf("The value %d is FOUND!!!POSITION=%d\n\n", val, pos);
            break;
        }
    }

    if(flag==0){
        printf("NOT FOUND!!\n\n");
    }

    return;
}

void swap_nodes(int node1, int node2) {
    Node *p, *q;
    int pos1=0, pos2=0, f1=0, f2=0;
    for(p=head; p; ) {
        pos1++;
        if(p->data==node1){
            f1=1;
            break;
        }
        if(f1==0)
            p=p->next;
    }

    //if(!p) {
    //    printf( "Can't SWAP!!The value was not found in the list!!\n\n" );
    //    return;
    //}

    for(q=head; q; ) {
        pos2++;
        if(q->data==node2){
            f2=1;
            break;
        }
        if(f2==0)
            q=q->next;
    }

    if(f1==0 || f2==0) {
        printf( "Can't SWAP!!The value was not found in the list!!\n\n" );
        return;
    }

    printf("Node to be swapped p=%d position=%d q=%d position=%d\n", node1, pos1, node2, pos2);
    Node *prevP, *prevQ, *temp;

    if(p != head && q != head) {
        for(prevP=head; prevP->next!=p; prevP=prevP->next);
        for(prevQ=head; prevQ->next!=q; prevQ=prevQ->next);

        prevP->next = q;
        temp=q->next;
        q->next = p->next;
        prevQ->next = p;
        p->next = temp;
    }

    else{
        prevP = prevQ = NULL;
        if(head == p) {
            for(prevQ = head; prevQ->next != q; prevQ = prevQ->next);
            head = q;
            prevQ->next = p;
        }
        else{
            for(prevP = head; prevP->next != p; prevP = prevP->next);
            head = p;
            prevP->next = q;
        }

        temp = q->next;
        q->next = p->next;
        p->next = temp;
    }

    printf("Successfully Swapped!!\n");
    printList();
}


void printList()
{
    Node *current;

    if( !head ) {
        printf( "No node available.\n" );
        return;
    }

    printf( "Here is my linked list:\n" );

    for( current = head; current; current = current->next )
        printf( "%d --> ", current->data );
    printf( "Shesh\n\n" );

    return;
}

int main(){
    freopen("OUTPUT.txt", "w", stdout);
    freopen("Lab2.txt", "r", stdin);

    int x;
    int n;
    scanf("%d", &n);
    while(scanf("%d", &x)!=EOF){
        int val, v;
        if(x!=4){
            cin>>val;
        }

        else{
            cin>>val>>v;
        }

        if(x==1){
            insert_node(val);
            //printList();
        }

        else if(x==2){
            delete_node(val);
        }

        else if(x==3){
            find_node(val);
        }

        else{
            swap_nodes(val, v);
        }
    }
    return 0;
}
