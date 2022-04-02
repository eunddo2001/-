#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS
# pragma warning(disable:4996)
# pragma warning(disable:6031)

typedef struct account {
    int ACCNUM;
    char NAME[20];
    int invalid;
}account;

typedef struct credit {
    int ACCNUM;
    int MONEY;
}credit;

void Init_account(account* pAccount)
{
    for (int i = 0; i < 100; i++)
    {
        (pAccount + i)->ACCNUM = 0;
        strcpy((pAccount + i)->NAME, "0");
        (pAccount + i)->invalid = 0;
    }
}

void Init_credit(credit* pCredit)
{
    for (int i = 0; i < 100; i++)
    {
        (pCredit + i)->ACCNUM = 0;
        (pCredit + i)->MONEY = 0;
    }
}

int AddBankAccount(account* pAccount, credit* pCredit, int accnum, char *name, int money, int index)
{
    while (index < 100)
    {
        (pAccount + index)->ACCNUM = accnum;
        strcpy((pAccount + index)->NAME, name);
        (pCredit + index)->ACCNUM = accnum;
        (pCredit + index)->MONEY = money;
        return ++index;
        break;
    }
}

void DeleteBankAccount(account* pAccount, credit* pCredit, int accnum)
{
    for (int i = 0; i < 100; i++)
    {
        if ((pAccount + i)->ACCNUM == accnum)
        {
            (pAccount + i)->ACCNUM = 0;
            (pAccount + i)->NAME, 0;
            (pCredit + i)->ACCNUM = 0;
            (pCredit + i)->MONEY = 0;
        }
    }
}

void AccountTransfer(credit* pCredit, int accnum_s, int accnum_r, int amount)
{
    for (int i = 0; i < 100; i++)
    {
        if ((pCredit + i)->ACCNUM == accnum_s)
        {
            (pCredit + i)->MONEY -= amount;
            for (int j = 0; j < 100; j++)
            {
                if ((pCredit + j)->ACCNUM == accnum_r)
                {
                    (pCredit + j)->MONEY += amount;
                }
            }
        }
    }
}

void CheckMoney(credit* pCredit, int accnum)
{
    for (int i = 0; i < 100; i++)
    {
        if ((pCredit + i)->ACCNUM == accnum)
        {
            printf("해당 계좌의 잔고는 %d입니다.\n", (pCredit+i)->MONEY);
        }
    }
}

void CheckTotalMoney(account* pAccount, credit* pCredit, char *name)
{
    printf("%s", name);
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        if (strcmp((pAccount + i)->NAME, name)==0)
        {
            sum += (pCredit + i)->MONEY;
        }
    }
    printf("사용자의 계좌 총액은 %d입니다.\n", sum);
}

void SuspendAccount(account* pAccount, int accnum)
{
    for (int i = 0; i < 100; i++)
    {
        if ((pAccount + i)->ACCNUM == accnum)
        {
            (pAccount + i)->invalid = 1;
            printf("계좌가 정지되었습니다.\n");
        }
    }
}

void ActivateAccount(account* pAccount, int accnum)
{
    for (int i = 0; i < 100; i++)
    {
        if ((pAccount + i)->ACCNUM == accnum)
        {
            (pAccount + i)->invalid = 0;
            printf("계좌가 활성화되었습니다.\n");
        }
    }
}

int main()
{
    int index = 0;
    int menu;
    bool loop = true;

    account* pAccount;
    pAccount = (account*)malloc(sizeof(account) * 100);
    credit* pCredit;
    pCredit = (credit*)malloc(sizeof(credit) * 100);

    if (pAccount == NULL)
        return -1;

    if (pCredit == NULL)
        return -1;

    //계좌 초기화
    Init_account(pAccount);
    Init_credit(pCredit);

    printf("==========[메뉴]==========\n");
    printf("1. 계좌 생성\n");
    printf("2. 계좌 삭제\n");
    printf("3. 다른 계좌로 이체\n");
    printf("4. 계좌 잔고 출력\n");
    printf("5. 전체 계좌 총액 출력\n");
    printf("6. 계정 정지\n");
    printf("7. 계정 활성화\n");
    printf("8. 뱅킹 시스템 종료\n");
    printf("==========================\n");

    while (loop)
    {
        if (pAccount->invalid == 0)
        {
            printf("\n메뉴를 선택하세요: ");
            scanf("%d", &menu);

            switch (menu)
            {
                case 1: //계좌 생성
                {
                    printf("1. 계좌 생성\n");
                    int accnum1;
                    int money1;
                    char name1[20];
                    printf("계좌 번호 6자리를 생성하세요: ");
                    scanf("%d", &accnum1);
                    printf("이름을 입력하세요: ");
                    scanf("%s", name1);
                    printf("계좌에 넣을 금액을 입력하세요: ");
                    scanf("%d", &money1);
                    index = AddBankAccount(pAccount, pCredit, accnum1, name1, money1, index);
                    break;
                }

                case 2: //계좌 삭제
                {
                    printf("2. 계좌 삭제\n");
                    int accnum2;
                    printf("삭제할 계좌의 계좌 번호를 입력하세요: ");
                    scanf("%d", &accnum2);
                    DeleteBankAccount(pAccount, pCredit, accnum2);
                    break;
                }

                case 3: //다른 계좌로 이체
                {
                    printf("3. 다른 계좌로 이체\n");
                    int accnum_s;
                    int accnum_r;
                    int amount;
                    printf("보내는 사람의 계좌 번호를 입력하세요: ");
                    scanf("%d", &accnum_s);
                    printf("받는 사람의 계좌 번호를 입력하세요: ");
                    scanf("%d", &accnum_r);
                    printf("이체할 금액을 입력하세요: ");
                    scanf("%d", &amount);
                    AccountTransfer(pCredit, accnum_s, accnum_r, amount);
                    break;
                }

                case 4: //계좌 잔고 출력
                {
                    printf("4. 계좌 잔고 출력\n");
                    int accnum4;
                    printf("잔고를 확인하고싶은 계좌의 계좌 번호를 입력하세요: ");
                    scanf("%d", &accnum4);
                    CheckMoney(pCredit, accnum4);
                    break;
                }

                case 5: //전체 계좌 총액 출력
                {
                    printf("5. 전체 계좌 총액 출력\n");
                    char name5[20];
                    printf("전체 계좌 총액을 확인하고싶은 사용자의 이름을 입력하세요: ");
                    scanf("%s", name5);
                    CheckTotalMoney(pAccount, pCredit, name5);
                    break;
                }

                case 6: //계정 정지
                {
                    printf("6. 계정 정지\n");
                    int accnum6;
                    printf("정지시키려는 계좌의 계좌번호를 입력하세요: ");
                    scanf("%d", &accnum6);
                    SuspendAccount(pAccount, accnum6);
                    break;
                }

                case 7: //계정 활성화
                    printf("이미 계정이 활성화되어 있습니다.\n");
                    break;

                case 8: //뱅킹 시스템 종료
                    printf("뱅킹 시스템을 종료합니다.\n");
                    loop = false;
                    break;
            }
        }

        else
        {
            int activate;
            int accnum7;
            printf("\n계좌를 활성화하려면 1을 입력하세요: ");
            scanf("%d", &activate);
            if (activate == 1)
                {
                    printf("활성화하려는 계좌의 계좌번호를 입력하세요: ");
                    scanf("%d", &accnum7);
                    ActivateAccount(pAccount, accnum7);
                }
            else
            {
                printf("뱅킹 시스템을 종료합니다.\n");
                loop = false;
                break;
            }
        }
    }

    free(pAccount);
    free(pCredit);

    return 0;
}