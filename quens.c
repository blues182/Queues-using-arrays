#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int front, rear;
    int arr[MAX_SIZE];
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("La cola está llena! No se puede encolar.\n");
        return;
    }
    
    if (q->front == -1) {
        q->front = 0;
    }
    
    q->rear++;
    q->arr[q->rear] = value;
    printf("Encolado: %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("La cola está vacía! No se puede desencolar.\n");
        return -1;
    }
    
    int value = q->arr[q->front];
    q->front++;
    
    // Reiniciar la cola si queda vacía
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    
    return value;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("La cola está vacía!\n");
        return;
    }
    
    printf("Contenido actual de la cola: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    char opcion;
    int elemento;
    
    initializeQueue(&q);
    
    printf("Programa de Cola (Tamaño máximo: %d)\n", MAX_SIZE);
    printf("==================================\n");
    
    do {
        printf("\nOpciones:\n");
        printf("e - Encolar (Enqueue)\n");
        printf("d - Desencolar (Dequeue)\n");
        printf("q - Salir\n");
        printf("Ingrese su opción: ");
        scanf(" %c", &opcion);
        
        switch (opcion) {
            case 'e':
            case 'E':
                if (isFull(&q)) {
                    printf("La cola está llena! No se puede encolar.\n");
                } else {
                    printf("Ingrese el elemento a encolar: ");
                    scanf("%d", &elemento);
                    enqueue(&q, elemento);
                }
                display(&q);
                break;
                
            case 'd':
            case 'D':
                if (isEmpty(&q)) {
                    printf("La cola está vacía! No se puede desencolar.\n");
                } else {
                    int desencolado = dequeue(&q);
                    printf("Elemento desencolado: %d\n", desencolado);
                }
                display(&q);
                break;
                
            case 'q':
            case 'Q':
                printf("Saliendo del programa...\n");
                break;
                
            default:
                printf("Opción inválida! Por favor intente nuevamente.\n");
        }
        
    } while (opcion != 'q' && opcion != 'Q');
    
    return 0;
}