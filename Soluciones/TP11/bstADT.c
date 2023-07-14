#include <stdlib.h>
#include "bstADT.h"

#define MAX(v1,v2)  (((v1)>(v2)) ? (v1) : (v2))

// En cada nodo tenemos que tener una referencia al subárbol izquierdo (los menores)
// y al subárbol derecho (los mayores)
typedef struct nodeCDT {
    elemType elem;
    struct nodeCDT * left;
    struct nodeCDT * right;
} nodeCDT;

struct bstCDT {
	nodeCDT * root;	    // raíz del arbol
	size_t size;	    // cantidad de nodos en el árbol
};

bstADT newBst(void) {
	return calloc(1, sizeof(struct bstCDT));
}

void freeNodeRec(nodeCDT * root) {
	if ( root == NULL )
	   return;
	freeNodeRec(root->left);    // liberamos el subárbol izquierdo
	freeNodeRec(root->right);   // liberamos el subárbol derecho
	free(root);                 // liberamos la raíz
}

void freeBst(bstADT bst) {
	freeNodeRec(bst->root);
	free(bst);
}

// Solo como ejercicio, vamos a escribir una función recursiva para calcular la cantidad de nodos
// Esta función no la usaremos ya que tenemos la cantidad calculada en el CDT
static int sizeRec(nodeCDT * root) {
    if ( root == NULL)
	    return 0;
    return 1 + sizeRec(root->left) + sizeRec(root->right);
}


unsigned int size(const bstADT bst) {
	return bst->size;
}

unsigned int heightRec(nodeCDT * root) {
	if ( root == NULL)
		return 0;
	unsigned hL = heightRec(root->left);        // Altura de árbol izquierdo
	unsigned hR = heightRec(root->right);       // Altura de árbol derecho
	return 1 + MAX(hL, hR);
}

unsigned int height(const bstADT bst) {
	return heightRec(bst->root);
}

int belongsRec(const nodeCDT * root, elemType elem) {
	if ( root == NULL)
		return 0;
	int c = compare(root->elem, elem);
	if ( c == 0 )
		return 1;
	if ( c < 0 )
		return belongsRec(root->right, elem);
	return belongsRec(root->left, elem);
}

int belongs(const bstADT bst, elemType elem) {
	return belongsRec(bst->root, elem);
}

nodeCDT * insertRec(nodeCDT * root, elemType elem, int *flag) {
	// Siempre se inserta una nueva hoja. No se insertan nodos "intermedios"
	if ( root==NULL ) {
		nodeCDT * aux = calloc(1, sizeof(nodeCDT));
		aux->elem = elem;
		*flag = 1;
		return aux;
	}
	int c = compare(root->elem, elem);
	if ( c < 0 )
		root->right = insertRec(root->right, elem, flag);
	else if ( c > 0 )
		root->left = insertRec(root->left, elem, flag);
	return root;
		
}

int insert(bstADT bst, elemType elem) {
	int flag = 0;
	bst->root = insertRec(bst->root, elem, &flag);
	bst->size += flag;
	return flag;
}

int inorderRec(const nodeCDT * root, elemType * vec, int idx) {
	if( root == NULL )
		return idx;
	idx = inorderRec(root->left, vec, idx);
	vec[idx++] = root->elem;
	return inorderRec(root->right, vec, idx);
}

// El recorrido inorder es: subárbol izquierdo, raíz, subárbol derecho
elemType * inorder(const bstADT bst) {
     elemType * vec = malloc( bst->size * sizeof(elemType));
     inorderRec(bst->root, vec, 0);
     return vec;
}


