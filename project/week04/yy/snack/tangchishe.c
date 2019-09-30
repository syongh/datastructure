#ifndef TANCHISHE_H
#define TANCHISHE_H

#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <sys/time.h>       //timeval
#include <unistd.h>         //usleep
#include <sys/select.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>        //memset
#include <setjmp.h>

#define LSBLANK     L" "
#define BLANK       " "

#define INIT_NODE_SIZE 5
#define SNAKE_MAX_SIZE 8192
#define LEFT_WALL 1
#define RIGHT_WALL (COLS-2)
#define TOP_WALL 0
#define BUTT_WALL (LINES-1)
#define NOB         L"#"//
#define LSFOOD      L"O"
#define NODE        "#"//instead of L"#"
#define FOOD        "O"
#define MAX_LEVEL 100
#define SUB_TIME_EACH_LEVEL 6
#define TIMES_TO_UPGRADE_EACH_LEVEL 6

#define _KEY_UP     'w'
#define _KEY_DOWN   's'
#define _KEY_LEFT   'a'
#define _KEY_RIGHT  'd'
#define AGAIN_KEY   'A'
#define QUIT_KEY    'Q'
struct post{
    int row;
    int col;
};
struct snake_s{
    int node_num;
    struct post head;
    struct post* snake_body;

};

//for all
extern struct snake_s snake_s1;
extern int row;
extern int col;
//extern struct timeval delay;

extern int real_g_forward;
extern int g_key_forward;
extern int food_row;
extern int food_col ;
extern int eat_num;
extern int score ;
extern int ticker ;//ms

extern int last_s_node;
extern int first_s_node;

extern int max_score;//do not init in retry!
extern int level;
extern int delay_sub_each_level[MAX_LEVEL];
extern int times_to_upgrade_each_level[MAX_LEVEL];
//extern int ticker_for_col;
//extern int ticker_for_row;

int set_ticker(int n_msecs);
void init_tcs(void);

#endif

int row=0; //the head
int col=0;

int g_key_forward=_KEY_RIGHT;
int real_g_forward=_KEY_RIGHT;
int food_row =0;
int food_col =0;
int eat_num=0;
int ticker = 200;//ms


struct snake_s snake_s1;
int last_s_node=0;
int first_s_node;

int score =0;
int max_score=0;//do not init in retry!
int level=0;
int delay_sub_each_level[MAX_LEVEL]={0};
int times_to_upgrade_each_level[MAX_LEVEL]={0};

void init_tcs(void)
{
    initscr();
    cbreak();       //�رջ���
    nonl();
    noecho();       //�رջ���
    intrflush(stdscr,FALSE);
    keypad(stdscr,TRUE);
    curs_set(0);    //��겻�ɼ�

    row =LINES/2-1;
    col =COLS/2-1;
    eat_num=0;
    ticker = 310;//ms
    score =0;
    g_key_forward=_KEY_RIGHT;
    real_g_forward=_KEY_RIGHT;
    last_s_node=0;
    //first_s_node;
    level=0;

    //����ÿ��һ����Ҫ�Ե�ʳ���ÿ��һ���ߵĿ�����Ҳ����ticker�Ĵ�С
    int sum=delay_sub_each_level[0]=8;//EVERY_LEVEL_SUB_TIME;
    int i;
    times_to_upgrade_each_level[0]=TIMES_TO_UPGRADE_EACH_LEVEL;
    for(i=1;i<MAX_LEVEL;++i){
        times_to_upgrade_each_level[i]=times_to_upgrade_each_level[i-1]+(TIMES_TO_UPGRADE_EACH_LEVEL);

        if(sum<ticker-50){
            if(i<6)
                delay_sub_each_level[i] =8;
            else if(i<12)
                delay_sub_each_level[i] =7;
            else if(i <18)
                delay_sub_each_level[i] =6;
            else
                delay_sub_each_level[i] =5;

        }
        else delay_sub_each_level[i]=delay_sub_each_level[i-1];
        sum =sum+delay_sub_each_level[i];

    }
    //���Ʊ߿�
    attrset(A_REVERSE);
    for(i=0;i<LINES;++i){
        mvaddch(i,0,' ');
        mvaddch(i,LEFT_WALL,' ');
        mvaddch(i,RIGHT_WALL,' ');
        mvaddch(i,COLS-1,' ');
    }
    for(i=0;i<COLS;++i){
        mvaddch(0,i,' ');
        mvaddch(LINES-1,i,' ');
    }

    mvprintw(0,COLS/2 -16,"Score:%d Max Score:%d Level:%d",score,max_score,level);
    mvprintw(LINES-1,COLS/2 -18,"Eledim Walks the Earth,%c%c%c%c to Move",_KEY_UP, _KEY_DOWN, _KEY_LEFT, _KEY_RIGHT);
    refresh();
    attrset(A_NORMAL);

    //�����ߵĽڵ�����
    snake_s1.snake_body = malloc( SNAKE_MAX_SIZE *sizeof(struct post)) ;
    if(snake_s1.snake_body == NULL)
        mvprintw(0,0,"malloc error");
    memset(snake_s1.snake_body,0,SNAKE_MAX_SIZE*sizeof(struct post));

    srand((unsigned)time(NULL)); //no this ,rand every time return same num
#ifdef DEBUG__
    food_row = LINES/2 -1;
    food_col =COLS/2 +1;
#else
    food_row = 1+rand()%(LINES-3);
    food_col =2+rand()%(COLS-5);
#endif
    //��ʼ�����������е����꣬����ʾ
    //snake_s1.head.row=row;
    //snake_s1.head.col=col;
    snake_s1.node_num =INIT_NODE_SIZE;
    first_s_node=snake_s1.node_num-1;

    for(i=0;i<snake_s1.node_num;++i){
        snake_s1.snake_body[i].row=row;
        snake_s1.snake_body[i].col=col-snake_s1.node_num+1+i;
        //mvaddchstr(row,col-i,NOB);
        mvaddstr(row,col-i,NODE);
    }
    //show food
    //mvaddchstr(food_row,food_col,FOOD);
    mvaddstr(food_row,food_col,FOOD);
    move(LINES-1,0);refresh();
}

//2015 10 06
//#define DEBUG__
void gogo(int );
void move_here_show(int  );
int collision_detec(void);
void gameover(int );
sigjmp_buf jmpbuffer;

int main()
{
    //��������Ծ���������������Ϣ���������ص㡣���źŰ棬���غ��Զ��ָ��ź�����mask��
    //�����״������Թ�if�ڴ��룬��Ϸ��������siglongjmp(jmpbuffer, int)����
    if(sigsetjmp(jmpbuffer,1) != 0){

    }
    init_tcs();//�����ĳ�ʼ��������Ļ�ĳ�ʼ����ʾ��������ʳ�����ʾ

#ifndef DEBUG__
    signal(SIGALRM,gogo);       //���ö�ʱ�źŵĴ������������ߵ��ƶ�,����ʱ���ֶ�����
    set_ticker(ticker);         //ÿticher���� �����ź�
#endif
    while(1){
        int i =getch();
        switch (i) {
            case _KEY_UP   :
                if(real_g_forward!=_KEY_DOWN &&real_g_forward!=_KEY_UP)       //��ֹ����
                    {g_key_forward=_KEY_UP;}break;
            case _KEY_DOWN :
                if(real_g_forward!=_KEY_UP&&real_g_forward!=_KEY_DOWN )
                    {g_key_forward=_KEY_DOWN ;}break;
            case _KEY_LEFT :
                if(real_g_forward!=_KEY_RIGHT&&real_g_forward!=_KEY_LEFT)
                    {g_key_forward=_KEY_LEFT;}break;//delay_real=&delay;
            case _KEY_RIGHT:
                if(real_g_forward!=_KEY_RIGHT&&real_g_forward!=_KEY_LEFT)
                    {g_key_forward=_KEY_RIGHT;}break;
#ifdef DEBUG__
            case 'g':gogo(0);//raise(SIGALRM);
#endif
        }
    }

    endwin();
    return 0;
}

void gogo(int signum)//zouba
{
    //���������ʱ����ȫ�ֱ���g_key_forward��ÿ�ΰ��µ�ϣ��ǰ���ķ���
    int temp_g_forward=g_key_forward;
    move_here_show(temp_g_forward);//����ָ�������ƶ�
    collision_detec();//��ײ���
}

void move_here_show(int  forward)
{
    switch (forward) {
        case _KEY_UP: --row; break;     //��ͷ��㰴��ָ��������ƶ�
        case _KEY_DOWN : ++row; break;
        case _KEY_LEFT: --col; break;
        case _KEY_RIGHT: ++col; break;
        default:return;
    }
    //��ʱ������������ǰ������
    //��Ϊ��ʱ�˶�����ϣ���real_g_forward��ʱ���ڼ��̼����б�ʹ��
    real_g_forward=forward;

    //mvaddchstr(snake_s1.snake_body[last_s_node].row,
    //                          snake_s1.snake_body[last_s_node].col,LSBLANK);
    //��Ļ��ɾ�����ֲ������������һ���ڵ�
    mvaddstr(snake_s1.snake_body[last_s_node].row,
            snake_s1.snake_body[last_s_node].col,BLANK);
    //�ڶ������������ƶ����ͷ�ڵ� ���꣨��ͷʼ�����ӵ� �������Сδ�õ�Ԫ ������β����
    snake_s1.snake_body[++first_s_node].row= row;
    snake_s1.snake_body[first_s_node].col = col;
    //mvaddchstr(row,col,NOB);
    mvaddstr(row,col,NODE); //����Ļ����ʾ����ͷ�µ�����

#ifdef DEBUG__
    //�����õĲ�����������MAX_SIZE������Լ1800�룬֮ǰ�϶������������������
    printw("%d",first_s_node+1-INIT_NODE_SIZE);
#endif
    move(LINES-1,0);refresh();
    last_s_node++;            //�ڶ����м�ȥ���ƶ����β�ڵ� ����
}
int collision_detec()
{
    int i;
    //����Ƿ�ʳ��
    if(col== food_col&& row ==food_row){
        srand((unsigned)time(NULL));
        food_col = 2+rand()%(COLS-5);
        food_row = 1+rand()%(LINES-3);

test_dupe://��ֹ�����ɵ�ʳ���������ϡ���
        for(i=last_s_node;i<first_s_node;++i){
           if(food_col == snake_s1.snake_body[i].col)
               if(food_row == snake_s1.snake_body[i].row ){
                   food_col = 2+rand()%(COLS-5);
                   food_row = 1+rand()%(LINES-3);
                   goto test_dupe;
                }
        }
        //mvaddchstr(food_row,food_col,FOOD);
        //���ﲻ�ģ�centosҲ������ʾ��Ϊ�˱��գ�Ҳ�ĳɵ��ֽڰ�
        mvaddstr(food_row,food_col,FOOD);//
        last_s_node--;//muhaha

        //����Ƿ����� ���ұ������Ӧlevel���±꣩��������Ҫ��ʳ��
        if(++eat_num >=times_to_upgrade_each_level[level]){
            //������ʱ������ ÿ��Ӧ���ٵ�ʱ�䣬���µȼ�
            ticker -=delay_sub_each_level[level++];//ע��˴����ۼ���
            //���¶�ʱ�����źź��������ӿ죬�ƶ��ٶȼӿ�
            set_ticker(ticker);
        }
        score++;
        max_score =max_score>score?max_score:score;
        attrset(A_REVERSE);                     //��ɫ���������
        mvprintw(0,COLS/2 -16,"Score:%d Max Score:%d Level:%d",score,max_score,level);
        attrset(A_NORMAL);
        //move(LINES-1,0);refresh();//û��Ҳ���ԣ�����level�ǻ���

    }
    else{
        //����Ƿ�ײǽ
        if(col == LEFT_WALL||col == RIGHT_WALL||row == TOP_WALL||row == BUTT_WALL)
            gameover(1);
        //����Ƿ��Թ�
        for(i=last_s_node;i<first_s_node-2;++i){
            if(col == snake_s1.snake_body[i].col)
                if(row == snake_s1.snake_body[i].row )
                    gameover(2);
        }
    }
    return 0;
}
void gameover(int type)
{
    set_ticker(0);
    mvprintw(LINES/2-2,COLS/2 -15,           "           Game Over!    ");
    char * S=                                "       Your Score is %d!";
    if(score>max_score)
        mvprintw(LINES/2+1,COLS/2 -15,       "     You Cut the Record!!!");
    else S=                                  "  Your Score is %d! Too Young!!!";
    if(score>75)S =                          "     Your Score is %d! Nice!!!";
    mvprintw(LINES/2,COLS/2 -15, S,score);
    mvprintw(LINES/2+2,COLS/2 -15,           "Press <%c> Play Again! <%c> to Quit!",AGAIN_KEY,QUIT_KEY);
    refresh();
    free(snake_s1.snake_body);
    int geta;
    while(1){
        if((geta =getch()) == AGAIN_KEY){
            erase();
            refresh();
            siglongjmp(jmpbuffer, type);//game over ������Ϣ����main��ʼ׼���õ��������
        }
        else if(geta == QUIT_KEY)
            exit(0);
    }
}

int set_ticker(int n_msecs) //�� �Ժ���Ϊ��λ��ʱ�� ת���ɶ�Ӧ�� ��ʱ��
{
    struct itimerval new_timeset;
    long n_sec,n_usecs;

    n_sec = n_msecs/1000;
    n_usecs=(n_msecs%1000)*1000L;

    new_timeset.it_interval.tv_sec=n_sec;
    new_timeset.it_interval.tv_usec=n_usecs;

    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec= n_usecs;

    return setitimer(ITIMER_REAL,&new_timeset,NULL);
}
