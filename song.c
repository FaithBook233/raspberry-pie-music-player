/*
	**欢迎使用！！！ 
*/ 
#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>

//蜂鸣器GPIO接口 
#define BuzPin    0	

//3个八度的C大调频率 
#define  LC  262
#define  LD  294
#define  LE  330
#define  LF  349
#define  LG  392
#define  LA  440
#define  LB  494

#define  MC  523
#define  MD  587
#define  ME  662
#define  MF  698
#define  MG  784
#define  MA  880
#define  MB  988

#define  HC  1046
#define  HD  1175
#define  HE  1318
#define  HF  1397
#define  HG  1568
#define  HA  1760
#define  HB  1926

#define MA_  932

//一拍的长度 
#define BEAT 110

//音调 
int song[] = {
	MD,MD,MC,MD,MF,MF,MG,
	MD,MD,MC,MD,MC,LA,MC,
	MD,MD,MC,MD,MF,MG,MA,
	MA,MG,MF,MD,
	MD,MD,MC,MD,MF,MF,MG,
	MD,MD,MC,MD,MC,MC,LA,
	MD,MD,MC,MD,MF,MG,MA,
	MA,MG,MA,MG,MF,MD,
	MF,ME,MD,MC,MC,MC,MD,LA,LG,LA,
	LA,MC,MD,MG,ME,MF,ME,MC,MD,
	MF,ME,MD,MC,MC,MC,MD,LA,LG,LA,
	LA,MC,MD,MD,MD,MF,MG,ME,
	MD,MF,MG,MG,MG,MA,MA,
	MA,HC,HD,MG,MF,MA,
	MD,MF,MG,MG,MG,MA,MA,
	MA,MA_,MA,MG,MF,MF,
	MD,MF,MG,MG,MG,MA,MA,
	MA,HC,HD,MG,MF,MA,
	MD,MF,MA_,MA,MG,MF,MG,MF,MA,HC,HD,
	MG,MA,MD,MC,MD,MC,
	MG,MA,MD,MC,MD,MC,
	MG,MA,MD,MC,MD,MC,
	MF,ME,MD,MC,
	MG,MA,MD,MC,MD,MC,
	MG,MA,MD,MC,MD,MC,
	MF,MG,MA,HF,HE,HF,HE,HC,MA,
	MG,MA,MD,MC,MD,MC,
	MG,MA,MD,MC,MD,MC,
	MG,MA,MD,MC,MD,MC,
	MF,ME,MD,MC,
	MD,MC,MD,MF,MD,MF,MG,MF,MG,MA,MG,MF,ME,MD,MD,MC,MD,
};

//音调对应的拍子长度 
int beat[] = {
	4,3,1,2,2,2,2,
	4,3,1,2,2,2,2,
	4,3,1,2,2,2,2,
	4,4,4,4,
	4,3,1,2,2,2,2,
	4,3,1,2,2,2,2,
	4,3,1,2,2,2,2,
	4,2,1,1,4,4,
	4,4,4,4,2,1,1,2,2,8,
	2,2,4,4,4,4,2,2,8,
	4,4,4,4,2,1,1,2,2,4,
	2,2,2,4,2,4,4,12,
	2,2,3,1,2,2,6,2,2,2,2,2,4,
	2,2,3,1,2,2,6,2,2,2,2,2,4,
	2,2,3,1,2,2,6,2,2,2,2,2,4,
	2,2,4,4,4,4,2,2,2,2,8,
	2,2,1,1,1,1,
	2,2,1,1,1,1,
	2,2,1,1,1,1,
	2,2,2,2,
	2,2,1,1,1,1,
	2,2,1,1,1,1,
	2,2,2,2,2,1,1,2,2,
	2,2,1,1,1,1,
	2,2,1,1,1,1,
	2,2,1,1,1,1,
	2,2,2,2,
	2,1,1,2,1,1,2,1,1,1,1,1,1,3,3,2,8,
};

int main(void)
{
	int i, j; 
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}

	if(softToneCreate(BuzPin) == -1){
		printf("setup softTone failed !");
		return 1; 
	}
	//循环播放歌曲 
	while(1){
		printf("Senbon Zakura is being played!!!\n");
		for(i=0;i<sizeof(song)/4;i++){
			softToneWrite(BuzPin, song[i]);	
			delay(beat[i] * BEAT);
		}
		delay(8*BEAT);
	}
	
	return 0;
}

