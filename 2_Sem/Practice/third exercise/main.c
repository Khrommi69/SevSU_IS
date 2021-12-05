#include <stdio.h>


typedef struct studentMarks {
    float physics;
    float history;
    float maths;
} studentMarks;

typedef struct student {
    int id;
    char[30] lastname;
    studentMarks marks;
} student;

typedef struct node {
    student el;
    node* next;
} node;

typedef struct list {
    node* head;
    int size;
} list;


list* init();
//node* get(list* l, int index);
void push(list* l, student el);
//string marshal(student el);
//student unmarshal(string s);
//node* findById(list* l, int id);


int main()
{
    printf("inicializ pustogo spiska");
    getc(stdin);
    init();

    printf("push 5 raz");
    
    return 0;
}


list* init()
{
    list *l;
    l -> head = NULL;
    l -> size = 0;

    return (l);
}






//
//typedef struct studentMarks {
//    float physics;
//    float history;
//    float maths;
//} studentMarks;
//
//typedef struct student {
//    int id;
//    string lastname;
//    studentMarks marks;
//} student;
//
//typedef struct node {
//    student el;
//    node* next;
//} node;
//
//typedef struct list {
//    node* head;
//    int size;
//} list;
//
//list* init();
//node* get(list* l, int index);
//void push(list* l, student el);
//string marshal(student el);
//student unmarshal(string s);
//node* findById(list* l, int id);
//*/
//
//list* init() {
//
//}
//
//node* get(list* l, int index) {
//    return NULL;
//}
//
//void push(list* l, student el) {
//
//}
//
//string marshal(student el) {
//
//}
//
//student unmarshal(string s) {
//
//}
//
//node* findById(list* l, int id) {
//
//}