#include "cheats.h"
#include <stdbool.h>
#include <stdio.h>
#include "hid.h"
#include "values.h"
#include <string.h>
#include "ID.h"
#define YOKAI 62
#define ADDRESS 0x08758FA0
#define SPEED 0.5

/**妖怪をボス妖怪にするかなり雑なソースww(失敗作)**/
void	Boss(void){
	static unsigned int tmp = 0;
	static u32 Y_offset = ADDRESS;
	static u32 backup[YOKAI] = {0};
	if(is_pressed(Y+DU)){
		for(int i = 0;i < YOKAI;i++){
			if(tmp != 1){
				backup[i] = READU32(Y_offset);
			}
			WRITEU32(Y_offset,BOSS[i]);
			Y_offset += 0xCC;
		}
		tmp = 1;
		Y_offset = ADDRESS;
	}
	if(is_pressed(Y+DD)){
		for(int i = 0;i < YOKAI;i++){
			WRITEU32(Y_offset,backup[i]);
			Y_offset += 0xCC;
		}
		Y_offset = ADDRESS;
	}
}

void	movement(void){
	if(is_pressed(Y)){
		if(is_pressed(DR)){
			WRITEFLOAT_P(0x0891D200,SPEED);
		}
		if(is_pressed(DL)){
			WRITEFLOAT_M(0x0891D200,SPEED);
		}
		if(is_pressed(DD)){
			WRITEFLOAT_P(0x0891D208,SPEED);
		}
		if(is_pressed(DU)){
			WRITEFLOAT_M(0x0891D208,SPEED);
		}
	}
}

void	Create_BinFile(void){
	FILE *cf;
	cf = fopen("test.bin","wb");
	fclose(cf);
}