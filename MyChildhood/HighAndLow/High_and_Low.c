#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int Round(double val){
	return(val + 0.5555555555);
}

int Dragon_roll(int pc){
	int a = 113;
	int tim = time(NULL);
	do{
		pc = tim % a;
		srand(pc);
		pc = rand() % 15;
		a++;
	}while(pc <= 1);
	return pc;
}

char *Help(int h, int i){
	char *a = "\n\n���̃Q�[���́A���ɏo�Ă��鐔����\n���݂̐������傫��������������\������Q�[���ł�\n\n";
	char *b = "���ɏo�Ă��鐔�������݂̐������傫���Ǝv�����ꍇ��\"h\"��\n�������Ǝv������\"l\"����͂���\n\"Enter\"�L�[�������Ă�������\n\n";
	char *c = "�ԈႦ�����_�ŃQ�[���I�[�o�[�ƂȂ�܂�\n\n";
	char *d = "�\������鐔���́A�g�����v�̃J�[�h�ɕ����\n2,3,4,5,6,7,8,9,10,J,Q,K,A�@��13�ł�\n2���Ŏ�ŁAA���ŋ��ɂȂ�܂�\n\n";
	char *e = "�Q�[���̓r����\"finish\"�Ɠ��͂���ƃQ�[�����I�����܂�\n\n";
	char *f = "�n�߂�O�ɂ܂��A��Փx��\n\"Hard\", \"Nomal\", \"Easy\", \"Beginner\", \"Endless\"\n�̒�����I�����Ă�������";
	char *g = "\"difficulty\"�Ɠ��͂����\n���ݑI�𒆂̓�Փx�̐���������܂�\n\n";
	
	switch(i){
		case 0:
			return a;
			break;
		case 1:
			return b;
			break;
		case 2:
			return c;
			break;
		case 3:
			return d;
			break;
		case 4:
			return e;
			break;
		case 5:
			if(h == 1){
				f = "�����ł͂܂��A��Փx��\n\"Hard\", \"Nomal\", \"Easy\", \"Beginner\", \"Endless\"\n�̒�����I�����܂�";
			}
			else if(h > 1){
				f = "�܂��A\"change\"�Ɠ��͂���Ɠ�Փx���ύX�ł��܂�\n\n";
			}
			return f;
			break;
		case 6:
			return g;
			break;
	}
}

char *Difficulty(int h){
	char *a = "\n\n\"h\"��I�������Ƃ��̓��_��\n�O�̐���8�ȏ�̏ꍇ��100point\n7�ȉ��͐������������Ȃ�ɂ��10point�������Ă����܂�\n(7��90point��2��40point)";
	char *b = "\n\n\"l\"��I�������Ƃ��̓��_��\n�O�̐���8�ȉ��̏ꍇ��100point\n9�ȏ�͐������傫���Ȃ�ɂ��10point�������Ă����܂�\n(9��90point��A��40point)";
	char *c = "\n\n\"h\"��I�������Ƃ��̓��_��\n�O�̐���6�ȏ�̏ꍇ��100point\n3-5�̏ꍇ��75point\n2�̏ꍇ��50point";
	char *d = "\n\n\"l\"��I�������Ƃ��̓��_��\n�O�̐���10�ȉ��̓f����100point\nJ-K�̏ꍇ��75point\nA�̏ꍇ��50point�ɂȂ�܂�";
	char *e = "\n\n�Q�[���I�[�o�[�ɂȂ�����ɃR���e�B�j���[�����\n����܂ł̃|�C���g����500point������܂�";
	char *f = "\n\n�Q�[���I�[�o�[�ɂȂ�����ɃR���e�B�j���[�����\n�|�C���g���N���A����܂�";
	char *g = "\n\n�Q�[���I�[�o�[�ɂȂ�����ɃR���e�B�j���[�����\n�|�C���g��2/1�ɂȂ�܂�(�����_�ȉ��J�グ)\n�������A�l�������|�C���g��50point�ȉ��̏ꍇ\n�|�C���g�̓N���A����܂�";
	
	if(h == 0 || h == 1 || h == 4){
		return a;
	}
	else if(h == 2 || h == 3){
		return c;
	}
	else if(h == 5 || h == 6 || h == 9){
		return b;
	}
	else if(h == 7 || h == 8){
		return d;
	}
	else if(h == 10){
		return e;
	}
	else if(h == 11 || h == 12){
		return f;
	}
	else if(h == 13){
		return g;
	}
	else if(h == 14){
		g = "\n\n�Q�[���ɕ�����Ɗl���|�C���g����300points������܂���\n���̂܂܃Q�[���𑱂��邱�Ƃ��ł��܂�\n\n�I������ɂ́A\"finish\"�Ⴕ����\"change\"�R�}���h��\n���͂��Ă�������";
		return g;
	}
	else{
		g = "!! Error !!\n\nSorry. The computer has made some error.\nPlease sent error report to the creator of this game.\n\nearel.elceir.thorondor@hotmail.co.jp\n\nInput \"change\" to continue the game.\n\n>";
		return g;
	}
}

char *Rong(int num){
	char d[100] = {'\0'};
	char *da;
	
	switch(num){
		case 14:
			da = "A";
			break;
		case 13:
			da = "K";
			break;
		case 12:
			da = "Q";
			break;
		case 11:
			da = "J";
			break;
		default:
			sprintf(d, "%d", num);
			da = d;
			break;
	}
		return(da);
}

int main(void){
	int a = 0, che = 0, point = 0, hi = 0, hid = 0;
	
	do{
		char *doc = Help(0, a);
		printf("%s", doc);
		a++;
	}while(a < 6);
	
	do{
		char com[100];
		int dif;
		char *d;
		
		printf("\n\n\nSelect difficulty>");
		
		do{
			int pass = 0;
			
			scanf("%s", com);
			
			if(strcmp(com,"hard") == 0){
				dif = 0;
				strcpy(com, "Hard");
			}
			else if(strcmp(com,"nomal") == 0){
				dif = 1;
				strcpy(com, "Nomal");
			}
			else if(strcmp(com,"easy") == 0){
				dif = 2;
				strcpy(com, "Easy");
			}
			else if(strcmp(com,"beginner") == 0){
				dif = 3;
				strcpy(com, "Beginnger");
			}
			else if(strcmp(com, "endless") == 0){
				dif = 4;
				strcpy(com, "Endless");
			}
			else if(strcmp(com,"finish") == 0){
				
				printf("\n\nWill you quit the game?>");
				
				do{
					pass = 0;
					
					scanf("%s", com);
					
					if(strcmp(com, "y") == 0){
					
						if(che == 2){
							printf("\n\n\nYour final point is: %d\n\nYour high score is: %d", point, hi);
						}
						
						printf("\n\n\nPress key to finish\n\n>");
						getch();
						return 0;
					}
					else if(strcmp(com, "n") == 0){
						dif = 5;
						printf("\n\nSelect difficulty>");
					}
					else{
						printf("\n\nWill you quit the game? Y or N>");
						pass = 1;
					}
				}while(pass == 1);
			}
			else if(strcmp(com, "help") == 0){
			
				a = 0;
				dif = 5;
				
				do{
					char *doc = Help(1, a);
					printf("%s", doc);
					a++;
				}while(a < 6);
				
				printf("\n\n\nSelect difficulty>");
			}
			else{
				dif = 5;
				printf("\n\n\"hard\", \"nomal\", \"easy\", \"beginner\" or \"endless\"");
			}
			
			if(dif < 5){
				int m = 0;
				int n = dif;
				char *dm;
				
				printf("\n\n\n\n\n\"%s\"���I������܂���\n", com);
				do{
				
					dm = Difficulty(n);
					printf("%s", dm);
					
					n = n + 5;
					m++;
					
				}while(m < 3);
				
				printf("\n\n\n���̓�Փx�Ńv���C���܂����H\n\n");
				printf("\nWill you paly in this mode?>");
				
				do{
					scanf("%s", com);
					
					if(strcmp(com, "y") == 0){
						
						printf("\n\n�ł́A�撣���Ă�������!!\n\nGood Luck!!\n\n\n");
						
						if(che == 2){
							printf("\nYour point is: %d\n\n", point);
						}
						che = 0;
						goto Selected;
					}
					else if(strcmp(com, "n") == 0){
						
						printf("\n\n\n��Փx��I�����Ă�������\n");
						dif = 5;
						break;
					}
					else
						printf("\n\nWill you play in this mode? Y or N>");
				}while(1);
			}
			
			if(dif == 5)
				printf("\n\nSelect difficulty>");
		}while(1);
		
		Selected:
		
		a = Dragon_roll(0);
		
		while(che == 0){
			int ad, ed = 4, fp, help = 2;
			
			d = Rong(a);
			
			fp = 8 - a;
			if(fp < 0)
				fp = fp - (fp * 2);
			
			if(dif <= 1 || dif == 4)
				fp = fp * 10;
			else{
				if(fp == 6)
					fp = 50;
				else if(fp < 6){
					if(fp > 2)
						fp = 25;
					else if(fp <= 2)
						fp = 0;
				}
			}
			
			printf("\nNumber is %s, H or L? >", d);
			scanf("%s", com);
			
			ad = Dragon_roll(0);
			
			d = Rong(ad);
			
			if(ad == a)
				ed = 1;
			
			if(strcmp(com, "l") == 0){
				if(ad < a){
					
					ed = 0;
					
					if(a > 8)
						fp = 100 - fp;
					else
						fp = 100;
				}
				else if(ad > a)
					ed = 2;
			}
			else if(strcmp(com, "h") == 0){
				if(ad < a)
					ed = 2;
				else if(ad > a){
					ed = 0;
					
					if(a < 8)
						fp = 100 - fp;
					else
						fp = 100;
				}
			}
			
			else if(strcmp(com,"finish") == 0){
			
				printf("\n\nWill you quit the game?>");
				
				do{
					scanf("%s", com);
					
					if(strcmp(com, "y") == 0){
						printf("\n\nYour final point is: %d\n\nYour high score is: %d\n\nPress key to finish.\n\n>", point, hi);
						getch();
						return 0;
					}
					else if(strcmp(com, "n") == 0){
						che = 0;
						ed = 4;
					}
					else{
						printf("\n\nWill you quit the game? Y or N>");
						che = 2;
					}
				}while(che == 2);
			}
			else if(strcmp(com,"change") == 0){
			
				printf("\n\n\nWill you change difficulty?>");
				
				do{
					scanf("%s", com);
					
					if(strcmp(com, "y") == 0){
						printf("\n\nYour point is: %d", point);
						che = 2;
						ed = 4;
					}
					else if(strcmp(com, "n") == 0){
						che = 0;
						ed = 4;
					}
					else{
						printf("\n\nWill you change difficulty? Y or N>");
						che = 1;
					}
				}while(che == 1);
			}
			else if(strcmp(com, "help") == 0){
				int i = 0;
				
				do{
					char *doc = Help(2, i);
					printf("%s", doc);
					i++;
				}while(i < 7);
				
				che = 0;
				help = 1;
			}
			else if(strcmp(com, "difficulty") == 0){
			
				int m = 0;
				int n = dif;
				
				printf("\n\n\n���݂̓�Փx�ł�");
				
				do{
					d = Difficulty(n);
					printf("%s", d);
					
					n = n + 5;
					m++;
					
				}while(m < 3);
				
				printf("\n\n");
				
				che = 0;
			}
			else{
				printf("\n\nInput \"h\" or \"l\" and press Enter\n");
				che = 0;
			}
			
			if(ed != 4)
				printf("\n%s\n\n", d);
			
			switch(ed){
			
				char *poimes;
				
				case 0:
					point = point + fp;
						
					printf("\nYou Win!\n\n\n+%d points\n\nYour point is: %d\n\n", fp, point);
					
					if(point > hi){
						hi = point;
						printf("You are recording new high score!!\n\n");
					}
					printf("\n");
					che = 0;
					ed = 0;
					
					break;
				
				case 1:
					point = point + 0;
					printf("\nEven\n\n+-0 point\n\n\nYour point is: %d\n\n", point);
					che = 0;
					ed = 0;
					
					break;
				
				case 2:
				
					if( dif < 4){
						printf("\nYou Lose...\n\nYour point is: %d\n\nYour high score is: %d\n\n", point, hi);
						
						if(hid < hi){
							printf("New high score!!\n\n");
							hid = hi;
						}
						
						printf("\nContinue?>");
						
						switch(dif){
							case 0:
								point = point - 500;
								poimes = "\n\n\n-500 points\n\n";
								
								break;
							
							case 1:
								point = 0;
								poimes = "\n\n\nYour point has been cleared.\n\n";
								
								break;
							
							case 2:
								point = 0;
								poimes = "\n\n\nYour point has been cleared.\n\n";
								
								break;
							
							case 3:
								if(point < 0){
									poimes = "\n\n\n!!Your point is under 0!!\n\n+-0 point\n\n";
								}
								else if(point == 0){
									poimes = "\n\n\nOh, no!\nYou don't have point...\n\n";
								}
								else if(point > 0 && point <= 50){
								
									point = 0;
									poimes = "\n\n\n!!Your point is too low!!\n\nYour point has been cleared.\n\n";
								}
								else{
									fp = point - Round(point / 2);
									point = Round(point / 2);
									sprintf(poimes, "\n\n\n-%d points\n\n", fp);
								}
								break;
						}
						
						do{
							scanf("%s", com);
							
							if(strcmp(com, "y") == 0){
								printf("%s\nYour point is: %d\n\n", poimes, point);
								che = 0;
							}
							else if(strcmp(com, "n") == 0){
								printf("\n\nPless key to finish\n\n>");
								getch();
								return 0;
							}
							else if(strcmp(com, "change") == 0){
								
								printf("\n\n\nWill you change dificulty?>");
								
								do{
									scanf("%s", com);
									
									if(strcmp(com, "y") == 0){
										printf("%s\n\nYour point is: %d\n", poimes, point);
										che = 2;
									}
									else if(strcmp(com, "n") == 0){
										printf("\n\nContinue?>");
										che = 3;
									}
									else{
										printf("\n\nWill you change difficulty? Y or N>");
										che = 1;
									}
								}while(che == 1);
							}
							else if(strcmp(com, "help") == 0){
								printf("\n\n���Ȃ��̓Q�[���I�[�o�[�ɂȂ�܂���\n\n");
								printf("�R���e�B�j���[����ꍇ��\"y\"��\n�Q�[�����I������ꍇ��\"n\"��\n��Փx��ς���ꍇ��\"change\"\n����͂��ĉ�����\n\n");
								printf("�Ȃ��A���݂̓�Փx�ŃR���e�B�j���[�����ꍇ\n");
								
								if(dif == 0)
									printf("���݂̃|�C���g����500points������܂�\n\n");
								else if(dif == 3)
									printf("���݂̃|�C���g��50points��葽���ƃ|�C���g�������ɂȂ�܂�\n\n");
								else
									printf("�|�C���g���N���A����܂�\n\n");
								
								printf("���̃Q�[���̃w���v���������ꍇ��\n��U�R���e�B�j���[���Ă���Q�[������\n\"help\"�Ɠ��͂��Ă�������\n\n");
								printf("Continue?>");
								che = 3;
							}
							else{
								printf("Continue? Y or N>");
								che = 3;
							}
						}while(che == 3);
					}
					else if(dif == 4){
						if(hid < hi){
							hid = hi;
						}
						
						point = point - 300;
						
						printf("\nYou Lose...\n\n\n-300\n\nYour point is: %d\n\n", point);
						
						che = 0;
					}
					
					ed = 0;
					
					break;
			}
			
			if(help != 1 && ed == 0){
			
				a = ad;
				ed = 4;
			}
			
		}
		
		if(che == 2 && point != 0){
		
			printf("\n\nWill you clear your point?>");
			
			do{
				scanf("%s", com);
				
				if(strcmp(com, "y") == 0){
					point = 0;
					printf("\n\nYour point has been cleared.");
					che = 2;
				}
				else if(strcmp(com, "n") == 0){
					che = 2;
				}
				else{
					printf("\n\nWill you clear your point? Y or N>");
					che = 3;
				}
			}while(che == 3);
			
			printf("\n\n\n��Փx�� \"Hard\", \"Nomal\", \"Easy\", \"Beginner\", \"Endless\"\n�̒�����I�����Ă�������");
		}
		
	}while(che == 2);
}