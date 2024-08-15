def contar_elementos_maiores_que(lista, valor):
    contador = 0
    for elemento in lista:
        if elemento > valor:
            contador += 1
    return contador

# Exemplo de uso
lista = [1, 3, 5, 7, 9, 2, 4, 6, 8, 10]
valor = 5
resultado = contar_elementos_maiores_que(lista, valor)
print(f"Número de elementos maiores que {valor}: {resultado}")
