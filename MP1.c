#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void displayProd(int orderType, int ID)
{
    if (orderType == 1)
    {
        switch (ID)
        {
        case 1:
            printf("Chicken");
            break;
        case 2:
            printf("Pork");
            break;
        case 3:
            printf("Fish");
            break;
        case 4:
            printf("Beef");
            break;
        default:
            break;
        }
    }
    else if (orderType == 2)
    {
        switch (ID)
        {
        case 1:
            printf("Steamed Rice");
            break;
        case 2:
            printf("Shredded Corn");
            break;
        case 3:
            printf("Mashed Potatoes");
            break;
        case 4:
            printf("Steam Vegetables");
            break;
        default:
            break;
        }
    }
    else if (orderType == 3)
    {
        switch (ID)
        {
        case 1:
            printf("Mineral Water");
            break;
        case 2:
            printf("Iced Tea");
            break;
        case 3:
            printf("Soda");
            break;
        case 4:
            printf("Fruit Juice");
            break;
        default:
            break;
        }
    }
}
void orderF(int *meal, int *side, int *drink, int *orderCount)
{
    char resp;
    do
    {
        printf("Order %d: \n", *orderCount);
        printf("     Mea1:  ");
        scanf("%d", meal);
        printf("           ");
        displayProd(1, *meal);
        printf("\n");
        printf("     Side:  ");
        scanf("%d", side);
        printf("           ");
        displayProd(2, *side);
        printf("\n");
        printf("     Drink: ");
        scanf("%d", drink);
        printf("           ");
        displayProd(3, *drink);
        printf("\n");
        printf("Is this meal set order correct (Y/N)? ");
        scanf(" %c", &resp);
    } while (resp != 'Y');
    *orderCount = *orderCount + 1;
}
float checkout(int orderCount, int meal, int side, int drink, int motd[])
{
    int priceIndex[3][4] = {
        {90, 105, 120, 135},
        {20, 35, 50, 65},
        {25, 35, 45, 55}};

    printf("\nOrder %d\n", orderCount);
    printf("Main:     ");
    displayProd(1, meal);
    printf("             P%d.00\n", priceIndex[0][meal - 1]);
    printf("Side:     ");
    displayProd(2, side);
    printf("             P%d.00\n", priceIndex[1][side - 1]);
    printf("Drink:    ");
    displayProd(3, drink);
    printf("             P%d.00\n", priceIndex[2][drink - 1]);
    float subTotal = priceIndex[0][meal - 1] + priceIndex[1][side - 1] + priceIndex[2][drink - 1];

    if (meal == motd[0] && side == motd[1] && drink == motd[2])
    {
        printf("     Meal Set of the day Discount 15%%\n");
        subTotal = subTotal * 0.85;
    }
    printf("Subtotal:                   P%0.2f\n", subTotal);

    return subTotal;
}

int main()
{
    srand(time(NULL));
    int order[3][3] = {};
    int motd[3] = {(rand() % 4) + 1, (rand() % 4) + 1, (rand() % 4) + 1};
    int action;

    printf("Meal of the day: %d %d %d\n", motd[0], motd[1], motd[2]);
    printf("Welcome to McDodo!\n");
    printf("[1] Make an Order\n");
    printf("[0] Exit\nCommand: ");
    scanf("%d", &action);

    if (action == 1)
    {
        int orderCount = 1;
        int resp;
        float total;
        orderF(&order[orderCount - 1][0], &order[orderCount - 1][1], &order[orderCount - 1][2], &orderCount);
        do
        {
            printf("\n[1] Make another order\n");
            printf("[2] Cancel an order\n");
            printf("[3] Proceed to checkout\n");
            printf("[0] Exit\nCommand: ");
            scanf(" %d", &resp);
            switch (resp)
            {
            case 1:
                orderF(&order[orderCount - 1][0], &order[orderCount - 1][1], &order[orderCount - 1][2], &orderCount);
                break;
            case 2:
                int r;
                printf("\n[0] Cancel\n");
                for (int n = 1; n < orderCount; n++)
                {
                    printf("[%d] Order %d\n", n, n);
                }
                printf("\nWhich order do you want to cancel? ");
                scanf("%d", &r);
                if (0 < r < 4)
                {
                }

                break;
            case 3:
                for (int i = 0; i < orderCount - 1; i++)
                {
                    total += checkout(i + 1, order[i][0], order[i][1], order[i][2], motd);
                }
                printf("\n\nTotal Amount Due:                         P%0.2f", total);
                resp = 0;
                break;
            default:
                break;
            }
        } while (resp != 0);
    }
}