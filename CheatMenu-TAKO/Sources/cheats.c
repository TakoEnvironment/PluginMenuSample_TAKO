#define ADDRESS 0x08758FA0
#define SPEED 0.5
#define SET_ADDERSS_FOR_MAHACK 0x03C00000

/**妖怪をボス妖怪にするかなり雑なソースww(失敗作)**/
void	Boss(void){
	static unsigned int tmp = 0;
	static u32 Y_offset = ADDRESS;
	static u32 backup[YOKAI] = {0};
	if(is_pressed(Y+DU)){
		for(int i = 0;i < YOKAI;i++){
			if(tmp != 1){
				backup[i] = READU32(Y_offset + SET_ADDERSS_FOR_MAHACK);
			}
			WRITEU32(Y_offset + SET_ADDERSS_FOR_MAHACK,BOSS[i]);
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
			WRITEFLOAT_P(0x0891D200 + SET_ADDERSS_FOR_MAHACK,SPEED);
		}
		if(is_pressed(DL)){
			WRITEFLOAT_M(0x0891D200 + SET_ADDERSS_FOR_MAHACK,SPEED);
		}
		if(is_pressed(DD)){
			WRITEFLOAT_P(0x0891D208 + SET_ADDERSS_FOR_MAHACK,SPEED);
		}
		if(is_pressed(DU)){
			WRITEFLOAT_M(0x0891D208 + SET_ADDERSS_FOR_MAHACK,SPEED);
		}
	}
}

void	Create_BinFile(void){
	//これは意味がないソースです
	FILE *cf;
	cf = fopen("test.bin","wb");
	fclose(cf);
}
