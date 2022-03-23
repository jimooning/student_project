#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>
#include <time.h>

#define MAX_COUNT 100
#define SUBJECT 3

struct STUDENT_INFO{
 char name[5];
 int no;
 int gender;
 int c;
 int java;
 int html;
 int total;
 double avr;
 char grade;
};

typedef struct STUDENT_INFO STUDENT;

void input_score(STUDENT *student);
char grade_check(double avr);
void print_score(STUDENT *student, int count);
void seach_score(STUDENT *student);
void remove_score(STUDENT *student);
void update_score(STUDENT *student);
void insert_score(STUDENT *student);

//�� �л��� �Է�
int total_count = 0;

int main()
{
    int menu = 0;
    int flag = 0;
    STUDENT student[MAX_COUNT];

    printf("�������� �� �� �л��� �Է� :");
    scanf("%d",&total_count);

    while(!flag){
        system("cls");
        fflush(stdin);

        printf("1 ����PG �Է�(�ڵ�) \n");
        printf("2 ����PG ��� \n");
        printf("3 ����PG �˻� \n");
        printf("4 ����PG ���� \n");
        printf("5 ����PG ���� \n");
        printf("6 ����PG �߰�(����) \n");
        printf("7 ����PG ����(��������,��������) \n");
        printf("8 ����PG ���� \n");

        printf("�޴��� �����Ͻÿ� : ");
        scanf("%d", &menu);

        switch(menu){
            case 1 :
                //STUDENT student[MAX_COUNT]; ����ü �迭��(STUDENT*~~~)
                input_score(student);
                printf("�������α׷��� �Է¿Ϸ�(�޴��� ���ư����� ���� �Է�)");
                getchar();
                getchar();
                break;
            case 2 :
                print_score(student, total_count);
                printf("�������α׷��� ��¿Ϸ�(�޴��� ���ư����� ���� �Է�)");
                getchar();
                getchar();
                break;
            case 3 :
                seach_score(student);
                printf("�������α׷��� �˻��Ϸ�(�޴��� ���ư����� ���� �Է�)");
                getchar();
                getchar();
                break;
            case 4 :
                remove_score(student);
                printf("�������α׷��� �����Ͽ����ϴ�.");
                getchar();
                getchar();
                break;
            case 5 :
                update_score(student);
                printf("�������α׷��� �����Ͽ����ϴ�.");
                getchar();
                getchar();
                break;
            case 6 :
                insert_score(student);
                printf("�������α׷��� �߰��Ͽ����ϴ�.");
                getchar();
                getchar();
                break;
            case 7 :
                sort_score(student);
                printf("�������α׷��� �����Ͽ����ϴ�.");
                getchar();
                getchar();
                break;
            case 8 :
                printf("�������α׷��� ���Ḧ �����Ͽ����ϴ�.\n");
                flag = 1;
                break;
            default :
                printf("��ȣ�� �ٽ� �����ϼ��� \n");
                break;
        }

    }
    printf("�������α׷��� �����մϴ�.\n");
return 0;
}
//STUDENT student[MAX_COUNT]; ����ü �迭��(STUDENT*~~~)
void input_score(STUDENT *student){
    int i = 0;
    //�����ʱ�ȭ
    srand(time(NULL));
    //��ü�ο��� �ڵ� �Է� ����
    for(i=0;i<total_count;i++){
        //�̸� ������ ����(�빮�ڷ� �����Է�)
        student[i].name[0] = rand()%(25-0+1)+0+'A';
        student[i].name[1] = rand()%26+'A';
        student[i].name[2] = rand()%26+'A';
        student[i].name[3] = 0;
        //��ȣ 1~1000���� �ڵ��Է�
        student[i].no = rand()%(1000-1+1)+1;
        //���� 0:�� 1:��
        student[i].gender = rand()%(1-0+1)+0;
        //3���� ���� 0~100���� �ڵ��Է�
        student[i].c = rand()%(100-0+1)+0;
        student[i].java = rand()%(100-0+1)+0;
        student[i].html = rand()%(100-0+1)+0;
        //�������
        student[i].total = student[i].c +student[i].java + student[i].html;
        //��հ��
        student[i].avr = student[i].total / (double)SUBJECT;
        //��ް�� 90�̻� A/ 80�̻� B/ 70�̻� C/ 60�̻� D/ 60�̸� F
        student[i].grade = grade_check(student[i].avr);
    }


    return;
}
//��ް�� 90�̻� A/ 80�̻� B/ 70�̻� C/ 60�̻� D/ 60�̸� F
char grade_check(double avr){
    char grade = 0;

    if(avr >= 90.0){
        grade = 'A';
    }else if(avr >= 80.0){
        grade = 'B';
    }else if(avr >= 70.0){
        grade = 'C';
    }else if(avr >= 60.0){
        grade = 'D';
    }else {
        grade = 'F';
    }
    return grade;
}

void print_score(STUDENT *student, int count){
    int i = 0;
    for(i=0; i<count; i++){
        printf("%3d %6s %5d %3s %3d %3d %3d %5d %6.2lf %5c\n",
               i+1, &student[i].name[0], student[i].no, (student[i].gender)==1?"��":"��",
               student[i].c, student[i].java, student[i].html, student[i].total, student[i].avr, student[i].grade );

    }
 return;
}
void seach_score(STUDENT *student){
    char name[5]={0,};
    int i=0;
    int search_flag=0;
    printf("ã�� �л� �̸� �Է�3���ڸ� : ");
    scanf("%s",&name[0]);
    //���ڿ� �� ��ҹ��� ���о��� int strcmpi(const char *string1, const char *string2)
    for(i=0;i<total_count;i++){
        if(strcmpi(&name[0],&student[i].name[0])==0){
            print_score(&student[i],1);
            search_flag=1;
        }
    }
    if(search_flag==0){
        printf("%s �̸��� �����ϴ� \n", &name[0]);
    }
    return;
}
void remove_score(STUDENT *student){
    char name[5]={0,};
    int i=0;
    int delete_flag=0;
    printf("������ �л� �̸� �Է�3���ڸ� : ");
    scanf("%s",&name[0]);
    //���ڿ� �� ��ҹ��� ���о��� int strcmpi(const char *string1, const char *string2)
    for(i=0;i<total_count;i++){
        if(strcmpi(&name[0],&student[i].name[0])==0){
            student[i].name[0]=0;
            student[i].name[1]=0;
            student[i].name[2]=0;
            student[i].no=0;
            student[i].gender=0;
            student[i].c=0;
            student[i].java=0;
            student[i].html=0;
            student[i].total=0;
            student[i].avr=0.0;
            student[i].grade='_';
            delete_flag=1;
        }
    }
    if(delete_flag==0){
        printf("������ %s �̸��� �����ϴ� \n", &name[0]);
    }
    return;
}
void update_score(STUDENT *student){
    char name[5]={0,};
    int i=0;
    int update_flag=0;
    printf("������ �л� �̸� �Է�3���ڸ� : ");
    scanf("%s",&name[0]);
    //���ڿ� �� ��ҹ��� ���о��� int strcmpi(const char *string1, const char *string2)
    for(i=0;i<total_count;i++){
        if(strcmpi(&name[0],&student[i].name[0])==0){
            print_score(&student[i], 1);
            printf("������ c���� �Է� 0-100 : ");
            scanf("%d", &student[i].c);
            printf("������ java���� �Է� 0-100 : ");
            scanf("%d", &student[i].java);
            printf("������ html���� �Է� 0-100 : ");
            scanf("%d", &student[i].html);
            student[i].total=student[i].c+student[i].java+student[i].html;
            student[i].avr=student[i].total/(double)SUBJECT;
            student[i].grade=grade_check(student[i].avr);
            update_flag=1;
        }
    }
    if(update_flag==0){
        printf("���� %s �̸��� �����ϴ� \n", &name[0]);
    }
    return;
}
void insert_score(STUDENT *student){

    printf("�߰��� �̸� �Է� 3���� : ");
    scanf("%s", &student[total_count].name[0]);
    printf("�߰��� ��ȣ �Է� 1-1000 : ");
    scanf("%d", &student[total_count].no);
    printf("�߰��� ���� �Է�  ��0/��1: ");
    scanf("%d", &student[total_count].gender);
    printf("�߰��� c���� �Է� 0-100 : ");
    scanf("%d", &student[total_count].c);
    printf("�߰��� java���� �Է� 0-100 : ");
    scanf("%d", &student[total_count].java);
    printf("�߰��� html���� �Է� 0-100 : ");
    scanf("%d", &student[total_count].html);
    student[total_count].total=student[total_count].c+student[total_count].java+student[total_count].html;
    student[total_count].avr=student[total_count].total/(double)SUBJECT;
    student[total_count].grade=grade_check(student[total_count].avr);
    total_count++;
}
void sort_score(STUDENT *student){
    int sort_type=0;
    int i=0, j=0;
    STUDENT copy_student[total_count];
    STUDENT student_buffer;

    printf("��������: 1, ��������: 2 : ");
    scanf("%d",&sort_type);

    //���� -> �纻���� ����ü �迭 ����  void *memcpy(void *_Dst, void const *_Src, size_t _Size);
    for(i=0;i<total_count;i++){
        memcpy(&copy_student[i], &student[i], sizeof(STUDENT));
    }

    switch(sort_type){
        case 1:
            //������������
            for(i=0;i<total_count-1;i++){
                for(j=i+1;j<total_count;j++){
                    if(copy_student[i].total > copy_student[j].total){
                        memcpy(&student_buffer,&copy_student[i], sizeof(STUDENT));
                        memcpy(&copy_student[i],&copy_student[j], sizeof(STUDENT));
                        memcpy(&copy_student[j],&student_buffer, sizeof(STUDENT));
                    }
                }
            }//end of for
            print_score(copy_student, total_count);
            break;
        case 2:
            //������������
           for(i=0;i<total_count-1;i++){
                for(j=i+1;j<total_count;j++){
                    if(copy_student[i].total < copy_student[j].total){
                        memcpy(&student_buffer,&copy_student[i], sizeof(STUDENT));
                        memcpy(&copy_student[i],&copy_student[j], sizeof(STUDENT));
                        memcpy(&copy_student[j],&student_buffer, sizeof(STUDENT));
                    }
                }
            }//end of for
            print_score(copy_student, total_count);

            break;
        default: puts("�߸� �����ϼ̽��ϴ�.");
    }

    return;
}

