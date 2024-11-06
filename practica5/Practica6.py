def max_area(height):
    izq, der = 0, len(height) - 1
    max_area = 0

    while izq < der:
        altura = min(height[izq], height[der])
        ancho = der - izq
        area = altura * ancho
        max_area = max(max_area, area)

        if height[izq] < height[der]:
            izq += 1
        else:
            der -= 1

    return max_area

def main():
    height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    resultado = max_area(height)
    print("La máxima cantidad de agua que se puede contener es:", resultado)

if __name__ == "__main__":
    main()
