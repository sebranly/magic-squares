#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDER 19

void initializeMagicSquare(unsigned int magicSquare[][MAX_ORDER], unsigned int magicSquareOrder);
void displayMagicSquare(unsigned int magicSquare[][MAX_ORDER], unsigned int magicSquareOrder);
void adjustPosition(unsigned int *xPosition, unsigned int *yPosition, unsigned int magicSquareOrder);

int main(void)
{
    unsigned int magicSquare[MAX_ORDER][MAX_ORDER];
    unsigned int magicSquareOrder, currentNumber, xPosition, previousXPosition, yPosition, previousYPosition;
    int correctMagicSquareOrder;
    int keepCreating;

    do
    {
        do
        {
            correctMagicSquareOrder = 0;
            printf("Create a magic square of n * n size (n order).\nPlease type the order as a positive odd integer lower than %d: ", MAX_ORDER + 1);
            scanf("%d", &magicSquareOrder);

            if(magicSquareOrder < 0 || magicSquareOrder % 2 == 0 || magicSquareOrder > MAX_ORDER)
                printf("\tThe order you typed is invalid. Please read the instructions once more.\n\n");
            else
                correctMagicSquareOrder = 1;
        } while (!correctMagicSquareOrder);

        initializeMagicSquare(magicSquare, magicSquareOrder);

        currentNumber = 1;
        xPosition = magicSquareOrder / 2;
        yPosition = magicSquareOrder / 2 + 1;
        if (magicSquareOrder == 1)
            magicSquare[0][0] = 1;
        else
            magicSquare[xPosition][yPosition] = currentNumber;

        for (currentNumber = 2 ; currentNumber <= magicSquareOrder * magicSquareOrder ; currentNumber++)
        {
            previousXPosition = xPosition;
            previousYPosition = yPosition;
            xPosition++;
            yPosition++;
            adjustPosition(&xPosition, &yPosition, magicSquareOrder);

            if(magicSquare[xPosition][yPosition] != 0)
            {
                xPosition = previousXPosition;
                yPosition = previousYPosition + 2;
                adjustPosition(&xPosition, &yPosition, magicSquareOrder);
            }

            magicSquare[xPosition][yPosition] = currentNumber;
        }

        displayMagicSquare(magicSquare, magicSquareOrder);

        printf("Do you want to create a new one?\nType 1 if you want to, anything else if you don't want to: ");
        scanf("%d", &keepCreating);
    } while (keepCreating == 1);

    return EXIT_SUCCESS;
}

void initializeMagicSquare(unsigned int magicSquare[][MAX_ORDER], unsigned int magicSquareOrder)
{
    int i = 0, j = 0;
    for(i = 0 ; i < magicSquareOrder ; i++)
        for(j = 0 ; j < magicSquareOrder ; j++)
            magicSquare[i][j] = 0;
}

void displayMagicSquare(unsigned int magicSquare[][MAX_ORDER], unsigned int magicSquareOrder)
{
    int i = 0, j = 0;
    for(j = 0 ; j < magicSquareOrder ; j++)
    {
        for(i = 0 ; i < magicSquareOrder ; i++)
            printf("+---");
        printf("+\n");

        for(i = 0 ; i < magicSquareOrder ; i++)
            printf("|%03d", magicSquare[i][j]);
        printf("|\n");
    }

    for(i = 0 ; i < magicSquareOrder ; i++)
		printf("+---");
    printf("+\n");
}

void adjustPosition(unsigned int *xPosition, unsigned int *yPosition, unsigned int magicSquareOrder)
{
    if(*xPosition >= magicSquareOrder)
        *xPosition -= magicSquareOrder;
    if(*yPosition >= magicSquareOrder)
        *yPosition -= magicSquareOrder;
}
