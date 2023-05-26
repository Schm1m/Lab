// cody by tim, L9Q4
typedef struct numberItem {  // create struct with one value and the same struct again
    int val;
    struct numberItem* next;
} numberItem;

void appendNumberItem(struct numberItem** root, int value) {                             // create number-item at the end
    struct numberItem* newItem = (struct numberItem*)malloc(sizeof(struct numberItem));  // create item and allocate memory
    struct numberItem* last = *root;                                                     // create "last" item to find and store the last item

    newItem->val = value;  // assign value

    if (*root == NULL) {  // if input is NULL make the new item the root
        *root = newItem;
        return;
    }

    while (last->next != NULL) {  // get the last item
        last = last->next;
    }
    last->next = newItem;  // make last item the new item
}

void printList(struct numberItem* inputItem) {  // print all items
    while (inputItem != NULL) {
        printf("%d\n", inputItem->val);  // print item
        inputItem = inputItem->next;     // get next item
    }
}

void clearList(struct numberItem* rootInput) {  // clear all items
    struct numberItem* root = rootInput;        // create temporary items
    struct numberItem* nextItem;                //

    while (root != NULL) {
        nextItem = root->next;  // get next item
        free(root);             // free memory of item
        root = nextItem;        // make item the root
    }
}