#include <stdio.h>
#include <curses.h>
#include <unistd.h>//����sleep����
#include <stdlib.h>//���������
#include <time.h>

int beginy = 3;//�ߵ���ʼλ��
int beginx = 6;
int snack[1500][2][2];//�� �����ڵ��λ��
int wlenth = 25 , width = 60;//�����С
int speed = 12;//�����ٶ�


int main(){
	
	initscr();
	start_color();//������ɫ����
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);//��ɫ��ʼ��
	init_pair(2,COLOR_BLACK,COLOR_GREEN);
	init_pair(3,COLOR_BLACK,COLOR_BLACK);
	init_pair(4,COLOR_BLUE,COLOR_BLACK);
	init_pair(5,COLOR_RED,COLOR_BLACK);
	init_pair(6,COLOR_YELLOW,COLOR_BLACK);
    keypad(stdscr,1);
    attron(COLOR_PAIR(3));

    //��ʼ������
    WINDOW*  midscreen;//�߿�1
	midscreen = newwin(wlenth,width,2,4);
	//box(midscreen,ACS_DIAMOND,ACS_DIAMOND);
	int a = ACS_CKBOARD;
	//wborder(midscreen,a,a,a,a,a,a,a,a);
	refresh();
	wrefresh(midscreen);
	WINDOW*  midscreen1;//�߿�2
	midscreen1 = newwin(wlenth,width-2,2,5);
	//wborder(midscreen1,a,a,a,a,a,a,a,a);
	refresh();
	wrefresh(midscreen1);
	WINDOW*  midscreen2;//��Ϸ������
	midscreen2 = newwin(wlenth-2,width-4,3,6);
	WINDOW*  midscreen3;//��Ϸ��ʼ����
	midscreen3 = newwin(wlenth-2,width-4,3,6);
	
	keypad(midscreen2,1);
	keypad(midscreen3,1);

    int lenth = 3;//�ߵĳ���

    refresh();
    wrefresh(midscreen2);

    int F = 4;//���ó�ʼ����
    bool paint = 1;//����whileѭ��bool��
    
	int start_ch;//��ʼ����getch��ֵ
	int end_ch;//��������getch��ֵ
    
	int ra = 11,rb = 24;//����ʳ���ʼλ��
	int score = 0;//���÷���
	bool start = 1;//��ʼ�����boolֵ
	bool end = 1;//���������boolֵ
	bool run = 1;//�����е�boolֵ
	
while(run){
		int lenth = 3;//�ߵĳ���
		//�����ߵĳ�ʼ����
		int snack[1500][2][2] = {
        {{0,0},{0,0}},
        {{beginy,beginx},{beginy,beginx+1}},
        {{beginy,beginx+2},{beginy,beginx+3}},
        {{beginy+1,beginx+2},{beginy+1,beginx+3}}
		};
	while(start){
		wattron(midscreen3, COLOR_PAIR(6)|A_BOLD );
		box(midscreen3,ACS_VLINE,ACS_HLINE);
		mvwprintw(midscreen3,7,16,"welcome to SnackGame !");
		wattron(midscreen3, COLOR_PAIR(6)|A_BOLD |A_STANDOUT);
		mvwprintw(midscreen3,12,15,"Enter 'Esc' to end game ");
		mvwprintw(midscreen3,15,15,"Enter  'p'  to end game ");
		wattroff(midscreen3, COLOR_PAIR(6)|A_BOLD |A_STANDOUT);
		wattron(midscreen3, COLOR_PAIR(6)|A_BOLD );
		refresh();
		wrefresh(midscreen3);
		start_ch = wgetch(midscreen3);
		wclear(midscreen3);
		switch(start_ch){
			case 'p':  start = 0; break;
			case 27 :  start = 0; paint = 0;end =0;run =0;break; //27��ʾ����Esc��
		}
		refresh();
		wrefresh(midscreen3);
	}
    while(paint){		
        int ch;
		halfdelay(speed);//�����ٶ�
		//��getch����������halfdelay���棩
		ch = getch();
        
		wclear(midscreen2);//����
		wclear(midscreen);
		wclear(midscreen1);
		
		wborder(midscreen,a,a,a,a,a,a,a,a);
		wborder(midscreen1,a,a,a,a,a,a,a,a);
		wrefresh(midscreen);
		wrefresh(midscreen1);
		

        //����ʳ����ж����Ƿ�Ե�ʳ��
		if((snack[lenth][0][0] == ra&&
			snack[lenth][0][1] == rb)||
			(snack[lenth][0][0] == ra&&
			snack[lenth][0][1] == rb-1)||
			(snack[lenth][0][0] == ra&&
			snack[lenth][0][1] == (rb+1))
			)
            {
            srand(time(0));
            ra = rand() % (23);
            rb = rand() % (55);
            wattron(midscreen2,COLOR_PAIR(2));
            wmove(midscreen2,ra,rb);
            wprintw(midscreen2,"+");
            wmove(midscreen2,ra,rb+1);
            wprintw(midscreen2,"+");
            wattroff(midscreen2,COLOR_PAIR(2));
            wrefresh(midscreen2);

            score += 1;
			lenth += 1;
			
			//�����Ѷȣ�����speedֵ��
			if(score > 20) speed = 1;
			else if (score > 15) speed = 2;
			else if (score > 10) speed = 4;
			else if (score > 5) speed = 6;

        }
        else{
            wattron(midscreen2,COLOR_PAIR(2));
            wmove(midscreen2,ra,rb);
            wprintw(midscreen2,"+");
            wmove(midscreen2,ra,rb+1);
            wprintw(midscreen2,"+");
            wattroff(midscreen2,COLOR_PAIR(2));
            wrefresh(midscreen2);
            for(int k=1;k<=lenth;k++){
                for(int j=0;j<2;j++){
                    snack[k][j][0] = snack[k+1][j][0];
                    snack[k][j][1] = snack[k+1][j][1];
                }
            }

        }



		//���ü��̹��ܼ�
		switch(ch){
			case KEY_UP:  {if(F == 2){break;} F=1;break;}
			case KEY_DOWN:  {if(F == 1){break;} F=2; break;}
			case KEY_LEFT:  {if(F == 4){break;} F=3; break;}
			case KEY_RIGHT:  {if(F == 3){break;} F=4; break;}
			case 27 : {paint=0; end = 1; break;}//27��ʾ����Esc��
		}
        
		//���ݷ��򣬸��� snack[lenth] ����λ��
		if(F == 1){
            snack[lenth][0][0] = snack[lenth-1][0][0]-1;
            snack[lenth][0][1] = snack[lenth-1][0][1];
            snack[lenth][1][0] = snack[lenth-1][1][0]-1;
            snack[lenth][1][1] = snack[lenth-1][1][1];
        }
        if(F == 2){
            snack[lenth][0][0] = snack[lenth-1][0][0]+1;
            snack[lenth][0][1] = snack[lenth-1][0][1];
            snack[lenth][1][0] = snack[lenth-1][1][0]+1;
            snack[lenth][1][1] = snack[lenth-1][1][1];
        }
        if(F == 3){
            snack[lenth][0][0] = snack[lenth-1][0][0];
            snack[lenth][0][1] = snack[lenth-1][0][1]-2;
            snack[lenth][1][0] = snack[lenth-1][1][0];
            snack[lenth][1][1] = snack[lenth-1][1][1]-2;
        }
        if(F == 4){
            snack[lenth][0][0] = snack[lenth-1][0][0];
            snack[lenth][0][1] = snack[lenth-1][0][1]+2;
            snack[lenth][1][0] = snack[lenth-1][1][0];
            snack[lenth][1][1] = snack[lenth-1][1][1]+2;
        }
		
		//��������
        for(int k=1;k<=lenth;k++){
            for(int j=0;j<2;j++){
                wmove(midscreen2,snack[k][j][0],snack[k][j][1]);
                wattron(midscreen2,COLOR_PAIR(1));
                wprintw(midscreen2,"%c", '+' );
                wattroff(midscreen2,COLOR_PAIR(1));
            }
        }
		
		//���ײ�����ұ߿����
        if(snack[lenth][1][1]>=56 || snack[lenth][0][1]<0 ){
            paint = 0;
			end = 1;
        }
		//���ײ�����±߿����
        if(snack[lenth][0][0]<0 || snack[lenth][1][0]>22){
            paint = 0;
			end = 1;
			
        }
        for(int k=1;k<lenth;k++){//���ײ���������
                if(snack[k][0][0]== snack[lenth][0][0] &&
                   snack[k][0][1]== snack[lenth][0][1] &&
                   snack[k][1][0]== snack[lenth][1][0] &&
                   snack[k][1][1]== snack[lenth][1][1] ){
                    paint = 0;
					end = 1;
                }
        }

        wmove(midscreen2,0,0);
        curs_set(0);//ȡ�������˸
        
		//�������
		move(27,8);
		attron(COLOR_PAIR(4) | A_BOLD);
		printw("now score is %d",score);
		if(score<5) mvprintw(28,8,"Difficulty: *		simple");
		else if(score<10) mvprintw(28,8,"Difficulty: **	general");
		else if(score<15) mvprintw(28,8,"Difficulty: ***	difficult");
		else if(score<20) mvprintw(28,8,"Difficulty: ****	Purgatory");
		attron(COLOR_PAIR(4) | A_BOLD|A_STANDOUT);
		mvprintw(30,8,"Enter 'UP','DOWN','LEFT'or'RIGHT' to control direction!");
		mvprintw(31,8,"                                                       ");
		mvprintw(32,8,"Enter 'Esc' to end the running game!                   ");
		attroff(COLOR_PAIR(4) | A_BOLD|A_STANDOUT);
		attroff(COLOR_PAIR(4) | A_BOLD);

        refresh();
        wrefresh(midscreen2 );

    }
	clear();
	wclear(midscreen3);
	wrefresh(midscreen3);
	while(end){
		wattron(midscreen3, COLOR_PAIR(4)|A_BOLD );
		box(midscreen3,ACS_VLINE,ACS_HLINE);
		mvwprintw(midscreen3,7,18,"Your score is %d ",score);
		wattron(midscreen3, COLOR_PAIR(4)|A_BOLD |A_STANDOUT);
		mvwprintw(midscreen3,12,15,"Enter 'Esc' to end game ");
		mvwprintw(midscreen3,15,15,"Enter 'p' to play again ");
		wattroff(midscreen3, COLOR_PAIR(4)|A_BOLD |A_STANDOUT);
		wattron(midscreen3, COLOR_PAIR(4)|A_BOLD );
		refresh();
		wrefresh(midscreen3);
		
		end_ch = wgetch(midscreen3);
		wclear(midscreen3);
		switch(end_ch){
			case 'p':  {
				end = 0; 
				start = 0; 
				paint=1;
				lenth = 3;
				score = 0;
				speed = 12;
				F = 4;
				break;
			}
			case 27 :  end = 0; run = 0 ; break; //27��ʾ����Esc��
		}
		refresh();
		wrefresh(midscreen3);
	}
	
	}//while(run)�Ľ���
	
    refresh();
	endwin();
	return 0;
}
