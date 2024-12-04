#include <stdlib.h>
#include <stdio.h>

typedef struct no No;
typedef struct no {
    int dado;
    No *esquerdo, *direito;
    int altura;
} No;

typedef struct arvore {
    No* raiz;
} Arvore;

int ObterAltura(No *no) {
    if(no == NULL) {
        return -1;
    }
    return no->altura;
}

int CalculaBalanceamento(No *no) {
    if(no == NULL) {
        return 0;
    }
    return ObterAltura(no->esquerdo) - ObterAltura(no->direito);
}

void AtualizaAltura(No *no) {
    if(no == NULL) {
        return;
    }
    int alturaEsquerda = ObterAltura(no->esquerdo);
    int alturaDireita = ObterAltura(no->direito);
    no->altura = (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

No* RotacaoSimplesEsquerda(No* no) {
    No* novoRaiz = no->direito;
    no->direito = novoRaiz->esquerdo;
    novoRaiz->esquerdo = no;
    
    AtualizaAltura(no);
    AtualizaAltura(novoRaiz);
    
    return novoRaiz;
}

No* RotacaoSimplesDireita(No* no) {
    No* novoRaiz = no->esquerdo;
    no->esquerdo = novoRaiz->direito;
    novoRaiz->direito = no;
    
    AtualizaAltura(no);
    AtualizaAltura(novoRaiz);
    
    return novoRaiz;
}

No* BalanceamentoNo(No *no) {
    int fatorBalanceamento = CalculaBalanceamento(no);
    
    if(fatorBalanceamento > 1) {
        if(CalculaBalanceamento(no->esquerdo) < 0) {
            no->esquerdo = RotacaoSimplesEsquerda(no->esquerdo);
        }
        return RotacaoSimplesDireita(no);
    }
    
    if(fatorBalanceamento < -1) {
        if(CalculaBalanceamento(no->direito) > 0) {
            no->direito = RotacaoSimplesDireita(no->direito);
        }
        return RotacaoSimplesEsquerda(no);
    }
    
    return no;
}

int BuscarRecursao(No* no, int valor) {
    if (no == NULL) {
        return 0; // N�o encontrou
    }

    if (no->dado == valor) {
        return 1; // Encontrou
    } else if (valor < no->dado) {
        return BuscarRecursao(no->esquerdo, valor);
    } else {
        return BuscarRecursao(no->direito, valor);
    }
}

int Buscar(Arvore* arvore, int valor){
    return BuscarRecursao(arvore->raiz, valor);
}

No* CriarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro de aloca��o de mem�ria\n");
        return NULL;
    }
    novoNo->dado = dado;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    novoNo->altura = 0;
    return novoNo;
}

Arvore* CriarArvore(int raiz) {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    if (!arvore) {
        printf("Erro de aloca��o de mem�ria\n");
        return NULL;
    }
    
    arvore->raiz = CriarNo(raiz);
    return arvore;
}

No* InserirNoRecursao(No* no, int valor) {
    if (no == NULL) {
        return CriarNo(valor);
    }

    if (valor < no->dado) {
        no->esquerdo = InserirNoRecursao(no->esquerdo, valor);
    } else if (valor > no->dado) {
        no->direito = InserirNoRecursao(no->direito, valor);
    }
    
    AtualizaAltura(no);
    return BalanceamentoNo(no);
}

void Inserir(Arvore* arvore, int valor) {
    arvore->raiz = InserirNoRecursao(arvore->raiz, valor);
}

void PrintPreOrderRecursao(No* no) {
    if(no == NULL) {
        return;
    }
    
    printf("%d ", no->dado);
    PrintPreOrderRecursao(no->esquerdo);
    PrintPreOrderRecursao(no->direito);
}

void PrintPreOrder(Arvore* arvore){
    PrintPreOrderRecursao(arvore->raiz);
    printf("\n");
}

void PrintInOrderRecursao(No* no) {
    if(no == NULL) {
        return;
    }
    
    PrintInOrderRecursao(no->esquerdo);
    printf("%d ", no->dado);
    PrintInOrderRecursao(no->direito);
}

void PrintInOrder(Arvore* arvore){
    PrintInOrderRecursao(arvore->raiz);
    printf("\n");
}

void PrintPostOrderRecursao(No* no) {
    if(no == NULL) {
        return;
    }
    
    PrintPostOrderRecursao(no->esquerdo);
    PrintPostOrderRecursao(no->direito);
    printf("%d ", no->dado);
}

void PrintPostOrder(Arvore* arvore){
    PrintPostOrderRecursao(arvore->raiz);
    printf("\n");
}

void LiberaMemoriaNo(No* no) {
    if(no == NULL) {
        return;
    }
    
    LiberaMemoriaNo(no->esquerdo);
    LiberaMemoriaNo(no->direito);
    free(no);
}

void LiberarMemoria(Arvore* arvore){
    LiberaMemoriaNo(arvore->raiz);
    free(arvore);
}

int main() {
    Arvore* minhaArvore = CriarArvore(10);
    Inserir(minhaArvore, 11);
    Inserir(minhaArvore, 12);
    Inserir(minhaArvore, 13);
    Inserir(minhaArvore, 8);
    Inserir(minhaArvore, 2);
    Inserir(minhaArvore, 1);
    Inserir(minhaArvore, 22);
    Inserir(minhaArvore, 80);
    Inserir(minhaArvore, 100);

    printf("PreOrder: ");
    PrintPreOrder(minhaArvore);

    printf("InOrder: ");
    PrintInOrder(minhaArvore);

    printf("PostOrder: ");
    PrintPostOrder(minhaArvore);

    if (Buscar(minhaArvore, 7)) {
        printf("Valor 7 encontrado na �rvore!\n");
    } else {
        printf("Valor 7 n�o encontrado na �rvore!\n");
    }

    LiberarMemoria(minhaArvore);
    return 0;
}

