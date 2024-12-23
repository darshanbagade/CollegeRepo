//DARSHAN BAGADE
//Project -Insertion & Deletion of Elements in an Array
#include<stdio.h>
int arr[10]={11,22,33,44,55,66};
int current_index=5;
void display_array();

//---Insert Element at end----
void insert_end(int element){
    if(current_index== (sizeof(arr)/sizeof(int)) - 1){
        printf("---Array is full--\n");
        return;
    }
    current_index++;
    arr[current_index]=element;
    printf("Element is inserted at the end\n");
    display_array();
}

//---Insert Element at Start----
void insert_start(int element){
    if(current_index==( sizeof(arr)/sizeof(int)) -1 ){
        printf("---Array is full--\n");
        return;
    }
    for(int i=current_index ;i>=0 ; i--){
        arr[i+1]=arr[i];
    }
    arr[0]=element;
    current_index++;
    printf("Element is inserted at the start\n");
    display_array();
}

//----Insert element at any index----
void insert_anyIndex(int element ,int index){
    if(current_index==(sizeof(arr)/sizeof(int)) -1){
        printf("---Array is full--\n");
        return;
    }
    for(int i=current_index ;i>=index ; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    current_index++;
    printf("Element is inserted at %d index\n",index);
    display_array();}

//----Delete element at last index----
void delete_end(){
    if(current_index==-1){
        printf("--Array is Empty--\n");
    }
    current_index--;
    printf("\nElement at last index is deleted\n");
    display_array();
}

//----Delete element at start index----
void delete_start(){
    if(current_index==-1){
        printf("--Array is Empty--\n");
    }
    for(int i=0;i<current_index;i++){
        arr[i]=arr[i+1];
    }
    current_index--;
    printf("Element at the begining of array is deleted\n");
    display_array();}

//----Delete element at any index----
void delete_anyIndex(int index){
    if(current_index==-1){
        printf("--Array is Empty--\n");
    }
    for(int i=index;i<current_index;i++){
        arr[i]=arr[i+1];
    }
    current_index--;
    printf("Element at the %d index is deleted\n",index);
    display_array();
}

//----Display of Array----
void display_array(){
    for(int i=0;i<=current_index ; i++){
        printf("%d ",arr[i]);
    }
        printf("\n");
}

int main() {
    int element;
    int index;
    int choice;
    printf("Available elements in array\n");
    display_array();
    while (1) {
        printf("\nChoose your choice: \n");
        printf("1. Insert at end \n2. Insert at start\n3. Insert at any index\n");
        printf("4. Delete at end \n5. Delete at start\n6. Delete at any index\n");
        printf("7. Display array\n8. Quit\t:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &element);
                insert_end(element);
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &element);
                insert_start(element);
                break;
            case 3:
                printf("Enter the element: ");
                scanf("%d", &element);
                printf("Enter the index: ");
                scanf("%d", &index);
                insert_anyIndex(element, index);
                break;
            case 4:
                delete_end();
                break;
            case 5:
                delete_start();
                break;
            case 6:
                printf("Enter the index: ");
                scanf("%d", &index);
                delete_anyIndex(index);
                break;
            case 7:
                display_array();
                break;
            case 8:
                printf("Quit\n");
                exit(0);
            default:
                printf("Invalid Input\n");
                break;
        }
    }
    return 0;
}
